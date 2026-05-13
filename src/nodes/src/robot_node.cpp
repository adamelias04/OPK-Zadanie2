#include <chrono>
#include <cmath>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <nav_msgs/msg/path.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <std_msgs/msg/color_rgba.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

#include <core/environment/Environment.h>
#include <core/robot/Robot.h>
#include <core/world/Obstacle.h>
#include <core/config/ConfigLoader.h>
#include <core/util/Exception.h>

#include <msgs/msg/robot_status.hpp>
#include <msgs/msg/game_state.hpp>
#include <msgs/srv/collect_trash.hpp>
#include <msgs/srv/unload_trash.hpp>

using namespace std::chrono_literals;

namespace vacuum_robot {

class RobotNode : public rclcpp::Node {
public:
    RobotNode() : rclcpp::Node("robot_node") {
        declareParams();
        loadConfig();
        setupCollisionEnvironment();
        setupRobot();
        setupTopicsAndTimers();
        initMarkerColor();
        RCLCPP_INFO(get_logger(),
            "robot_node '%s' started at (%.2f, %.2f), ghost=%s",
            robot_id_.c_str(), start_x_, start_y_, ghost_ ? "true" : "false");
    }
     
private:
    void declareParams() {
        config_path_ = declare_parameter<std::string>("config_file", "");
        robot_id_ = declare_parameter<std::string>("robot_id", "player");
        start_x_ = declare_parameter<double>("start_x", 1.0);
        start_y_ = declare_parameter<double>("start_y", 1.0);
        start_theta_ = declare_parameter<double>("start_theta", 0.0);
        ghost_ = declare_parameter<bool>("ghost", false);
        publish_period_ms_ = declare_parameter<int>("publish_period_ms", 33);
    }

    void loadConfig() {
        if (config_path_.empty()) {
            throw std::runtime_error("robot_node: 'config_file' parameter is required");
        }
        cfg_ = core::config::ConfigLoader::loadFromFile(config_path_);
    }

    void setupCollisionEnvironment() {
        core::environment::Config env_cfg{
            cfg_.map_path, cfg_.resolution
        };
        env_ = std::make_shared<core::environment::Environment>(env_cfg);

        uint32_t id = 1;
        for (const auto& o : cfg_.obstacles) {
            if (o.shape == "circle") {
                obstacles_.push_back(std::make_shared<core::world::CircleObstacle>(
                    id++, o.center, o.radius));
            } else if (o.shape == "rectangle") {
                obstacles_.push_back(std::make_shared<core::world::RectangleObstacle>(
                    id++, o.center, o.width, o.height));
            }
        }
    }

    void setupRobot() {
        core::robot::Config rcfg;
        rcfg.accelerations.linear = cfg_.accel_linear;
        rcfg.accelerations.angular = cfg_.accel_angular;
        rcfg.emergency_decelerations.linear = cfg_.emergency_accel_linear;
        rcfg.emergency_decelerations.angular = cfg_.emergency_accel_angular;
        rcfg.command_duration = cfg_.command_duration;
        rcfg.simulation_period_ms = cfg_.simulation_period_ms;
        rcfg.start_x = start_x_;
        rcfg.start_y = start_y_;
        rcfg.start_theta = start_theta_;

        auto env_ptr = env_;
        auto obstacles = obstacles_;
        const double robot_radius = cfg_.robot_radius;
        const bool ghost = ghost_;

        core::robot::Robot::CollisionCb cb = nullptr;
        if (!ghost) {
            cb = [env_ptr, obstacles, robot_radius]
                 (core::geometry::RobotState s) -> bool {
                if (env_ptr->isOccupied(s.x, s.y)) return true;
                for (const auto& o : obstacles) {
                    if (o->intersects({s.x, s.y}, robot_radius)) return true;
                }
                return false;
            };
        }

        robot_ = std::make_unique<core::robot::Robot>(rcfg, cb, true);
    }

