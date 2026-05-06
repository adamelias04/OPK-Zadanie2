#pragma once

#include <string>
#include <opencv2/core.hpp>

namespace vacuum_core::environment {

struct Config {
    std::string map_filename;
    double resolution; // meters per pixel
};

class Environment {
public:
    explicit Environment(const Config& config);

    bool isOccupied(double x, double y) const;
    double getWidth() const;
    double getHeight() const;

    int cols() const { return map_.cols; }
    int rows() const { return map_.rows; }
    double resolution() const { return resolution_; }
    const cv::Mat& map() const { return map_; }

private:
    cv::Mat map_;
    double resolution_{0.0};
};

} // namespace vacuum_core::environment
