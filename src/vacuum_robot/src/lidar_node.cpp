#include <chrono>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

#include <vacuum_core/environment/Environment.h>
#include <vacuum_core/lidar/Lidar.h>
#include <vacuum_core/config/ConfigLoader.h>

#include <vacuum_msgs/msg/robot_status.hpp>

namespace vacuum_robot {

class LidarNode : public rclcpp::Node {
public:
    LidarNode() : rclcpp::Node("lidar_node") {
        config_path_ = declare_parameter<std::string>("config_file", "");
        robot_id_ = declare_parameter<std::string>("robot_id", "player");
        max_range_ = declare_parameter<double>("max_range", 5.0);
        beam_count_ = declare_parameter<int>("beam_count", 181);
        first_angle_ = declare_parameter<double>("first_ray_angle", -M_PI_2);
        last_angle_ = declare_parameter<double>("last_ray_angle", M_PI_2);

        if (config_path_.empty()) {
            throw std::runtime_error("lidar_node: 'config_file' parameter is required");
        }
        auto cfg = vacuum_core::config::ConfigLoader::loadFromFile(config_path_);
        vacuum_core::environment::Config ec{cfg.map_path, cfg.resolution};
        env_ = std::make_shared<vacuum_core::environment::Environment>(ec);

        vacuum_core::lidar::Config lc;
        lc.max_range = max_range_;
        lc.beam_count = beam_count_;
        lc.first_ray_angle = first_angle_;
        lc.last_ray_angle = last_angle_;
        lidar_ = std::make_unique<vacuum_core::lidar::Lidar>(lc, env_);

        const std::string ns = "/" + robot_id_;
        scan_pub_ = create_publisher<sensor_msgs::msg::LaserScan>(ns + "/scan", 10);

        status_sub_ = create_subscription<vacuum_msgs::msg::RobotStatus>(
            ns + "/status", 10,
            [this](const vacuum_msgs::msg::RobotStatus::SharedPtr msg) {
                publishScan(*msg);
            });

        RCLCPP_INFO(get_logger(), "lidar_node '%s' started (beams=%d, range=%.2fm)",
                    robot_id_.c_str(), beam_count_, max_range_);
    }

private:
    void publishScan(const vacuum_msgs::msg::RobotStatus& status) {
        vacuum_core::geometry::RobotState state;
        state.x = status.pose.x;
        state.y = status.pose.y;
        state.theta = status.pose.theta;

        auto result = lidar_->scan(state);

        sensor_msgs::msg::LaserScan msg;
        msg.header.stamp = this->now();
        msg.header.frame_id = robot_id_ + "_base_link";
        msg.angle_min = first_angle_;
        msg.angle_max = last_angle_;
        msg.angle_increment =
            (beam_count_ > 1)
                ? (last_angle_ - first_angle_) / static_cast<double>(beam_count_ - 1)
                : 0.0;
        msg.range_min = 0.0;
        msg.range_max = max_range_;
        msg.ranges.assign(result.ranges.begin(), result.ranges.end());
        scan_pub_->publish(msg);
    }

    std::string config_path_;
    std::string robot_id_;
    double max_range_{5.0};
    int beam_count_{181};
    double first_angle_{-M_PI_2};
    double last_angle_{M_PI_2};

    std::shared_ptr<vacuum_core::environment::Environment> env_;
    std::unique_ptr<vacuum_core::lidar::Lidar> lidar_;
    rclcpp::Subscription<vacuum_msgs::msg::RobotStatus>::SharedPtr status_sub_;
    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr scan_pub_;
};

} // namespace vacuum_robot

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    try {
        rclcpp::spin(std::make_shared<vacuum_robot::LidarNode>());
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("lidar_node"), "fatal: %s", e.what());
        rclcpp::shutdown();
        return 1;
    }
    rclcpp::shutdown();
    return 0;
}
