#pragma once

#include <memory>
#include <vector>

#include "vacuum_core/types/Geometry.h"
#include "vacuum_core/environment/Environment.h"

namespace vacuum_core::lidar {

struct Config {
    double max_range{5.0};
    int beam_count{181};
    double first_ray_angle{-1.57079632679};
    double last_ray_angle{1.57079632679};
};

struct ScanResult {
    std::vector<double> ranges;
    std::vector<geometry::Point2d> hits;
};

class Lidar {
public:
    Lidar(const Config& config, std::shared_ptr<environment::Environment> env);

    ScanResult scan(const geometry::RobotState& state) const;

    const Config& config() const { return config_; }

private:
    Config config_;
    std::shared_ptr<environment::Environment> env_;
};

} // namespace vacuum_core::lidar
