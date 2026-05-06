#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

#include <chrono>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

using namespace std::chrono_literals;

namespace vacuum_game {

class TeleopNode : public rclcpp::Node {
public:
    TeleopNode() : rclcpp::Node("teleop_node") {
        robot_id_ = declare_parameter<std::string>("robot_id", "player");
        linear_step_ = declare_parameter<double>("linear_step", 0.5);
        angular_step_ = declare_parameter<double>("angular_step", 0.5);
        max_linear_ = declare_parameter<double>("max_linear", 3.0);
        max_angular_ = declare_parameter<double>("max_angular", 2.5);

        const std::string ns = "/" + robot_id_;
        cmd_pub_ = create_publisher<geometry_msgs::msg::Twist>(ns + "/cmd_vel", 10);

        setupTerminal();

        timer_ = create_wall_timer(50ms, [this]() { tick(); });

        RCLCPP_INFO(get_logger(),
            "teleop '%s' — WASD to move, x/c to zero linear/angular, space to stop, q to quit",
            robot_id_.c_str());
    }

    ~TeleopNode() override { restoreTerminal(); }

private:
    void setupTerminal() {
        tcgetattr(STDIN_FILENO, &orig_termios_);
        struct termios raw = orig_termios_;
        raw.c_lflag &= ~(ICANON | ECHO);
        raw.c_cc[VMIN] = 0;
        raw.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
        int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    }

    void restoreTerminal() {
        tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios_);
    }

    void tick() {
        char c;
        while (read(STDIN_FILENO, &c, 1) > 0) {
            handleKey(c);
        }
        publishCmd();
    }

    void handleKey(char c) {
        switch (c) {
        case 'w': linear_  = std::min(max_linear_,  linear_  + linear_step_);  break;
        case 's': linear_  = std::max(-max_linear_, linear_  - linear_step_);  break;
        case 'a': angular_ = std::min(max_angular_, angular_ + angular_step_); break;
        case 'd': angular_ = std::max(-max_angular_, angular_ - angular_step_); break;
        case 'x': linear_ = 0.0; break;
        case 'c': angular_ = 0.0; break;
        case ' ': linear_ = 0.0; angular_ = 0.0; break;
        case 'q': rclcpp::shutdown(); break;
        default: break;
        }
    }

    void publishCmd() {
        geometry_msgs::msg::Twist msg;
        msg.linear.x = linear_;
        msg.angular.z = angular_;
        cmd_pub_->publish(msg);
    }

    std::string robot_id_;
    double linear_step_{0.5}, angular_step_{0.5};
    double max_linear_{3.0}, max_angular_{2.5};
    double linear_{0.0}, angular_{0.0};
    struct termios orig_termios_ {};
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

} // namespace vacuum_game

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<vacuum_game::TeleopNode>());
    rclcpp::shutdown();
    return 0;
}
