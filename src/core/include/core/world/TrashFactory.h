#pragma once

#include <functional>
#include <memory>
#include <random>
#include <string>
#include <vector>

#include "core/world/Collectible.h"

namespace core::world {

struct TrashTypeSpec {
    std::string type;
    double weight{1.0};
    Color color{1.0f, 1.0f, 0.0f, 1.0f};
};

// Factory pattern: single entry point for constructing Collectible objects.
// Hides the concrete trash subclass behind a type string, lets callers extend
// the game with new trash variants without touching game logic.
class TrashFactory {
public:
    using OccupancyCheck = std::function<bool(const geometry::Point2d&, double)>;

    TrashFactory(std::vector<TrashTypeSpec> types,
                 double min_radius,
                 double max_radius,
                 unsigned seed = 0);

    std::unique_ptr<Collectible> create(const std::string& type,
                                        uint32_t id,
                                        const geometry::Point2d& pos,
                                        double radius) const;

    std::unique_ptr<Collectible> createRandom(uint32_t id,
                                              double world_width,
                                              double world_height,
                                              const OccupancyCheck& blocked,
                                              int max_attempts = 200);

    const std::vector<TrashTypeSpec>& types() const { return types_; }

private:
    std::vector<TrashTypeSpec> types_;
    double min_radius_;
    double max_radius_;
    mutable std::mt19937 rng_;
    std::discrete_distribution<int> type_dist_;
};

} // namespace core::world
