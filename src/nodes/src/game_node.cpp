#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_set>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

#include <opencv2/core.hpp>

#include <core/config/ConfigLoader.h>
#include <core/environment/Environment.h>
#include <core/game/GameLogic.h>

#include <msgs/msg/game_state.hpp>
#include <msgs/msg/robot_status.hpp>
#include <msgs/srv/collect_trash.hpp>
#include <msgs/srv/unload_trash.hpp>
#include <msgs/srv/reset_game.hpp>

using namespace std::chrono_literals;

namespace vacuum_game {

class GameNode : public rclcpp::Node {
public:
    GameNode() : rclcpp::Node("game_node") {
        config_path_ = declare_parameter<std::string>("config_file", "");
        if (config_path_.empty()) {
            throw std::runtime_error("game_node: 'config_file' parameter is required");
        }

        cfg_ = core::config::ConfigLoader::loadFromFile(config_path_);
        core::environment::Config ec{cfg_.map_path, cfg_.resolution};
        env_ = std::make_shared<core::environment::Environment>(ec);
        logic_ = std::make_unique<core::game::GameLogic>(cfg_, env_);

        for (const auto& r : cfg_.robots) {
            logic_->registerRobot(r.robot_id);
        }

        logic_->start();
        logic_->spawnInitialTrash(cfg_.initial_trash_count);

        rclcpp::QoS latched_qos(1);
        latched_qos.transient_local();

        map_pub_ = create_publisher<nav_msgs::msg::OccupancyGrid>("/map", latched_qos);
        game_state_pub_ = create_publisher<msgs::msg::GameState>("/game_state", 10);
        trash_markers_pub_ = create_publisher<visualization_msgs::msg::MarkerArray>(
            "/trash_markers", 10);
        obstacle_markers_pub_ = create_publisher<visualization_msgs::msg::MarkerArray>(
            "/obstacle_markers", latched_qos);
        station_marker_pub_ = create_publisher<visualization_msgs::msg::Marker>(
            "/station_marker", latched_qos);

        collect_srv_ = create_service<msgs::srv::CollectTrash>(
            "/collect_trash",
            [this](const std::shared_ptr<msgs::srv::CollectTrash::Request> req,
                   std::shared_ptr<msgs::srv::CollectTrash::Response> resp) {
                core::geometry::Point2d pos{req->robot_pos.x, req->robot_pos.y};
                auto r = logic_->tryCollect(req->robot_id, pos, req->robot_radius);
                resp->success = r.success;
                resp->capacity_used = r.capacity_used;
                resp->capacity_max = r.capacity_max;
                if (r.success) {
                    resp->collected.id = r.trash_id;
                    resp->collected.type = r.type;
                    resp->collected.position.x = r.position.x;
                    resp->collected.position.y = r.position.y;
                    resp->collected.radius = r.radius;
                    resp->collected.color.r = r.color[0];
                    resp->collected.color.g = r.color[1];
                    resp->collected.color.b = r.color[2];
                    resp->collected.color.a = r.color[3];
                    resp->collected.score_value = r.score_value;
                }
            });

        unload_srv_ = create_service<msgs::srv::UnloadTrash>(
            "/unload_trash",
            [this](const std::shared_ptr<msgs::srv::UnloadTrash::Request> req,
                   std::shared_ptr<msgs::srv::UnloadTrash::Response> resp) {
                core::geometry::Point2d pos{req->robot_pos.x, req->robot_pos.y};
                auto r = logic_->tryUnload(req->robot_id, pos);
                resp->success = r.success;
                resp->score_gained = r.score_gained;
                resp->capacity_used = r.capacity_used;
            });

        reset_srv_ = create_service<msgs::srv::ResetGame>(
            "/reset_game",
            [this](const std::shared_ptr<msgs::srv::ResetGame::Request>,
                   std::shared_ptr<msgs::srv::ResetGame::Response> resp) {
                logic_ = std::make_unique<core::game::GameLogic>(cfg_, env_);
                for (const auto& r : cfg_.robots) {
                    logic_->registerRobot(r.robot_id);
                }
                logic_->start();
                logic_->spawnInitialTrash(cfg_.initial_trash_count);
                announced_ = false;
                resp->success = true;
                RCLCPP_INFO(get_logger(), "game reset");
            });

        publish_timer_ = create_wall_timer(100ms, [this]() { publishAll(); });

        tick_timer_ = create_wall_timer(
            std::chrono::duration<double>(0.1),
            [this]() { logic_->tick(0.1); announceWinner(); });

        publishStaticMarkers();
        publishMap();

        RCLCPP_INFO(get_logger(), "game_node started, mode=%s, robots=%zu, trash=%d",
            cfg_.mode.c_str(), cfg_.robots.size(), cfg_.initial_trash_count);
    }

private:
    void publishMap() {
        const auto& m = env_->map();
        nav_msgs::msg::OccupancyGrid grid;
        grid.header.frame_id = "map";
        grid.header.stamp = now();
        grid.info.resolution = cfg_.resolution;
        grid.info.width = m.cols;
        grid.info.height = m.rows;
        grid.info.origin.position.x = 0.0;
        grid.info.origin.position.y = 0.0;
        grid.info.origin.orientation.w = 1.0;
        grid.data.resize(m.cols * m.rows, 0);
        for (int y = 0; y < m.rows; ++y) {
            for (int x = 0; x < m.cols; ++x) {
                const int src_y = m.rows - 1 - y;
                const unsigned char v = m.at<unsigned char>(src_y, x);
                grid.data[y * m.cols + x] = (v == 0) ? 100 : 0;
            }
        }
        map_pub_->publish(grid);
    }

