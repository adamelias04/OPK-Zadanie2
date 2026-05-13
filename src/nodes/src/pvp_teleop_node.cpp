#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

using namespace std::chrono_literals;

namespace vacuum_game {

// Controls two robots from one terminal.
// WASD = player,  IJKL = bot,  Space = stop both,  q = quit
class PvpTeleopNode : public rclcpp::Node {
public:
    PvpTeleopNode() : rclcpp::Node("pvp_teleop_node") {
        p1_id_ = declare_parameter<std::string>("player1_id", "player");
        p2_id_ = declare_parameter<std::string>("player2_id", "bot");
        linear_step_  = declare_parameter<double>("linear_step",  0.5);
        angular_step_ = declare_parameter<double>("angular_step", 0.5);
        max_linear_   = declare_parameter<double>("max_linear",   3.0);
        max_angular_  = declare_parameter<double>("max_angular",  2.5);

        p1_pub_ = create_publisher<geometry_msgs::msg::Twist>("/" + p1_id_ + "/cmd_vel", 10);
        p2_pub_ = create_publisher<geometry_msgs::msg::Twist>("/" + p2_id_ + "/cmd_vel", 10);

        setupTerminal();
        timer_ = create_wall_timer(50ms, [this]() { tick(); });

        RCLCPP_INFO(get_logger(),
            "pvp_teleop — Player1(%s): WASD  Player2(%s): sipky  Space=stop both  q=quit",
            p1_id_.c_str(), p2_id_.c_str());
    }

    ~PvpTeleopNode() override { restoreTerminal(); }

private:
    void setupTerminal() {
        tcgetattr(STDIN_FILENO, &orig_termios_);
        struct termios raw = orig_termios_;
        raw.c_lflag &= ~(ICANON | ECHO);
        raw.c_cc[VMIN]  = 0;
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
        std::vector<char> buf;
        while (read(STDIN_FILENO, &c, 1) > 0) {
            buf.push_back(c);
        }
        for (size_t i = 0; i < buf.size(); ++i) {
            if (buf[i] == '\033' && i + 2 < buf.size() && buf[i + 1] == '[') {
                handleArrow(buf[i + 2]);
                i += 2;
            } else {
                handleKey(buf[i]);
            }
        }
        publish(p1_pub_, p1_lin_, p1_ang_);
        publish(p2_pub_, p2_lin_, p2_ang_);
    }

    // Arrow keys (ESC [ A/B/C/D) — Player 2
    void handleArrow(char code) {
        switch (code) {
        case 'A': p2_lin_ = std::min(max_linear_,   p2_lin_ + linear_step_);  break; // Up
        case 'B': p2_lin_ = std::max(-max_linear_,  p2_lin_ - linear_step_);  break; // Down
        case 'D': p2_ang_ = std::min(max_angular_,  p2_ang_ + angular_step_); break; // Left
        case 'C': p2_ang_ = std::max(-max_angular_, p2_ang_ - angular_step_); break; // Right
        default: break;
        }
    }

    void handleKey(char c) {
        switch (c) {
        // Player 1 — WASD
        case 'w': p1_lin_ = std::min(max_linear_,   p1_lin_ + linear_step_);  break;
        case 's': p1_lin_ = std::max(-max_linear_,  p1_lin_ - linear_step_);  break;
        case 'a': p1_ang_ = std::min(max_angular_,  p1_ang_ + angular_step_); break;
        case 'd': p1_ang_ = std::max(-max_angular_, p1_ang_ - angular_step_); break;
        case 'x': p1_lin_ = 0.0; break;
        case 'z': p1_ang_ = 0.0; break;
        // Global
        case ' ':
            p1_lin_ = 0.0; p1_ang_ = 0.0;
            p2_lin_ = 0.0; p2_ang_ = 0.0;
            break;
        case 'q': rclcpp::shutdown(); break;
        default: break;
        }
    }

    void publish(rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr& pub,
                 double lin, double ang) {
        geometry_msgs::msg::Twist msg;
        msg.linear.x  = lin;
        msg.angular.z = ang;
        pub->publish(msg);
    }

    std::string p1_id_, p2_id_;
    double linear_step_{0.5}, angular_step_{0.5};
    double max_linear_{3.0}, max_angular_{2.5};
    double p1_lin_{0.0}, p1_ang_{0.0};
    double p2_lin_{0.0}, p2_ang_{0.0};
    struct termios orig_termios_{};
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr p1_pub_, p2_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

} // namespace vacuum_game

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<vacuum_game::PvpTeleopNode>());
    rclcpp::shutdown();
    return 0;
}
