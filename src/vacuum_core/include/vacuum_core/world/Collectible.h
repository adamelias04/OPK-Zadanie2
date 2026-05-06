#pragma once

#include <cmath>

#include "vacuum_core/world/WorldObject.h"

namespace vacuum_core::world {

class Collectible : public WorldObject {
public:
    double radius() const { return radius_; }
    Color color() const override { return color_; }

    virtual std::string type() const = 0;
    virtual int scoreValue() const = 0;

    std::string kind() const override { return "trash"; }

    bool intersects(const geometry::Point2d& p, double r) const override {
        const double dx = p.x - position_.x;
        const double dy = p.y - position_.y;
        return std::sqrt(dx * dx + dy * dy) < (r + radius_);
    }

protected:
    Collectible(uint32_t id, geometry::Point2d pos, double radius, Color color)
        : WorldObject(id, pos), radius_(radius), color_(color) {}

    double radius_{0.0};
    Color color_{};
};

class PaperTrash : public Collectible {
public:
    PaperTrash(uint32_t id, geometry::Point2d pos, double radius,
               Color color = {1.0f, 1.0f, 0.0f, 1.0f})
        : Collectible(id, pos, radius, color) {}

    std::string type() const override { return "paper"; }
    int scoreValue() const override { return 1; }
};

class PlasticTrash : public Collectible {
public:
    PlasticTrash(uint32_t id, geometry::Point2d pos, double radius,
                 Color color = {0.2f, 0.4f, 1.0f, 1.0f})
        : Collectible(id, pos, radius, color) {}

    std::string type() const override { return "plastic"; }
    int scoreValue() const override { return 2; }
};

class GlassTrash : public Collectible {
public:
    GlassTrash(uint32_t id, geometry::Point2d pos, double radius,
               Color color = {0.2f, 0.9f, 0.4f, 1.0f})
        : Collectible(id, pos, radius, color) {}

    std::string type() const override { return "glass"; }
    int scoreValue() const override { return 3; }
};

} // namespace vacuum_core::world
