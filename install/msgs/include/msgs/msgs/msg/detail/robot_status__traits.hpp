// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define MSGS__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: capacity_used
  {
    out << "capacity_used: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity_used, out);
    out << ", ";
  }

  // member: capacity_max
  {
    out << "capacity_max: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity_max, out);
    out << ", ";
  }

  // member: in_collision
  {
    out << "in_collision: ";
    rosidl_generator_traits::value_to_yaml(msg.in_collision, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }

  // member: capacity_used
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "capacity_used: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity_used, out);
    out << "\n";
  }

  // member: capacity_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "capacity_max: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity_max, out);
    out << "\n";
  }

  // member: in_collision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "in_collision: ";
    rosidl_generator_traits::value_to_yaml(msg.in_collision, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace msgs

namespace rosidl_generator_traits
{

[[deprecated("use msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const msgs::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs::msg::RobotStatus & msg)
{
  return msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs::msg::RobotStatus>()
{
  return "msgs::msg::RobotStatus";
}

template<>
inline const char * name<msgs::msg::RobotStatus>()
{
  return "msgs/msg/RobotStatus";
}

template<>
struct has_fixed_size<msgs::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<msgs::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<msgs::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
