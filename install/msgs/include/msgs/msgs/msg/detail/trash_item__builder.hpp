// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRASH_ITEM__BUILDER_HPP_
#define MSGS__MSG__DETAIL__TRASH_ITEM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/trash_item__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_TrashItem_score_value
{
public:
  explicit Init_TrashItem_score_value(::msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  ::msgs::msg::TrashItem score_value(::msgs::msg::TrashItem::_score_value_type arg)
  {
    msg_.score_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::TrashItem msg_;
};

class Init_TrashItem_color
{
public:
  explicit Init_TrashItem_color(::msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_score_value color(::msgs::msg::TrashItem::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_TrashItem_score_value(msg_);
  }

private:
  ::msgs::msg::TrashItem msg_;
};

class Init_TrashItem_radius
{
public:
  explicit Init_TrashItem_radius(::msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_color radius(::msgs::msg::TrashItem::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_TrashItem_color(msg_);
  }

private:
  ::msgs::msg::TrashItem msg_;
};

class Init_TrashItem_position
{
public:
  explicit Init_TrashItem_position(::msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_radius position(::msgs::msg::TrashItem::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_TrashItem_radius(msg_);
  }

private:
  ::msgs::msg::TrashItem msg_;
};

class Init_TrashItem_type
{
public:
  explicit Init_TrashItem_type(::msgs::msg::TrashItem & msg)
  : msg_(msg)
  {}
  Init_TrashItem_position type(::msgs::msg::TrashItem::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_TrashItem_position(msg_);
  }

private:
  ::msgs::msg::TrashItem msg_;
};

class Init_TrashItem_id
{
public:
  Init_TrashItem_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrashItem_type id(::msgs::msg::TrashItem::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_TrashItem_type(msg_);
  }

private:
  ::msgs::msg::TrashItem msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::TrashItem>()
{
  return msgs::msg::builder::Init_TrashItem_id();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__TRASH_ITEM__BUILDER_HPP_
