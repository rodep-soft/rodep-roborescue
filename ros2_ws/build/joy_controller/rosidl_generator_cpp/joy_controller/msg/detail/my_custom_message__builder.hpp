// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice

#ifndef JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__BUILDER_HPP_
#define JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "joy_controller/msg/detail/my_custom_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace joy_controller
{

namespace msg
{

namespace builder
{

class Init_MyCustomMessage_my_buttons
{
public:
  explicit Init_MyCustomMessage_my_buttons(::joy_controller::msg::MyCustomMessage & msg)
  : msg_(msg)
  {}
  ::joy_controller::msg::MyCustomMessage my_buttons(::joy_controller::msg::MyCustomMessage::_my_buttons_type arg)
  {
    msg_.my_buttons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::joy_controller::msg::MyCustomMessage msg_;
};

class Init_MyCustomMessage_my_axes
{
public:
  Init_MyCustomMessage_my_axes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyCustomMessage_my_buttons my_axes(::joy_controller::msg::MyCustomMessage::_my_axes_type arg)
  {
    msg_.my_axes = std::move(arg);
    return Init_MyCustomMessage_my_buttons(msg_);
  }

private:
  ::joy_controller::msg::MyCustomMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::joy_controller::msg::MyCustomMessage>()
{
  return joy_controller::msg::builder::Init_MyCustomMessage_my_axes();
}

}  // namespace joy_controller

#endif  // JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__BUILDER_HPP_
