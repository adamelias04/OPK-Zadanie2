// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:srv/ResetGame.idl
// generated code does not contain a copyright notice

#ifndef MSGS__SRV__DETAIL__RESET_GAME__BUILDER_HPP_
#define MSGS__SRV__DETAIL__RESET_GAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/srv/detail/reset_game__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::srv::ResetGame_Request>()
{
  return ::msgs::srv::ResetGame_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace msgs


namespace msgs
{

namespace srv
{

namespace builder
{

class Init_ResetGame_Response_success
{
public:
  Init_ResetGame_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::msgs::srv::ResetGame_Response success(::msgs::srv::ResetGame_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::srv::ResetGame_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::srv::ResetGame_Response>()
{
  return msgs::srv::builder::Init_ResetGame_Response_success();
}

}  // namespace msgs

#endif  // MSGS__SRV__DETAIL__RESET_GAME__BUILDER_HPP_
