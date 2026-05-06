#pragma once

#include <algorithm>
#include <cmath>

#include "vacuum_core/world/WorldObject.h"

namespace vacuum_core::world {

class Obstacle : public WorldObject {
public:
    std::string kind() const override { return "obstacle"; }
    Color color() const override { return {0.85f, 0.1f, 0.1f, 1.0f}; }

protected:
    Obstacle(uint32_t id, geometry::Point2d pos)
        : WorldObject(id, pos) {}
};

class CircleObstacle : public Obstacle {
public:
    CircleObstacle(uint32_t id, geometry::Point2d center, double radius)
        : Obstacle(id, center), radius_(radius) {}

    double radius() const { return radius_; }

    bool intersects(const geometry::Point2d& p, double r) const override {
        const double dx = p.x - position_.x;
        const double dy = p.y - position_.y;
        return std::sqrt(dx * dx + dy * dy) < (r + radius_);
    }

private:
    double radius_{0.0};
};

class RectangleObstacle : public Obstacle {
public:
    RectangleObstacle(uint32_t id, geometry::Point2d center,
                      double width, double height)
        : Obstacle(id, center), width_(width), height_(height) {}

    double width() const { return width_; }
    double height() const { return height_; }

    bool intersects(const geometry::Point2d& p, double r) const override {
        const double dx = std::max(0.0, std::abs(p.x - position_.x) - width_ / 2.0);
        const double dy = std::max(0.0, std::abs(p.y - position_.y) - height_ / 2.0);
        return std::sqrt(dx * dx + dy * dy) < r;
    }

private:
    double width_{0.0};
    double height_{0.0};
};

} // namespace vacuum_core::world
