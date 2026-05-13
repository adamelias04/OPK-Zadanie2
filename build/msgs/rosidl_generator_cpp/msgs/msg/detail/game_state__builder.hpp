// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__GAME_STATE__BUILDER_HPP_
#define MSGS__MSG__DETAIL__GAME_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/game_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_GameState_winner
{
public:
  explicit Init_GameState_winner(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  ::msgs::msg::GameState winner(::msgs::msg::GameState::_winner_type arg)
  {
    msg_.winner = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_robots
{
public:
  explicit Init_GameState_robots(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_winner robots(::msgs::msg::GameState::_robots_type arg)
  {
    msg_.robots = std::move(arg);
    return Init_GameState_winner(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_active_trash
{
public:
  explicit Init_GameState_active_trash(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_robots active_trash(::msgs::msg::GameState::_active_trash_type arg)
  {
    msg_.active_trash = std::move(arg);
    return Init_GameState_robots(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_collected
{
public:
  explicit Init_GameState_collected(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_active_trash collected(::msgs::msg::GameState::_collected_type arg)
  {
    msg_.collected = std::move(arg);
    return Init_GameState_active_trash(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_score
{
public:
  explicit Init_GameState_score(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_collected score(::msgs::msg::GameState::_score_type arg)
  {
    msg_.score = std::move(arg);
    return Init_GameState_collected(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_elapsed_seconds
{
public:
  explicit Init_GameState_elapsed_seconds(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_score elapsed_seconds(::msgs::msg::GameState::_elapsed_seconds_type arg)
  {
    msg_.elapsed_seconds = std::move(arg);
    return Init_GameState_score(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_phase
{
public:
  explicit Init_GameState_phase(::msgs::msg::GameState & msg)
  : msg_(msg)
  {}
  Init_GameState_elapsed_seconds phase(::msgs::msg::GameState::_phase_type arg)
  {
    msg_.phase = std::move(arg);
    return Init_GameState_elapsed_seconds(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

class Init_GameState_mode
{
public:
  Init_GameState_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameState_phase mode(::msgs::msg::GameState::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_GameState_phase(msg_);
  }

private:
  ::msgs::msg::GameState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::GameState>()
{
  return msgs::msg::builder::Init_GameState_mode();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__GAME_STATE__BUILDER_HPP_
