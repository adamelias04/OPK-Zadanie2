// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vacuum_msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__TRAITS_HPP_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vacuum_msgs/msg/detail/trash_count__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vacuum_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrashCount & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: count
  {
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrashCount & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "count: ";
    rosidl_generator_traits::value_to_yaml(msg.count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrashCount & msg, bool use_flow_style = false)
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
  const vacuum_msgs::msg::TrashCount & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::msg::TrashCount & msg)
{
  return vacuum_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::msg::TrashCount>()
{
  return "vacuum_msgs::msg::TrashCount";
}

template<>
inline const char * name<vacuum_msgs::msg::TrashCount>()
{
  return "vacuum_msgs/msg/TrashCount";
}

template<>
struct has_fixed_size<vacuum_msgs::msg::TrashCount>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vacuum_msgs::msg::TrashCount>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vacuum_msgs::msg::TrashCount>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__TRAITS_HPP_
