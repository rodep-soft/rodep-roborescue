// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from joy_controller:msg/MyCustomMessage.idl
// generated code does not contain a copyright notice

#ifndef JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__STRUCT_HPP_
#define JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__joy_controller__msg__MyCustomMessage __attribute__((deprecated))
#else
# define DEPRECATED__joy_controller__msg__MyCustomMessage __declspec(deprecated)
#endif

namespace joy_controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MyCustomMessage_
{
  using Type = MyCustomMessage_<ContainerAllocator>;

  explicit MyCustomMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MyCustomMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _my_axes_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _my_axes_type my_axes;
  using _my_buttons_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _my_buttons_type my_buttons;

  // setters for named parameter idiom
  Type & set__my_axes(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->my_axes = _arg;
    return *this;
  }
  Type & set__my_buttons(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->my_buttons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    joy_controller::msg::MyCustomMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const joy_controller::msg::MyCustomMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      joy_controller::msg::MyCustomMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      joy_controller::msg::MyCustomMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__joy_controller__msg__MyCustomMessage
    std::shared_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__joy_controller__msg__MyCustomMessage
    std::shared_ptr<joy_controller::msg::MyCustomMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyCustomMessage_ & other) const
  {
    if (this->my_axes != other.my_axes) {
      return false;
    }
    if (this->my_buttons != other.my_buttons) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyCustomMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyCustomMessage_

// alias to use template instance with default allocator
using MyCustomMessage =
  joy_controller::msg::MyCustomMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace joy_controller

#endif  // JOY_CONTROLLER__MSG__DETAIL__MY_CUSTOM_MESSAGE__STRUCT_HPP_