    void publishStaticMarkers() {
        visualization_msgs::msg::MarkerArray arr;
        int id = 0;
        for (const auto& o : cfg_.obstacles) {
            visualization_msgs::msg::Marker m;
            m.header.frame_id = "map";
            m.header.stamp = now();
            m.ns = "obstacles";
            m.id = id++;
            m.action = visualization_msgs::msg::Marker::ADD;
            m.pose.position.x = o.center.x;
            m.pose.position.y = o.center.y;
            m.pose.position.z = 0.25;
            m.pose.orientation.w = 1.0;
            m.color.r = 0.85f; m.color.g = 0.1f; m.color.b = 0.1f; m.color.a = 1.0f;
            if (o.shape == "circle") {
                m.type = visualization_msgs::msg::Marker::CYLINDER;
                m.scale.x = o.radius * 2.0;
                m.scale.y = o.radius * 2.0;
                m.scale.z = 0.5;
            } else {
                m.type = visualization_msgs::msg::Marker::CUBE;
                m.scale.x = o.width;
                m.scale.y = o.height;
                m.scale.z = 0.5;
            }
            arr.markers.push_back(m);
        }
        obstacle_markers_pub_->publish(arr);

        visualization_msgs::msg::Marker sm;
        sm.header.frame_id = "map";
        sm.header.stamp = now();
        sm.ns = "station";
        sm.id = 0;
        sm.type = visualization_msgs::msg::Marker::CYLINDER;
        sm.action = visualization_msgs::msg::Marker::ADD;
        sm.pose.position.x = cfg_.station_pos.x;
        sm.pose.position.y = cfg_.station_pos.y;
        sm.pose.position.z = 0.05;
        sm.pose.orientation.w = 1.0;
        sm.scale.x = cfg_.station_radius * 2.0;
        sm.scale.y = cfg_.station_radius * 2.0;
        sm.scale.z = 0.1;
        sm.color.r = 0.1f; sm.color.g = 0.8f; sm.color.b = 0.1f; sm.color.a = 1.0f;
        station_marker_pub_->publish(sm);
    }

    void publishAll() {
        const auto snapshot = logic_->snapshot();
        publishTrashMarkers(snapshot);
        publishGameState(snapshot);
    }

