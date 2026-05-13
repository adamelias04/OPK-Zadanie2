#include <gtest/gtest.h>

#include "core/world/WorldManager.h"

using namespace core;

TEST(WorldManager, ObstacleIntersection) {
    world::WorldManager m;
    uint32_t id = m.nextId();
    m.addObstacle(std::make_unique<world::CircleObstacle>(
        id, geometry::Point2d{5.0, 5.0}, 1.0));

    EXPECT_TRUE(m.isObstacleAt({5.5, 5.0}, 0.1));
    EXPECT_FALSE(m.isObstacleAt({10.0, 10.0}, 0.1));
}

TEST(WorldManager, RectangleObstacleInside) {
    world::WorldManager m;
    m.addObstacle(std::make_unique<world::RectangleObstacle>(
        m.nextId(), geometry::Point2d{0.0, 0.0}, 4.0, 2.0));

    EXPECT_TRUE(m.isObstacleAt({1.0, 0.0}, 0.1));
    EXPECT_TRUE(m.isObstacleAt({-1.5, 0.9}, 0.1));
    EXPECT_FALSE(m.isObstacleAt({3.0, 0.0}, 0.1));
}

TEST(WorldManager, PickupTrash) {
    world::WorldManager m;
    m.addTrash(std::make_unique<world::PaperTrash>(
        m.nextId(), geometry::Point2d{2.0, 2.0}, 0.2));

    EXPECT_EQ(m.trashCount(), 1u);

    auto v = m.pickupNearest({2.1, 2.0}, 0.3);
    ASSERT_TRUE(v.has_value());
    EXPECT_EQ(v->type, "paper");
    EXPECT_EQ(m.trashCount(), 0u);

    auto miss = m.pickupNearest({10.0, 10.0}, 0.3);
    EXPECT_FALSE(miss.has_value());
}

TEST(WorldManager, StationIntersection) {
    world::WorldManager m;
    m.setStation(std::make_unique<world::Station>(
        m.nextId(), geometry::Point2d{1.0, 1.0}, 0.5));

    EXPECT_TRUE(m.isAtStation({1.3, 1.0}, 0.3));
    EXPECT_FALSE(m.isAtStation({5.0, 5.0}, 0.3));
}
