// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vacuum_msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__GAME_STATE__TRAITS_HPP_
#define VACUUM_MSGS__MSG__DETAIL__GAME_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vacuum_msgs/msg/detail/game_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'collected'
#include "vacuum_msgs/msg/detail/trash_count__traits.hpp"
// Member 'active_trash'
#include "vacuum_msgs/msg/detail/trash_item__traits.hpp"
// Member 'robots'
#include "vacuum_msgs/msg/detail/robot_status__traits.hpp"

namespace vacuum_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GameState & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: phase
  {
    out << "phase: ";
    rosidl_generator_traits::value_to_yaml(msg.phase, out);
    out << ", ";
  }

  // member: elapsed_seconds
  {
    out << "elapsed_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_seconds, out);
    out << ", ";
  }

  // member: score
  {
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << ", ";
  }

  // member: collected
  {
    if (msg.collected.size() == 0) {
      out << "collected: []";
    } else {
      out << "collected: [";
      size_t pending_items = msg.collected.size();
      for (auto item : msg.collected) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: active_trash
  {
    if (msg.active_trash.size() == 0) {
      out << "active_trash: []";
    } else {
      out << "active_trash: [";
      size_t pending_items = msg.active_trash.size();
      for (auto item : msg.active_trash) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: robots
  {
    if (msg.robots.size() == 0) {
      out << "robots: []";
    } else {
      out << "robots: [";
      size_t pending_items = msg.robots.size();
      for (auto item : msg.robots) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: winner
  {
    out << "winner: ";
    rosidl_generator_traits::value_to_yaml(msg.winner, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GameState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: phase
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "phase: ";
    rosidl_generator_traits::value_to_yaml(msg.phase, out);
    out << "\n";
  }

  // member: elapsed_seconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elapsed_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_seconds, out);
    out << "\n";
  }

  // member: score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "score: ";
    rosidl_generator_traits::value_to_yaml(msg.score, out);
    out << "\n";
  }

  // member: collected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.collected.size() == 0) {
      out << "collected: []\n";
    } else {
      out << "collected:\n";
      for (auto item : msg.collected) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: active_trash
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.active_trash.size() == 0) {
      out << "active_trash: []\n";
    } else {
      out << "active_trash:\n";
      for (auto item : msg.active_trash) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: robots
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robots.size() == 0) {
      out << "robots: []\n";
    } else {
      out << "robots:\n";
      for (auto item : msg.robots) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: winner
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "winner: ";
    rosidl_generator_traits::value_to_yaml(msg.winner, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GameState & msg, bool use_flow_style = false)
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
  const vacuum_msgs::msg::GameState & msg,
  std::ostream & out, size_t indentation = 0)
{
  vacuum_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vacuum_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const vacuum_msgs::msg::GameState & msg)
{
  return vacuum_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vacuum_msgs::msg::GameState>()
{
  return "vacuum_msgs::msg::GameState";
}

template<>
inline const char * name<vacuum_msgs::msg::GameState>()
{
  return "vacuum_msgs/msg/GameState";
}

template<>
struct has_fixed_size<vacuum_msgs::msg::GameState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vacuum_msgs::msg::GameState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vacuum_msgs::msg::GameState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VACUUM_MSGS__MSG__DETAIL__GAME_STATE__TRAITS_HPP_
