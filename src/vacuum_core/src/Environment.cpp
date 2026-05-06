#include "vacuum_core/environment/Environment.h"
#include "vacuum_core/util/Exception.h"

#include <opencv2/imgcodecs.hpp>

namespace vacuum_core::environment {

Environment::Environment(const Config& config)
    : resolution_(config.resolution)
{
    if (resolution_ <= 0.0) {
        throw util::MapLoadException("Environment: resolution must be positive");
    }

    map_ = cv::imread(config.map_filename, cv::IMREAD_GRAYSCALE);

    if (map_.empty()) {
        throw util::MapLoadException("Environment: failed to load map: " + config.map_filename);
    }
}

bool Environment::isOccupied(double x, double y) const
{
    const int px = static_cast<int>(x / resolution_);
    const int py_world = static_cast<int>(y / resolution_);  // row from bottom
    const int py = map_.rows - 1 - py_world;                 // convert to PNG row (from top)

    if (px < 0 || py_world < 0 || px >= map_.cols || py_world >= map_.rows) {
        return true;
    }

    return map_.at<unsigned char>(py, px) == 0;
}

double Environment::getWidth() const
{
    return static_cast<double>(map_.cols) * resolution_;
}

double Environment::getHeight() const
{
    return static_cast<double>(map_.rows) * resolution_;
}

} // namespace vacuum_core::environment
