#include "core/robot/Robot.h"

#include <algorithm>
#include <cmath>
#include <thread>

namespace core::robot {

namespace {
double moveTowards(double current, double target, double max_delta)
{
    if (current < target) {
        return std::min(current + max_delta, target);
    }
    return std::max(current - max_delta, target);
}
} // namespace

Robot::Robot(const Config& config, const CollisionCb& collision_cb, bool start_thread)
    : config_(config), collision_cb_(collision_cb)
{
    state_.x = config_.start_x;
    state_.y = config_.start_y;
    state_.theta = config_.start_theta;
    state_.velocity.linear = 0.0;
    state_.velocity.angular = 0.0;

    target_velocity_.linear = 0.0;
    target_velocity_.angular = 0.0;

    in_collision_ = false;
    last_command_time_ = std::chrono::steady_clock::now();

    running_ = false;
    if (start_thread) {
        running_ = true;
        worker_ = std::thread(&Robot::simulationLoop, this);
    }
}

Robot::~Robot()
{
    running_ = false;
    if (worker_.joinable()) {
        worker_.join();
    }
}

void Robot::setVelocity(const geometry::Twist& velocity)
{
    std::lock_guard<std::mutex> lock(mutex_);
    target_velocity_ = velocity;
    last_command_time_ = std::chrono::steady_clock::now();
}

geometry::RobotState Robot::getState() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return state_;
}

bool Robot::isInCollision() const
{
    std::lock_guard<std::mutex> lock(mutex_);
    return in_collision_;
}

void Robot::setCollisionCallback(const CollisionCb& cb)
{
    std::lock_guard<std::mutex> lock(mutex_);
    collision_cb_ = cb;
}

void Robot::update(const geometry::Twist& velocity, double dt)
{
    state_.theta += velocity.angular * dt;
    state_.x += velocity.linear * std::cos(state_.theta) * dt;
    state_.y += velocity.linear * std::sin(state_.theta) * dt;
    state_.velocity = velocity;
}

void Robot::simulationLoop()
{
    const double dt = static_cast<double>(config_.simulation_period_ms) / 1000.0;

    while (running_) {
        {
            std::lock_guard<std::mutex> lock(mutex_);

            const auto now = std::chrono::steady_clock::now();
            const double command_age =
                std::chrono::duration<double>(now - last_command_time_).count();

            geometry::Twist desired_velocity = target_velocity_;

            if (command_age > config_.command_duration) {
                desired_velocity.linear = 0.0;
                desired_velocity.angular = 0.0;
            }

            const bool emergency_stop =
                (desired_velocity.linear == 0.0 && state_.velocity.linear != 0.0) ||
                (desired_velocity.angular == 0.0 && state_.velocity.angular != 0.0);

            const double linear_acc =
                emergency_stop ? config_.emergency_decelerations.linear
                               : config_.accelerations.linear;

            const double angular_acc =
                emergency_stop ? config_.emergency_decelerations.angular
                               : config_.accelerations.angular;

            geometry::Twist next_velocity;
            next_velocity.linear = moveTowards(
                state_.velocity.linear,
                desired_velocity.linear,
                linear_acc * dt
            );
            next_velocity.angular = moveTowards(
                state_.velocity.angular,
                desired_velocity.angular,
                angular_acc * dt
            );

            geometry::RobotState old_state = state_;

            update(next_velocity, dt);

            if (collision_cb_ && collision_cb_(state_)) {
                in_collision_ = true;
                state_ = old_state;
                state_.velocity.linear = 0.0;
                state_.velocity.angular = 0.0;
                target_velocity_.linear = 0.0;
                target_velocity_.angular = 0.0;
            } else {
                in_collision_ = false;
            }
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(config_.simulation_period_ms)
        );
    }
}

} // namespace core::robot
