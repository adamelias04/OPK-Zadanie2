// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:srv/CollectTrash.idl
// generated code does not contain a copyright notice

#ifndef MSGS__SRV__DETAIL__COLLECT_TRASH__BUILDER_HPP_
#define MSGS__SRV__DETAIL__COLLECT_TRASH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/srv/detail/collect_trash__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace srv
{

namespace builder
{

class Init_CollectTrash_Request_robot_radius
{
public:
  explicit Init_CollectTrash_Request_robot_radius(::msgs::srv::CollectTrash_Request & msg)
  : msg_(msg)
  {}
  ::msgs::srv::CollectTrash_Request robot_radius(::msgs::srv::CollectTrash_Request::_robot_radius_type arg)
  {
    msg_.robot_radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Request msg_;
};

class Init_CollectTrash_Request_robot_pos
{
public:
  explicit Init_CollectTrash_Request_robot_pos(::msgs::srv::CollectTrash_Request & msg)
  : msg_(msg)
  {}
  Init_CollectTrash_Request_robot_radius robot_pos(::msgs::srv::CollectTrash_Request::_robot_pos_type arg)
  {
    msg_.robot_pos = std::move(arg);
    return Init_CollectTrash_Request_robot_radius(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Request msg_;
};

class Init_CollectTrash_Request_robot_id
{
public:
  Init_CollectTrash_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CollectTrash_Request_robot_pos robot_id(::msgs::srv::CollectTrash_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_CollectTrash_Request_robot_pos(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::srv::CollectTrash_Request>()
{
  return msgs::srv::builder::Init_CollectTrash_Request_robot_id();
}

}  // namespace msgs


namespace msgs
{

namespace srv
{

namespace builder
{

class Init_CollectTrash_Response_capacity_max
{
public:
  explicit Init_CollectTrash_Response_capacity_max(::msgs::srv::CollectTrash_Response & msg)
  : msg_(msg)
  {}
  ::msgs::srv::CollectTrash_Response capacity_max(::msgs::srv::CollectTrash_Response::_capacity_max_type arg)
  {
    msg_.capacity_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Response msg_;
};

class Init_CollectTrash_Response_capacity_used
{
public:
  explicit Init_CollectTrash_Response_capacity_used(::msgs::srv::CollectTrash_Response & msg)
  : msg_(msg)
  {}
  Init_CollectTrash_Response_capacity_max capacity_used(::msgs::srv::CollectTrash_Response::_capacity_used_type arg)
  {
    msg_.capacity_used = std::move(arg);
    return Init_CollectTrash_Response_capacity_max(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Response msg_;
};

class Init_CollectTrash_Response_collected
{
public:
  explicit Init_CollectTrash_Response_collected(::msgs::srv::CollectTrash_Response & msg)
  : msg_(msg)
  {}
  Init_CollectTrash_Response_capacity_used collected(::msgs::srv::CollectTrash_Response::_collected_type arg)
  {
    msg_.collected = std::move(arg);
    return Init_CollectTrash_Response_capacity_used(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Response msg_;
};

class Init_CollectTrash_Response_success
{
public:
  Init_CollectTrash_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CollectTrash_Response_collected success(::msgs::srv::CollectTrash_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CollectTrash_Response_collected(msg_);
  }

private:
  ::msgs::srv::CollectTrash_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::srv::CollectTrash_Response>()
{
  return msgs::srv::builder::Init_CollectTrash_Response_success();
}

}  // namespace msgs

#endif  // MSGS__SRV__DETAIL__COLLECT_TRASH__BUILDER_HPP_