    void setupTopicsAndTimers() {
        rclcpp::QoS qos(10);

        const std::string ns = "/" + robot_id_;
        cmd_sub_ = create_subscription<geometry_msgs::msg::Twist>(
            ns + "/cmd_vel", qos,
            [this](const geometry_msgs::msg::Twist::SharedPtr msg) {
                core::geometry::Twist t{msg->linear.x, msg->angular.z};
                robot_->setVelocity(t);
            });

        status_pub_ = create_publisher<msgs::msg::RobotStatus>(ns + "/status", qos);
        path_pub_ = create_publisher<nav_msgs::msg::Path>(ns + "/path", qos);
        marker_pub_ = create_publisher<visualization_msgs::msg::MarkerArray>(
            ns + "/robot_marker", qos);

        game_state_sub_ = create_subscription<msgs::msg::GameState>(
            "/game_state", qos,
            [this](const msgs::msg::GameState::SharedPtr msg) {
                latest_game_state_ = *msg;
                have_game_state_ = true;
            });

        collect_client_ = create_client<msgs::srv::CollectTrash>("/collect_trash");
        unload_client_ = create_client<msgs::srv::UnloadTrash>("/unload_trash");

        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

        path_msg_.header.frame_id = "map";

        timer_ = create_wall_timer(
            std::chrono::milliseconds(publish_period_ms_),
            [this]() { publishState(); });

        interaction_timer_ = create_wall_timer(
            std::chrono::milliseconds(150),
            [this]() { tryInteractions(); });
    }

    void tryInteractions() {
        if (!have_game_state_) return;
        if (call_in_flight_) return;

        const auto state = robot_->getState();

        if (last_capacity_used_ > 0) {
            const double dx = state.x - cfg_.station_pos.x;
            const double dy = state.y - cfg_.station_pos.y;
            if (std::sqrt(dx * dx + dy * dy) < cfg_.station_radius + cfg_.robot_radius) {
                callUnload(state);
                return;
            }
        }

        if (last_capacity_used_ >= cfg_.max_capacity) return;
        for (const auto& t : latest_game_state_.active_trash) {
            const double dx = state.x - t.position.x;
            const double dy = state.y - t.position.y;
            if (std::sqrt(dx * dx + dy * dy) < cfg_.robot_radius + t.radius) {
                callCollect(state);
                return;
            }
        }
    }

    void callCollect(const core::geometry::RobotState& state) {
        if (!collect_client_->service_is_ready()) return;
        auto req = std::make_shared<msgs::srv::CollectTrash::Request>();
        req->robot_id = robot_id_;
        req->robot_pos.x = state.x;
        req->robot_pos.y = state.y;
        req->robot_radius = cfg_.robot_radius;
        call_in_flight_ = true;
        collect_client_->async_send_request(req,
            [this](rclcpp::Client<msgs::srv::CollectTrash>::SharedFuture f) {
                auto resp = f.get();
                last_capacity_used_ = resp->capacity_used;
                if (resp->success) {
                    RCLCPP_INFO(get_logger(),
                        "[%s] collected '%s' (capacity %u/%u)",
                        robot_id_.c_str(), resp->collected.type.c_str(),
                        resp->capacity_used, resp->capacity_max);
                }
                call_in_flight_ = false;
            });
    }

    void callUnload(const core::geometry::RobotState& state) {
        if (!unload_client_->service_is_ready()) return;
        auto req = std::make_shared<msgs::srv::UnloadTrash::Request>();
        req->robot_id = robot_id_;
        req->robot_pos.x = state.x;
        req->robot_pos.y = state.y;
        call_in_flight_ = true;
        unload_client_->async_send_request(req,
            [this](rclcpp::Client<msgs::srv::UnloadTrash>::SharedFuture f) {
                auto resp = f.get();
                last_capacity_used_ = resp->capacity_used;
                if (resp->success) {
                    RCLCPP_INFO(get_logger(),
                        "[%s] unloaded, +%d points",
                        robot_id_.c_str(), resp->score_gained);
                }
                call_in_flight_ = false;
            });
    }

    void initMarkerColor() {
        marker_color_.a = 1.0f;
        if (robot_id_ == "player") {
            marker_color_.r = 0.2f; marker_color_.g = 0.5f; marker_color_.b = 1.0f;
        } else if (robot_id_ == "bot") {
            marker_color_.r = 1.0f; marker_color_.g = 0.3f; marker_color_.b = 1.0f;
        } else {
            marker_color_.r = marker_color_.g = marker_color_.b = 1.0f;
        }
    }

