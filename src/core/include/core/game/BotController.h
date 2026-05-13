#pragma once

#include <cstdint>
#include <optional>
#include <vector>

#include "core/types/Geometry.h"

namespace core::game {

// Stateless heuristic controller used by the Duel mode's ghost bot.
// Picks the nearest target (trash or station when full) and produces a simple
// heading-aligned velocity command. The bot is allowed to pass through
// obstacles, so no path-planning logic is needed here.
class BotController {
public:
    static geometry::Twist computeCommand(
        const geometry::RobotState& state,
        const std::optional<geometry::Point2d>& target,
        double max_linear,
        double max_angular);

    static std::optional<geometry::Point2d> pickTarget(
        const geometry::RobotState& state,
        const std::vector<geometry::Point2d>& trash_positions,
        const std::optional<geometry::Point2d>& station,
        uint32_t capacity_used,
        uint32_t capacity_max);

private:
    static double wrapAngle(double a);
};

} // namespace core::game
