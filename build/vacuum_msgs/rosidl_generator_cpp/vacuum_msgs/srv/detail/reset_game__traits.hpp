// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vacuum_msgs:srv/ResetGame.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__RESET_GAME__TRAITS_HPP_
#define VACUUM_MSGS__SRV__DETAIL__RESET_GAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vacuum_msgs/srv/detail/reset_game__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace vacuum_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetGame_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetGame_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetGame_Request & msg, bool use_flow_style = false)
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
  const vacuum_msgs::srv::ResetGame_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::srv::ResetGame_Request & msg)
{
  return vacuum_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::srv::ResetGame_Request>()
{
  return "vacuum_msgs::srv::ResetGame_Request";
}

template<>
inline const char * name<vacuum_msgs::srv::ResetGame_Request>()
{
  return "vacuum_msgs/srv/ResetGame_Request";
}

template<>
struct has_fixed_size<vacuum_msgs::srv::ResetGame_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vacuum_msgs::srv::ResetGame_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vacuum_msgs::srv::ResetGame_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace vacuum_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResetGame_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResetGame_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResetGame_Response & msg, bool use_flow_style = false)
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
  const vacuum_msgs::srv::ResetGame_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::srv::ResetGame_Response & msg)
{
  return vacuum_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::srv::ResetGame_Response>()
{
  return "vacuum_msgs::srv::ResetGame_Response";
}

template<>
inline const char * name<vacuum_msgs::srv::ResetGame_Response>()
{
  return "vacuum_msgs/srv/ResetGame_Response";
}

template<>
struct has_fixed_size<vacuum_msgs::srv::ResetGame_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<vacuum_msgs::srv::ResetGame_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<vacuum_msgs::srv::ResetGame_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vacuum_msgs::srv::ResetGame>()
{
  return "vacuum_msgs::srv::ResetGame";
}

template<>
inline const char * name<vacuum_msgs::srv::ResetGame>()
{
  return "vacuum_msgs/srv/ResetGame";
}

template<>
struct has_fixed_size<vacuum_msgs::srv::ResetGame>
  : std::integral_constant<
    bool,
    has_fixed_size<vacuum_msgs::srv::ResetGame_Request>::value &&
    has_fixed_size<vacuum_msgs::srv::ResetGame_Response>::value
  >
{
};

template<>
struct has_bounded_size<vacuum_msgs::srv::ResetGame>
  : std::integral_constant<
    bool,
    has_bounded_size<vacuum_msgs::srv::ResetGame_Request>::value &&
    has_bounded_size<vacuum_msgs::srv::ResetGame_Response>::value
  >
{
};

template<>
struct is_service<vacuum_msgs::srv::ResetGame>
  : std::true_type
{
};

template<>
struct is_service_request<vacuum_msgs::srv::ResetGame_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vacuum_msgs::srv::ResetGame_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VACUUM_MSGS__SRV__DETAIL__RESET_GAME__TRAITS_HPP_
