#pragma once

#include <atomic>
#include <chrono>
#include <functional>
#include <mutex>
#include <thread>

#include "core/types/Geometry.h"

namespace core::robot {

struct Config {
    geometry::Twist accelerations{};
    geometry::Twist emergency_decelerations{};
    double command_duration{1.0};
    int simulation_period_ms{30};
    double start_x{1.0};
    double start_y{1.0};
    double start_theta{0.0};
};

class Robot {
public:
    using CollisionCb = std::function<bool(geometry::RobotState)>;

    Robot(const Config& config,
          const CollisionCb& collision_cb = nullptr,
          bool start_thread = true);
    ~Robot();

    Robot(const Robot&) = delete;
    Robot& operator=(const Robot&) = delete;

    void setVelocity(const geometry::Twist& velocity);
    geometry::RobotState getState() const;
    bool isInCollision() const;

    void setCollisionCallback(const CollisionCb& cb);

protected:
    void update(const geometry::Twist& velocity, double dt);

private:
    void simulationLoop();

    Config config_;
    CollisionCb collision_cb_;

    mutable std::mutex mutex_;
    geometry::RobotState state_{};
    geometry::Twist target_velocity_{};
    bool in_collision_{false};

    std::atomic<bool> running_{false};
    std::thread worker_;
    std::chrono::steady_clock::time_point last_command_time_;
};

} // namespace core::robot
