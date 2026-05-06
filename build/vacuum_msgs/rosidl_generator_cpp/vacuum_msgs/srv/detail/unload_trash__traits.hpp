// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vacuum_msgs:srv/UnloadTrash.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__TRAITS_HPP_
#define VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vacuum_msgs/srv/detail/unload_trash__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'robot_pos'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace vacuum_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnloadTrash_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: robot_pos
  {
    out << "robot_pos: ";
    to_flow_style_yaml(msg.robot_pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UnloadTrash_Request & msg,
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

  // member: robot_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_pos:\n";
    to_block_style_yaml(msg.robot_pos, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UnloadTrash_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vacuum_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vacuum_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vacuum_msgs::srv::UnloadTrash_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::srv::UnloadTrash_Request & msg)
{
  return vacuum_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::srv::UnloadTrash_Request>()
{
  return "vacuum_msgs::srv::UnloadTrash_Request";
}

template<>
inline const char * name<vacuum_msgs::srv::UnloadTrash_Request>()
{
  return "vacuum_msgs/srv/UnloadTrash_Request";
}

template<>
struct has_fixed_size<vacuum_msgs::srv::UnloadTrash_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vacuum_msgs::srv::UnloadTrash_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vacuum_msgs::srv::UnloadTrash_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace vacuum_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UnloadTrash_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: score_gained
  {
    out << "score_gained: ";
    rosidl_generator_traits::value_to_yaml(msg.score_gained, out);
    out << ", ";
  }

  // member: capacity_used
  {
    out << "capacity_used: ";
    rosidl_generator_traits::value_to_yaml(msg.capacity_used, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UnloadTrash_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: score_gained
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score_gained: ";
    rosidl_generator_traits::value_to_yaml(msg.score_gained, out);
    out << "\n";
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UnloadTrash_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vacuum_msgs

namespace rosidl_generator_traits
{

[[deprecated("use vacuum_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vacuum_msgs::srv::UnloadTrash_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::srv::UnloadTrash_Response & msg)
{
  return vacuum_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::srv::UnloadTrash_Response>()
{
  return "vacuum_msgs::srv::UnloadTrash_Response";
}

template<>
inline const char * name<vacuum_msgs::srv::UnloadTrash_Response>()
{
  return "vacuum_msgs/srv/UnloadTrash_Response";
}

template<>
struct has_fixed_size<vacuum_msgs::srv::UnloadTrash_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vacuum_msgs::srv::UnloadTrash_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vacuum_msgs::srv::UnloadTrash_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vacuum_msgs::srv::UnloadTrash>()
{
  return "vacuum_msgs::srv::UnloadTrash";
}

template<>
inline const char * name<vacuum_msgs::srv::UnloadTrash>()
{
  return "vacuum_msgs/srv/UnloadTrash";
}

template<>
struct has_fixed_size<vacuum_msgs::srv::UnloadTrash>
  : std::integral_constant<
    bool,
    has_fixed_size<vacuum_msgs::srv::UnloadTrash_Request>::value &&
    has_fixed_size<vacuum_msgs::srv::UnloadTrash_Response>::value
  >
{
};

template<>
struct has_bounded_size<vacuum_msgs::srv::UnloadTrash>
  : std::integral_constant<
    bool,
    has_bounded_size<vacuum_msgs::srv::UnloadTrash_Request>::value &&
    has_bounded_size<vacuum_msgs::srv::UnloadTrash_Response>::value
  >
{
};

template<>
struct is_service<vacuum_msgs::srv::UnloadTrash>
  : std::true_type
{
};

template<>
struct is_service_request<vacuum_msgs::srv::UnloadTrash_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vacuum_msgs::srv::UnloadTrash_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__TRAITS_HPP_
