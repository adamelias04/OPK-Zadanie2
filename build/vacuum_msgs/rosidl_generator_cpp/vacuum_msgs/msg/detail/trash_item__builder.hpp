// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vacuum_msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__BUILDER_HPP_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vacuum_msgs/msg/detail/trash_item__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vacuum_msgs
{

namespace msg
{

namespace builder
{

class Init_TrashItem_score_value
{
public:
  explicit Init_TrashItem_score_value(::vacuum_msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  ::vacuum_msgs::msg::TrashItem score_value(::vacuum_msgs::msg::TrashItem::_score_value_type arg)
  {
    msg_.score_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashItem msg_;
};

class Init_TrashItem_color
{
public:
  explicit Init_TrashItem_color(::vacuum_msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_score_value color(::vacuum_msgs::msg::TrashItem::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_TrashItem_score_value(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashItem msg_;
};

class Init_TrashItem_radius
{
public:
  explicit Init_TrashItem_radius(::vacuum_msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_color radius(::vacuum_msgs::msg::TrashItem::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_TrashItem_color(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashItem msg_;
};

class Init_TrashItem_position
{
public:
  explicit Init_TrashItem_position(::vacuum_msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_radius position(::vacuum_msgs::msg::TrashItem::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_TrashItem_radius(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashItem msg_;
};

class Init_TrashItem_type
{
public:
  explicit Init_TrashItem_type(::vacuum_msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_position type(::vacuum_msgs::msg::TrashItem::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_TrashItem_position(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashItem msg_;
};

class Init_TrashItem_id
{
public:
  Init_TrashItem_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrashItem_type id(::vacuum_msgs::msg::TrashItem::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_TrashItem_type(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashItem msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::msg::TrashItem>()
{
  return vacuum_msgs::msg::builder::Init_TrashItem_id();
}

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__BUILDER_HPP_
