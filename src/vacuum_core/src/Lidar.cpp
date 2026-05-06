#include "vacuum_core/lidar/Lidar.h"
#include "vacuum_core/util/Exception.h"

#include <cmath>

namespace vacuum_core::lidar {

Lidar::Lidar(const Config& config, std::shared_ptr<environment::Environment> env)
    : config_(config), env_(std::move(env))
{
    if (!env_) {
        throw util::VacuumException("Lidar: environment pointer is null");
    }
    if (config_.max_range <= 0.0) {
        throw util::VacuumException("Lidar: max_range must be positive");
    }
    if (config_.beam_count <= 0) {
        throw util::VacuumException("Lidar: beam_count must be positive");
    }
}

ScanResult Lidar::scan(const geometry::RobotState& state) const
{
    ScanResult result;
    result.ranges.reserve(static_cast<std::size_t>(config_.beam_count));
    result.hits.reserve(static_cast<std::size_t>(config_.beam_count));

    const double angle_step =
        (config_.beam_count == 1)
            ? 0.0
            : (config_.last_ray_angle - config_.first_ray_angle) /
                  static_cast<double>(config_.beam_count - 1);

    const double ray_step = 0.01;

    for (int i = 0; i < config_.beam_count; ++i) {
        const double ray_angle = state.theta + config_.first_ray_angle + i * angle_step;
        const double cos_a = std::cos(ray_angle);
        const double sin_a = std::sin(ray_angle);

        bool hit_found = false;

        for (double r = 0.0; r <= config_.max_range; r += ray_step) {
            const double x = state.x + r * cos_a;
            const double y = state.y + r * sin_a;

            if (env_->isOccupied(x, y)) {
                result.hits.push_back({x, y});
                result.ranges.push_back(r);
                hit_found = true;
                break;
            }
        }

        if (!hit_found) {
            const double x = state.x + config_.max_range * cos_a;
            const double y = state.y + config_.max_range * sin_a;
            result.hits.push_back({x, y});
            result.ranges.push_back(config_.max_range);
        }
    }

    return result;
}

} // namespace vacuum_core::lidar
