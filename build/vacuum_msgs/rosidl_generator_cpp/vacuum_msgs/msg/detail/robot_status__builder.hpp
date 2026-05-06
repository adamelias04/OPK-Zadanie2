// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vacuum_msgs:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define VACUUM_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vacuum_msgs/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vacuum_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_in_collision
{
public:
  explicit Init_RobotStatus_in_collision(::vacuum_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::vacuum_msgs::msg::RobotStatus in_collision(::vacuum_msgs::msg::RobotStatus::_in_collision_type arg)
  {
    msg_.in_collision = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_capacity_max
{
public:
  explicit Init_RobotStatus_capacity_max(::vacuum_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_in_collision capacity_max(::vacuum_msgs::msg::RobotStatus::_capacity_max_type arg)
  {
    msg_.capacity_max = std::move(arg);
    return Init_RobotStatus_in_collision(msg_);
  }

private:
  ::vacuum_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_capacity_used
{
public:
  explicit Init_RobotStatus_capacity_used(::vacuum_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_capacity_max capacity_used(::vacuum_msgs::msg::RobotStatus::_capacity_used_type arg)
  {
    msg_.capacity_used = std::move(arg);
    return Init_RobotStatus_capacity_max(msg_);
  }

private:
  ::vacuum_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_velocity
{
public:
  explicit Init_RobotStatus_velocity(::vacuum_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_capacity_used velocity(::vacuum_msgs::msg::RobotStatus::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_RobotStatus_capacity_used(msg_);
  }

private:
  ::vacuum_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_pose
{
public:
  explicit Init_RobotStatus_pose(::vacuum_msgs::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_velocity pose(::vacuum_msgs::msg::RobotStatus::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_RobotStatus_velocity(msg_);
  }

private:
  ::vacuum_msgs::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_id
{
public:
  Init_RobotStatus_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_pose robot_id(::vacuum_msgs::msg::RobotStatus::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotStatus_pose(msg_);
  }

private:
  ::vacuum_msgs::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::msg::RobotStatus>()
{
  return vacuum_msgs::msg::builder::Init_RobotStatus_robot_id();
}

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
