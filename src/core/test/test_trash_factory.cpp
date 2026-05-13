#include <gtest/gtest.h>

#include "core/world/TrashFactory.h"
#include "core/util/Exception.h"

using namespace core;

TEST(TrashFactory, CreatesByType) {
    world::TrashFactory f({
        {"paper", 1.0, {1,1,0,1}},
        {"plastic", 1.0, {0,0,1,1}},
        {"glass", 1.0, {0,1,0,1}},
    }, 0.1, 0.2);

    auto p = f.create("paper", 1, {0.0, 0.0}, 0.15);
    ASSERT_NE(p, nullptr);
    EXPECT_EQ(p->type(), "paper");
    EXPECT_EQ(p->scoreValue(), 1);
}

TEST(TrashFactory, UnknownTypeThrows) {
    world::TrashFactory f({{"paper", 1.0, {1,1,0,1}}}, 0.1, 0.2);
    EXPECT_THROW(f.create("metal", 1, {0,0}, 0.15),
                 util::ConfigParseException);
}

TEST(TrashFactory, RandomAvoidsBlockedRegion) {
    world::TrashFactory f({{"paper", 1.0, {1,1,0,1}}}, 0.1, 0.2, 42);

    int good = 0;
    for (int i = 0; i < 20; ++i) {
        auto t = f.createRandom(i + 1, 10.0, 10.0,
            [](const geometry::Point2d& p, double) {
                return p.x < 5.0;
            }, 100);
        if (t) {
            EXPECT_GE(t->position().x, 5.0);
            ++good;
        }
    }
    EXPECT_GT(good, 0);
}

TEST(TrashFactory, InvalidRadiusRangeThrows) {
    EXPECT_THROW(
        world::TrashFactory({{"paper", 1.0, {1,1,0,1}}}, -0.1, 0.1),
        util::ConfigParseException);
    EXPECT_THROW(
        world::TrashFactory({{"paper", 1.0, {1,1,0,1}}}, 0.5, 0.1),
        util::ConfigParseException);
}

TEST(TrashFactory, EmptyTypesThrows) {
    EXPECT_THROW(world::TrashFactory({}, 0.1, 0.2),
                 util::ConfigParseException);
}
