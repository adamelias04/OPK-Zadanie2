#pragma once

#include <string>

#include "vacuum_core/config/GameConfig.h"

namespace vacuum_core::config {

class ConfigLoader {
public:
    // Parses a YAML file into a GameConfig struct.
    // Throws util::ConfigParseException on any parsing/validation error.
    static GameConfig loadFromFile(const std::string& path);
    static GameConfig loadFromString(const std::string& yaml);
};

} // namespace vacuum_core::config