    void publishRobotMarker(const core::geometry::RobotState& state,
                            const rclcpp::Time& now) {
        visualization_msgs::msg::MarkerArray arr;

        // telo
        visualization_msgs::msg::Marker body;
        body.header.frame_id = "map";
        body.header.stamp = now;
        body.ns = robot_id_;
        body.id = 0;
        body.type = visualization_msgs::msg::Marker::CYLINDER;
        body.action = visualization_msgs::msg::Marker::ADD;
        body.pose.position.x = state.x;
        body.pose.position.y = state.y;
        body.pose.position.z = 0.12;
        body.pose.orientation.w = 1.0;
        body.scale.x = cfg_.robot_radius * 2.0;
        body.scale.y = cfg_.robot_radius * 2.0;
        body.scale.z = 0.24;
        body.color = marker_color_;
        arr.markers.push_back(body);

        // sipka
        visualization_msgs::msg::Marker arrow;
        arrow.header = body.header;
        arrow.ns = robot_id_;
        arrow.id = 1;
        arrow.type = visualization_msgs::msg::Marker::ARROW;
        arrow.action = visualization_msgs::msg::Marker::ADD;
        geometry_msgs::msg::Point p0, p1;
        p0.x = state.x; p0.y = state.y; p0.z = 0.25;
        p1.x = state.x + std::cos(state.theta) * cfg_.robot_radius * 1.8;
        p1.y = state.y + std::sin(state.theta) * cfg_.robot_radius * 1.8;
        p1.z = 0.25;
        arrow.points = {p0, p1};
        arrow.scale.x = 0.06;   
        arrow.scale.y = 0.12;   
        arrow.scale.z = 0.10;   
        arrow.color.r = 1.0f; arrow.color.g = 1.0f; arrow.color.b = 1.0f;
        arrow.color.a = 1.0f;
        arr.markers.push_back(arrow);

        marker_pub_->publish(arr);
    }

    void publishState() {
        const auto state = robot_->getState();
        const bool collided = robot_->isInCollision();

        const auto now = this->now();

        msgs::msg::RobotStatus status;
        status.robot_id = robot_id_;
        status.pose.x = state.x;
        status.pose.y = state.y;
        status.pose.theta = state.theta;
        status.velocity.linear.x = state.velocity.linear;
        status.velocity.angular.z = state.velocity.angular;
        status.capacity_used = last_capacity_used_;
        status.capacity_max = cfg_.max_capacity;
        status.in_collision = collided;
        status_pub_->publish(status);

        geometry_msgs::msg::PoseStamped ps;
        ps.header.stamp = now;
        ps.header.frame_id = "map";
        ps.pose.position.x = state.x;
        ps.pose.position.y = state.y;
        tf2::Quaternion q;
        q.setRPY(0, 0, state.theta);
        ps.pose.orientation.x = q.x();
        ps.pose.orientation.y = q.y();
        ps.pose.orientation.z = q.z();
        ps.pose.orientation.w = q.w();

        path_msg_.header.stamp = now;
        if (path_msg_.poses.empty() ||
            std::hypot(
                state.x - path_msg_.poses.back().pose.position.x,
                state.y - path_msg_.poses.back().pose.position.y) > 0.1)
        {
            path_msg_.poses.push_back(ps);
            if (path_msg_.poses.size() > 2000) {
                path_msg_.poses.erase(path_msg_.poses.begin());
            }
            path_pub_->publish(path_msg_);
        }
        publishRobotMarker(state, now);

        geometry_msgs::msg::TransformStamped tf;
        tf.header.stamp = now;
        tf.header.frame_id = "map";
        tf.child_frame_id = robot_id_ + "_base_link";
        tf.transform.translation.x = state.x;
        tf.transform.translation.y = state.y;
        tf.transform.rotation.x = q.x();
        tf.transform.rotation.y = q.y();
        tf.transform.rotation.z = q.z();
        tf.transform.rotation.w = q.w();
        tf_broadcaster_->sendTransform(tf);
    }

    std::string config_path_;
    std::string robot_id_;
    std_msgs::msg::ColorRGBA marker_color_{};
    double start_x_{1.0}, start_y_{1.0}, start_theta_{0.0};
    bool ghost_{false};
    int publish_period_ms_{33};
    uint32_t last_capacity_used_{0};
    bool call_in_flight_{false};
    bool have_game_state_{false};

    core::config::GameConfig cfg_;
    std::shared_ptr<core::environment::Environment> env_;
    std::vector<std::shared_ptr<core::world::Obstacle>> obstacles_;
    std::unique_ptr<core::robot::Robot> robot_;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
    rclcpp::Subscription<msgs::msg::GameState>::SharedPtr game_state_sub_;
    rclcpp::Publisher<msgs::msg::RobotStatus>::SharedPtr status_pub_;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr marker_pub_;
    rclcpp::Client<msgs::srv::CollectTrash>::SharedPtr collect_client_;
    rclcpp::Client<msgs::srv::UnloadTrash>::SharedPtr unload_client_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr interaction_timer_;
    nav_msgs::msg::Path path_msg_;
    msgs::msg::GameState latest_game_state_;
};

} // namespace vacuum_robot

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    try {
        rclcpp::spin(std::make_shared<vacuum_robot::RobotNode>());
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("robot_node"), "fatal: %s", e.what());
        rclcpp::shutdown();
        return 1;
    }
    rclcpp::shutdown();
    return 0;
}
