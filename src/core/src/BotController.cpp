#include "core/game/BotController.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace core::game {

double BotController::wrapAngle(double a) {
    while (a > M_PI) a -= 2.0 * M_PI;
    while (a < -M_PI) a += 2.0 * M_PI;
    return a;
}

std::optional<geometry::Point2d> BotController::pickTarget(
    const geometry::RobotState& state,
    const std::vector<geometry::Point2d>& trash_positions,
    const std::optional<geometry::Point2d>& station,
    uint32_t capacity_used,
    uint32_t capacity_max)
{
    if (capacity_max > 0 && capacity_used >= capacity_max) {
        return station;
    }
    if (trash_positions.empty()) {
        return station;
    }
    double best_dist = std::numeric_limits<double>::max();
    geometry::Point2d best{};
    for (const auto& p : trash_positions) {
        const double dx = p.x - state.x;
        const double dy = p.y - state.y;
        const double d = dx * dx + dy * dy;
        if (d < best_dist) {
            best_dist = d;
            best = p;
        }
    }
    return best;
}

geometry::Twist BotController::computeCommand(
    const geometry::RobotState& state,
    const std::optional<geometry::Point2d>& target,
    double max_linear,
    double max_angular)
{
    geometry::Twist cmd{};
    if (!target) return cmd;

    const double dx = target->x - state.x;
    const double dy = target->y - state.y;
    const double dist = std::sqrt(dx * dx + dy * dy);
    if (dist < 1e-3) return cmd;

    const double target_heading = std::atan2(dy, dx);
    const double heading_err = wrapAngle(target_heading - state.theta);

    cmd.angular = std::clamp(2.0 * heading_err, -max_angular, max_angular);

    const double alignment = std::max(0.0, std::cos(heading_err));
    cmd.linear = std::clamp(alignment * dist, 0.0, max_linear);
    return cmd;
}

} // namespace core::game
