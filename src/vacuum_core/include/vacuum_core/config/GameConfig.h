#pragma once

#include <string>
#include <vector>

#include "vacuum_core/types/Geometry.h"
#include "vacuum_core/world/TrashFactory.h"

namespace vacuum_core::config {

struct ObstacleSpec {
    std::string shape; // "circle" or "rectangle"
    geometry::Point2d center;
    double radius{0.0};        // for circle
    double width{0.0};         // for rectangle
    double height{0.0};        // for rectangle
};

struct RobotSpec {
    std::string robot_id;
    double start_x{1.0};
    double start_y{1.0};
    double start_theta{0.0};
    bool ghost{false};
    bool bot{false};
};

struct GameConfig {
    std::string map_path;
    double resolution{0.05};

    double robot_radius{0.3};
    uint32_t max_capacity{5};

    double trash_radius_min{0.1};
    double trash_radius_max{0.2};
    std::vector<world::TrashTypeSpec> trash_types;

    std::string mode{"duel"};
    double spawn_interval_sec{2.0};
    int initial_trash_count{10};

    double station_radius{0.5};
    geometry::Point2d station_pos{};

    std::vector<ObstacleSpec> obstacles;
    std::vector<RobotSpec> robots;

    // Duel settings
    int duel_goal_count{3};       // wins after N unloads
    double duel_time_limit_sec{180.0};
    double bot_max_linear{1.0};
    double bot_max_angular{1.5};

    // Robot dynamics
    double accel_linear{5.0};
    double accel_angular{3.0};
    double emergency_accel_linear{10.0};
    double emergency_accel_angular{6.0};
    double command_duration{1.0};
    int simulation_period_ms{30};
};

} // namespace vacuum_core::config
