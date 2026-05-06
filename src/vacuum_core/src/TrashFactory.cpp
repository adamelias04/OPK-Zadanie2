#include "vacuum_core/world/TrashFactory.h"
#include "vacuum_core/util/Exception.h"

#include <chrono>

namespace vacuum_core::world {

TrashFactory::TrashFactory(std::vector<TrashTypeSpec> types,
                           double min_radius,
                           double max_radius,
                           unsigned seed)
    : types_(std::move(types)),
      min_radius_(min_radius),
      max_radius_(max_radius)
{
    if (types_.empty()) {
        throw util::ConfigParseException("TrashFactory: at least one trash type required");
    }
    if (min_radius_ <= 0.0 || max_radius_ < min_radius_) {
        throw util::ConfigParseException("TrashFactory: invalid radius range");
    }

    if (seed == 0) {
        seed = static_cast<unsigned>(
            std::chrono::steady_clock::now().time_since_epoch().count());
    }
    rng_.seed(seed);

    std::vector<double> weights;
    weights.reserve(types_.size());
    for (const auto& t : types_) {
        weights.push_back(std::max(0.0, t.weight));
    }
    type_dist_ = std::discrete_distribution<int>(weights.begin(), weights.end());
}

std::unique_ptr<Collectible> TrashFactory::create(const std::string& type,
                                                  uint32_t id,
                                                  const geometry::Point2d& pos,
                                                  double radius) const
{
    Color color{1.0f, 1.0f, 0.0f, 1.0f};
    for (const auto& t : types_) {
        if (t.type == type) {
            color = t.color;
            break;
        }
    }

    if (type == "paper") {
        return std::make_unique<PaperTrash>(id, pos, radius, color);
    }
    if (type == "plastic") {
        return std::make_unique<PlasticTrash>(id, pos, radius, color);
    }
    if (type == "glass") {
        return std::make_unique<GlassTrash>(id, pos, radius, color);
    }
    throw util::ConfigParseException("TrashFactory: unknown trash type '" + type + "'");
}

std::unique_ptr<Collectible> TrashFactory::createRandom(uint32_t id,
                                                        double world_width,
                                                        double world_height,
                                                        const OccupancyCheck& blocked,
                                                        int max_attempts)
{
    std::uniform_real_distribution<double> x_dist(0.5, world_width - 0.5);
    std::uniform_real_distribution<double> y_dist(0.5, world_height - 0.5);
    std::uniform_real_distribution<double> r_dist(min_radius_, max_radius_);

    for (int i = 0; i < max_attempts; ++i) {
        const geometry::Point2d pos{x_dist(rng_), y_dist(rng_)};
        const double radius = r_dist(rng_);
        if (blocked && blocked(pos, radius)) {
            continue;
        }
        const int type_idx = type_dist_(rng_);
        return create(types_[type_idx].type, id, pos, radius);
    }
    return nullptr;
}

} // namespace vacuum_core::world