    void publishTrashMarkers(const core::game::GameSnapshot& snap) {
        visualization_msgs::msg::MarkerArray arr;
        std::unordered_set<uint32_t> current;

        for (const auto& t : snap.active_trash) {
            current.insert(t.id);
            visualization_msgs::msg::Marker m;
            m.header.frame_id = "map";
            m.header.stamp = now();
            m.ns = "trash";
            m.id = static_cast<int>(t.id);
            m.type = visualization_msgs::msg::Marker::SPHERE;
            m.action = visualization_msgs::msg::Marker::ADD;
            m.pose.position.x = t.position.x;
            m.pose.position.y = t.position.y;
            m.pose.position.z = 0.1;
            m.pose.orientation.w = 1.0;
            m.scale.x = t.radius * 2.0;
            m.scale.y = t.radius * 2.0;
            m.scale.z = t.radius * 2.0;
            m.color.r = t.color[0];
            m.color.g = t.color[1];
            m.color.b = t.color[2];
            m.color.a = t.color[3];
            arr.markers.push_back(m);
        }

        for (uint32_t prev : last_trash_ids_) {
            if (current.count(prev)) continue;
            visualization_msgs::msg::Marker del;
            del.header.frame_id = "map";
            del.header.stamp = now();
            del.ns = "trash";
            del.id = static_cast<int>(prev);
            del.action = visualization_msgs::msg::Marker::DELETE;
            arr.markers.push_back(del);
        }

        if (!arr.markers.empty()) {
            trash_markers_pub_->publish(arr);
        }
        last_trash_ids_ = std::move(current);
    }

    void publishGameState(const core::game::GameSnapshot& snap) {
        msgs::msg::GameState msg;
        msg.mode = cfg_.mode;
        msg.phase = snap.phase;
        msg.elapsed_seconds = static_cast<float>(snap.elapsed_seconds);
        msg.winner = snap.winner;
        msg.score = snap.score;

        for (const auto& [id, used] : snap.capacity_used) {
            msgs::msg::RobotStatus rs;
            rs.robot_id = id;
            rs.capacity_used = used;
            rs.capacity_max = cfg_.max_capacity;
            msg.robots.push_back(rs);
        }

        for (const auto& c : snap.collected) {
            msgs::msg::TrashCount tc;
            tc.type = c.type;
            tc.count = c.count;
            msg.collected.push_back(tc);
        }

        for (const auto& t : snap.active_trash) {
            msgs::msg::TrashItem ti;
            ti.id = t.id;
            ti.type = t.type;
            ti.position.x = t.position.x;
            ti.position.y = t.position.y;
            ti.radius = t.radius;
            ti.color.r = t.color[0];
            ti.color.g = t.color[1];
            ti.color.b = t.color[2];
            ti.color.a = t.color[3];
            ti.score_value = t.score_value;
            msg.active_trash.push_back(ti);
        }

        game_state_pub_->publish(msg);
    }

    void announceWinner() {
        if (!logic_->isFinished()) return;
        if (announced_) return;
        announced_ = true;
        const auto snap = logic_->snapshot();
        RCLCPP_INFO(get_logger(), "=== GAME OVER === winner: %s  (elapsed %.1fs)",
                    snap.winner.empty() ? "(none)" : snap.winner.c_str(),
                    snap.elapsed_seconds);
    }

    std::string config_path_;
    core::config::GameConfig cfg_;
    std::shared_ptr<core::environment::Environment> env_;
    std::unique_ptr<core::game::GameLogic> logic_;
    bool announced_{false};

    rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr map_pub_;
    rclcpp::Publisher<msgs::msg::GameState>::SharedPtr game_state_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr trash_markers_pub_;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr obstacle_markers_pub_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr station_marker_pub_;

    rclcpp::Service<msgs::srv::CollectTrash>::SharedPtr collect_srv_;
    rclcpp::Service<msgs::srv::UnloadTrash>::SharedPtr unload_srv_;
    rclcpp::Service<msgs::srv::ResetGame>::SharedPtr reset_srv_;

    rclcpp::TimerBase::SharedPtr publish_timer_;
    rclcpp::TimerBase::SharedPtr tick_timer_;
    std::unordered_set<uint32_t> last_trash_ids_;
};

} // namespace vacuum_game

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    try {
        rclcpp::spin(std::make_shared<vacuum_game::GameNode>());
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("game_node"), "fatal: %s", e.what());
        rclcpp::shutdown();
        return 1;
    }
    rclcpp::shutdown();
    return 0;
}
