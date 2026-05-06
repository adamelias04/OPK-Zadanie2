// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vacuum_msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__TRAITS_HPP_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vacuum_msgs/msg/detail/trash_item__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'color'
#include "std_msgs/msg/detail/color_rgba__traits.hpp"

namespace vacuum_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrashItem & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << ", ";
  }

  // member: color
  {
    out << "color: ";
    to_flow_style_yaml(msg.color, out);
    out << ", ";
  }

  // member: score_value
  {
    out << "score_value: ";
    rosidl_generator_traits::value_to_yaml(msg.score_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrashItem & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }

  // member: color
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "color:\n";
    to_block_style_yaml(msg.color, out, indentation + 2);
  }

  // member: score_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score_value: ";
    rosidl_generator_traits::value_to_yaml(msg.score_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrashItem & msg, bool use_flow_style = false)
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

}  // namespace vacuum_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vacuum_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vacuum_msgs::msg::TrashItem & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::msg::TrashItem & msg)
{
  return vacuum_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::msg::TrashItem>()
{
  return "vacuum_msgs::msg::TrashItem";
}

template<>
inline const char * name<vacuum_msgs::msg::TrashItem>()
{
  return "vacuum_msgs/msg/TrashItem";
}

template<>
struct has_fixed_size<vacuum_msgs::msg::TrashItem>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vacuum_msgs::msg::TrashItem>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vacuum_msgs::msg::TrashItem>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__TRAITS_HPP_
