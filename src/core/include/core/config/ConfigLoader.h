#pragma once

#include <string>

#include <yaml-cpp/yaml.h>

#include "core/config/GameConfig.h"
#include "core/world/WorldObject.h"

namespace core::config {

class ConfigLoader {
public:
    // Parses a YAML file into a GameConfig struct.
    // Throws util::ConfigParseException on any parsing/validation error.
    static GameConfig loadFromFile(const std::string& path);
    static GameConfig loadFromString(const std::string& yaml);

private:
    template <typename T>
    static T required(const YAML::Node& node, const std::string& key);

    template <typename T>
    static T optional(const YAML::Node& node, const std::string& key, const T& fallback);

    static world::Color parseColor(const YAML::Node& node, world::Color fallback);
    static GameConfig parseNode(const YAML::Node& root);
};

} // namespace core::config
