// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vacuum_msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__GAME_STATE__BUILDER_HPP_
#define VACUUM_MSGS__MSG__DETAIL__GAME_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vacuum_msgs/msg/detail/game_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vacuum_msgs
{

namespace msg
{

namespace builder
{

class Init_GameState_winner
{
public:
  explicit Init_GameState_winner(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  ::vacuum_msgs::msg::GameState winner(::vacuum_msgs::msg::GameState::_winner_type arg)
  {
    msg_.winner = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_robots
{
public:
  explicit Init_GameState_robots(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_winner robots(::vacuum_msgs::msg::GameState::_robots_type arg)
  {
    msg_.robots = std::move(arg);
    return Init_GameState_winner(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_active_trash
{
public:
  explicit Init_GameState_active_trash(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_robots active_trash(::vacuum_msgs::msg::GameState::_active_trash_type arg)
  {
    msg_.active_trash = std::move(arg);
    return Init_GameState_robots(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_collected
{
public:
  explicit Init_GameState_collected(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_active_trash collected(::vacuum_msgs::msg::GameState::_collected_type arg)
  {
    msg_.collected = std::move(arg);
    return Init_GameState_active_trash(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_score
{
public:
  explicit Init_GameState_score(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_collected score(::vacuum_msgs::msg::GameState::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_GameState_collected(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_elapsed_seconds
{
public:
  explicit Init_GameState_elapsed_seconds(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_score elapsed_seconds(::vacuum_msgs::msg::GameState::_elapsed_seconds_type arg)
  {
    msg_.elapsed_seconds = std::move(arg);
    return Init_GameState_score(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_phase
{
public:
  explicit Init_GameState_phase(::vacuum_msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_elapsed_seconds phase(::vacuum_msgs::msg::GameState::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_GameState_elapsed_seconds(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

class Init_GameState_mode
{
public:
  Init_GameState_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameState_phase mode(::vacuum_msgs::msg::GameState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_GameState_phase(msg_);
  }

private:
  ::vacuum_msgs::msg::GameState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::msg::GameState>()
{
  return vacuum_msgs::msg::builder::Init_GameState_mode();
}

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__MSG__DETAIL__GAME_STATE__BUILDER_HPP_
