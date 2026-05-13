#pragma once

#include <array>
#include <cstdint>
#include <string>

#include "core/types/Geometry.h"

namespace core::world {

using Color = std::array<float, 4>;

class WorldObject {
public:
    virtual ~WorldObject() = default;

    uint32_t id() const { return id_; }
    const geometry::Point2d& position() const { return position_; }

    virtual std::string kind() const = 0;
    virtual bool intersects(const geometry::Point2d& p, double r) const = 0;
    virtual Color color() const = 0;

protected:
    WorldObject(uint32_t id, geometry::Point2d pos)
        : id_(id), position_(pos) {}

    uint32_t id_{0};
    geometry::Point2d position_{};
};

} // namespace core::world
