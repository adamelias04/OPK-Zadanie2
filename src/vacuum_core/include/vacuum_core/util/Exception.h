#pragma once

#include <stdexcept>
#include <string>

namespace vacuum_core::util {

class VacuumException : public std::runtime_error {
public:
    explicit VacuumException(const std::string& msg) : std::runtime_error(msg) {}
};

class ConfigParseException : public VacuumException {
public:
    explicit ConfigParseException(const std::string& msg)
        : VacuumException("[config] " + msg) {}
};

class MapLoadException : public VacuumException {
public:
    explicit MapLoadException(const std::string& msg)
        : VacuumException("[map] " + msg) {}
};

class CapacityFullException : public VacuumException {
public:
    explicit CapacityFullException(const std::string& robot_id)
        : VacuumException("[capacity] robot '" + robot_id + "' is full") {}
};

} // namespace vacuum_core::util
