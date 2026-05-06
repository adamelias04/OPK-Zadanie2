#include <gtest/gtest.h>

#include "vacuum_core/game/BotController.h"

using namespace vacuum_core;

TEST(BotController, PicksNearestTrash) {
    geometry::RobotState s;
    s.x = 0; s.y = 0;
    std::vector<geometry::Point2d> trash{{10, 0}, {3, 0}, {-5, 0}};
    auto target = game::BotController::pickTarget(s, trash, std::nullopt, 0, 5);
    ASSERT_TRUE(target.has_value());
    EXPECT_EQ(target->x, 3);
}

TEST(BotController, FullCapacityGoesToStation) {
    geometry::RobotState s;
    std::vector<geometry::Point2d> trash{{3, 0}};
    geometry::Point2d station{10, 10};
    auto target = game::BotController::pickTarget(s, trash, station, 5, 5);
    ASSERT_TRUE(target.has_value());
    EXPECT_EQ(target->x, 10);
    EXPECT_EQ(target->y, 10);
}

TEST(BotController, NoTrashNoStationNoTarget) {
    geometry::RobotState s;
    auto target = game::BotController::pickTarget(s, {}, std::nullopt, 0, 5);
    EXPECT_FALSE(target.has_value());
}

TEST(BotController, ClampsVelocityLimits) {
    geometry::RobotState s;
    s.x = 0; s.y = 0; s.theta = 0;
    geometry::Point2d target{100, 0};
    auto cmd = game::BotController::computeCommand(s, target, 1.5, 2.0);
    EXPECT_LE(cmd.linear, 1.5 + 1e-9);
    EXPECT_GE(cmd.linear, 0.0);
    EXPECT_LE(std::abs(cmd.angular), 2.0 + 1e-9);
}

TEST(BotController, TurnsTowardTargetBehind) {
    geometry::RobotState s;
    s.x = 0; s.y = 0; s.theta = 0.0;  // facing +x
    geometry::Point2d target{-5, 0};    // target behind
    auto cmd = game::BotController::computeCommand(s, target, 1.5, 2.0);
    EXPECT_GT(std::abs(cmd.angular), 0.5);
}
