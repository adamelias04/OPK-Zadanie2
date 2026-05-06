#include <gtest/gtest.h>

#include "vacuum_core/config/ConfigLoader.h"
#include "vacuum_core/util/Exception.h"

using namespace vacuum_core;

static const char* kValidYaml = R"(
environment:
  map_path: /tmp/map.png
  resolution: 0.05
  station:
    x: 10.0
    y: 5.0
    radius: 0.6
  obstacles:
    - { shape: circle, x: 2.0, y: 3.0, radius: 0.5 }
    - { shape: rectangle, x: 5.0, y: 5.0, width: 1.0, height: 2.0 }

robot:
  radius: 0.35
  max_capacity: 4

trash:
  radius_min: 0.1
  radius_max: 0.2
  types:
    - { type: paper,   weight: 2, color: [1.0, 1.0, 0.0, 1.0] }
    - { type: plastic, weight: 1, color: [0.0, 0.0, 1.0, 1.0] }
    - { type: glass,   weight: 1, color: [0.0, 1.0, 0.5, 1.0] }

game:
  mode: duel
  spawn_interval_sec: 1.5
  initial_trash_count: 8
  duel_goal_count: 3
  duel_time_limit_sec: 120

robots:
  - { id: player, start_x: 1.0, start_y: 1.0, ghost: false, bot: false }
  - { id: bot,    start_x: 2.0, start_y: 2.0, ghost: true,  bot: true }
)";

TEST(ConfigLoader, ParsesValidYaml) {
    auto cfg = config::ConfigLoader::loadFromString(kValidYaml);
    EXPECT_EQ(cfg.map_path, "/tmp/map.png");
    EXPECT_DOUBLE_EQ(cfg.resolution, 0.05);
    EXPECT_EQ(cfg.station_pos.x, 10.0);
    EXPECT_EQ(cfg.obstacles.size(), 2u);
    EXPECT_EQ(cfg.obstacles[0].shape, "circle");
    EXPECT_EQ(cfg.obstacles[1].shape, "rectangle");
    EXPECT_EQ(cfg.robot_radius, 0.35);
    EXPECT_EQ(cfg.max_capacity, 4u);
    EXPECT_EQ(cfg.trash_types.size(), 3u);
    EXPECT_EQ(cfg.robots.size(), 2u);
    EXPECT_TRUE(cfg.robots[1].ghost);
    EXPECT_TRUE(cfg.robots[1].bot);
}

TEST(ConfigLoader, MissingEnvironmentThrows) {
    EXPECT_THROW(
        config::ConfigLoader::loadFromString("robot:\n  radius: 0.3\n"),
        util::ConfigParseException);
}

TEST(ConfigLoader, BadObstacleShapeThrows) {
    std::string yaml = R"(
environment:
  map_path: /tmp/m.png
  resolution: 0.05
  obstacles:
    - { shape: triangle, x: 1.0, y: 1.0, radius: 1 }
trash:
  types:
    - { type: paper }
)";
    EXPECT_THROW(config::ConfigLoader::loadFromString(yaml),
                 util::ConfigParseException);
}

TEST(ConfigLoader, MissingTrashTypesThrows) {
    std::string yaml = R"(
environment:
  map_path: /tmp/m.png
  resolution: 0.05
trash:
  radius_min: 0.1
  radius_max: 0.2
)";
    EXPECT_THROW(config::ConfigLoader::loadFromString(yaml),
                 util::ConfigParseException);
}
