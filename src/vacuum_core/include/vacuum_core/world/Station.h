#pragma once

#include <cmath>

#include "vacuum_core/world/WorldObject.h"

namespace vacuum_core::world {

class Station : public WorldObject {
public:
    Station(uint32_t id, geometry::Point2d pos, double radius)
        : WorldObject(id, pos), radius_(radius) {}

    double radius() const { return radius_; }

    std::string kind() const override { return "station"; }
    Color color() const override { return {0.1f, 0.8f, 0.1f, 1.0f}; }

    bool intersects(const geometry::Point2d& p, double r) const override {
        const double dx = p.x - position_.x;
        const double dy = p.y - position_.y;
        return std::sqrt(dx * dx + dy * dy) < (r + radius_);
    }

private:
    double radius_{0.0};
};

} // namespace vacuum_core::world
