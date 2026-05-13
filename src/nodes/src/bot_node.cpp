#include <chrono>
#include <memory>
#include <optional>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

#include <core/game/BotController.h>
#include <msgs/msg/game_state.hpp>
#include <msgs/msg/robot_status.hpp>

using namespace std::chrono_literals;

namespace vacuum_game {

class BotNode : public rclcpp::Node {
public:
    BotNode() : rclcpp::Node("bot_node") {
        robot_id_ = declare_parameter<std::string>("robot_id", "bot");
        station_x_ = declare_parameter<double>("station_x", 0.0);
        station_y_ = declare_parameter<double>("station_y", 0.0);
        max_linear_ = declare_parameter<double>("max_linear", 1.5);
        max_angular_ = declare_parameter<double>("max_angular", 2.0);
        capacity_max_ = declare_parameter<int>("capacity_max", 5);

        const std::string ns = "/" + robot_id_;
        cmd_pub_ = create_publisher<geometry_msgs::msg::Twist>(ns + "/cmd_vel", 10);

        status_sub_ = create_subscription<msgs::msg::RobotStatus>(
            ns + "/status", 10,
            [this](const msgs::msg::RobotStatus::SharedPtr msg) {
                state_.x = msg->pose.x;
                state_.y = msg->pose.y;
                state_.theta = msg->pose.theta;
                capacity_used_ = msg->capacity_used;
                have_state_ = true;
            });

        game_sub_ = create_subscription<msgs::msg::GameState>(
            "/game_state", 10,
            [this](const msgs::msg::GameState::SharedPtr msg) {
                trash_positions_.clear();
                trash_positions_.reserve(msg->active_trash.size());
                for (const auto& t : msg->active_trash) {
                    trash_positions_.push_back({t.position.x, t.position.y});
                }
                game_phase_ = msg->phase;
            });

        timer_ = create_wall_timer(50ms, [this]() { tick(); });
        RCLCPP_INFO(get_logger(), "bot_node '%s' started", robot_id_.c_str());
    }

private:
    void tick() {
        if (!have_state_) return;
        if (game_phase_ != "RUNNING") {
            geometry_msgs::msg::Twist stop;
            cmd_pub_->publish(stop);
            return;
        }

        std::optional<core::geometry::Point2d> station{{station_x_, station_y_}};
        auto target = core::game::BotController::pickTarget(
            state_, trash_positions_, station, capacity_used_, capacity_max_);
        auto cmd = core::game::BotController::computeCommand(
            state_, target, max_linear_, max_angular_);

        geometry_msgs::msg::Twist msg;
        msg.linear.x = cmd.linear;
        msg.angular.z = cmd.angular;
        cmd_pub_->publish(msg);
    }

    std::string robot_id_;
    double station_x_{0.0}, station_y_{0.0};
    double max_linear_{1.5}, max_angular_{2.0};
    int capacity_max_{5};
    uint32_t capacity_used_{0};
    bool have_state_{false};
    core::geometry::RobotState state_{};
    std::vector<core::geometry::Point2d> trash_positions_;
    std::string game_phase_{"RUNNING"};

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub_;
    rclcpp::Subscription<msgs::msg::RobotStatus>::SharedPtr status_sub_;
    rclcpp::Subscription<msgs::msg::GameState>::SharedPtr game_sub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

} // namespace vacuum_game

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<vacuum_game::BotNode>());
    rclcpp::shutdown();
    return 0;
}
