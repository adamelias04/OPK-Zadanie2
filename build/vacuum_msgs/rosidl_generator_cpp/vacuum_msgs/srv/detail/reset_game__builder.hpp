// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vacuum_msgs:srv/ResetGame.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__RESET_GAME__BUILDER_HPP_
#define VACUUM_MSGS__SRV__DETAIL__RESET_GAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vacuum_msgs/srv/detail/reset_game__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vacuum_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::srv::ResetGame_Request>()
{
  return ::vacuum_msgs::srv::ResetGame_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace vacuum_msgs


namespace vacuum_msgs
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
  ::vacuum_msgs::srv::ResetGame_Response success(::vacuum_msgs::srv::ResetGame_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::srv::ResetGame_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::srv::ResetGame_Response>()
{
  return vacuum_msgs::srv::builder::Init_ResetGame_Response_success();
}

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__SRV__DETAIL__RESET_GAME__BUILDER_HPP_
