#include "vacuum_core/config/ConfigLoader.h"
#include "vacuum_core/util/Exception.h"

#include <yaml-cpp/yaml.h>

#include <fstream>
#include <sstream>

namespace vacuum_core::config {

namespace {

template <typename T>
T required(const YAML::Node& node, const std::string& key) {
    if (!node[key]) {
        throw util::ConfigParseException("missing required key: " + key);
    }
    try {
        return node[key].as<T>();
    } catch (const YAML::Exception& e) {
        throw util::ConfigParseException("bad type for key '" + key + "': " + e.what());
    }
}

template <typename T>
T optional(const YAML::Node& node, const std::string& key, const T& fallback) {
    if (!node[key]) return fallback;
    try {
        return node[key].as<T>();
    } catch (const YAML::Exception& e) {
        throw util::ConfigParseException("bad type for key '" + key + "': " + e.what());
    }
}

world::Color parseColor(const YAML::Node& node, world::Color fallback) {
    if (!node || !node.IsSequence() || node.size() < 3) {
        return fallback;
    }
    world::Color c = fallback;
    c[0] = node[0].as<float>();
    c[1] = node[1].as<float>();
    c[2] = node[2].as<float>();
    c[3] = (node.size() >= 4) ? node[3].as<float>() : 1.0f;
    return c;
}

GameConfig parseNode(const YAML::Node& root) {
    if (!root["environment"]) {
        throw util::ConfigParseException("missing 'environment' section");
    }

    GameConfig cfg;
    const auto env = root["environment"];
    cfg.map_path = required<std::string>(env, "map_path");
    cfg.resolution = required<double>(env, "resolution");

    if (env["station"]) {
        const auto st = env["station"];
        cfg.station_pos.x = required<double>(st, "x");
        cfg.station_pos.y = required<double>(st, "y");
        cfg.station_radius = optional<double>(st, "radius", 0.5);
    }

    if (env["obstacles"]) {
        for (const auto& o : env["obstacles"]) {
            ObstacleSpec spec;
            spec.shape = required<std::string>(o, "shape");
            spec.center.x = required<double>(o, "x");
            spec.center.y = required<double>(o, "y");
            if (spec.shape == "circle") {
                spec.radius = required<double>(o, "radius");
            } else if (spec.shape == "rectangle") {
                spec.width = required<double>(o, "width");
                spec.height = required<double>(o, "height");
            } else {
                throw util::ConfigParseException(
                    "obstacle shape must be 'circle' or 'rectangle', got '" + spec.shape + "'");
            }
            cfg.obstacles.push_back(spec);
        }
    }

    if (root["robot"]) {
        const auto r = root["robot"];
        cfg.robot_radius = optional<double>(r, "radius", cfg.robot_radius);
        cfg.max_capacity = optional<uint32_t>(r, "max_capacity", cfg.max_capacity);
        cfg.accel_linear = optional<double>(r, "accel_linear", cfg.accel_linear);
        cfg.accel_angular = optional<double>(r, "accel_angular", cfg.accel_angular);
        cfg.emergency_accel_linear =
            optional<double>(r, "emergency_accel_linear", cfg.emergency_accel_linear);
        cfg.emergency_accel_angular =
            optional<double>(r, "emergency_accel_angular", cfg.emergency_accel_angular);
        cfg.command_duration = optional<double>(r, "command_duration", cfg.command_duration);
        cfg.simulation_period_ms =
            optional<int>(r, "simulation_period_ms", cfg.simulation_period_ms);
    }

    if (root["trash"]) {
        const auto t = root["trash"];
        cfg.trash_radius_min = optional<double>(t, "radius_min", cfg.trash_radius_min);
        cfg.trash_radius_max = optional<double>(t, "radius_max", cfg.trash_radius_max);
        if (t["types"]) {
            for (const auto& typ : t["types"]) {
                world::TrashTypeSpec spec;
                spec.type = required<std::string>(typ, "type");
                spec.weight = optional<double>(typ, "weight", 1.0);
                spec.color = parseColor(typ["color"], {1.0f, 1.0f, 0.0f, 1.0f});
                cfg.trash_types.push_back(spec);
            }
        }
    }
    if (cfg.trash_types.empty()) {
        throw util::ConfigParseException("at least one trash type required under trash.types");
    }

    if (root["game"]) {
        const auto g = root["game"];
        cfg.mode = optional<std::string>(g, "mode", cfg.mode);
        cfg.spawn_interval_sec =
            optional<double>(g, "spawn_interval_sec", cfg.spawn_interval_sec);
        cfg.initial_trash_count =
            optional<int>(g, "initial_trash_count", cfg.initial_trash_count);
        cfg.duel_goal_count = optional<int>(g, "duel_goal_count", cfg.duel_goal_count);
        cfg.duel_time_limit_sec =
            optional<double>(g, "duel_time_limit_sec", cfg.duel_time_limit_sec);
        cfg.bot_max_linear = optional<double>(g, "bot_max_linear", cfg.bot_max_linear);
        cfg.bot_max_angular = optional<double>(g, "bot_max_angular", cfg.bot_max_angular);
    }

    if (root["robots"]) {
        for (const auto& r : root["robots"]) {
            RobotSpec spec;
            spec.robot_id = required<std::string>(r, "id");
            spec.start_x = optional<double>(r, "start_x", 1.0);
            spec.start_y = optional<double>(r, "start_y", 1.0);
            spec.start_theta = optional<double>(r, "start_theta", 0.0);
            spec.ghost = optional<bool>(r, "ghost", false);
            spec.bot = optional<bool>(r, "bot", false);
            cfg.robots.push_back(spec);
        }
    }

    return cfg;
}

} // namespace

GameConfig ConfigLoader::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        throw util::ConfigParseException("cannot open config file: " + path);
    }
    std::stringstream buf;
    buf << in.rdbuf();
    return loadFromString(buf.str());
}

GameConfig ConfigLoader::loadFromString(const std::string& yaml) {
    try {
        YAML::Node root = YAML::Load(yaml);
        return parseNode(root);
    } catch (const util::VacuumException&) {
        throw;
    } catch (const YAML::Exception& e) {
        throw util::ConfigParseException(std::string("YAML error: ") + e.what());
    }
}

} // namespace vacuum_core::config
