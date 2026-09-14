// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qt_project:msg/SeatCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/msg/seat_command.hpp"


#ifndef QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__BUILDER_HPP_
#define QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qt_project/msg/detail/seat_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qt_project
{

namespace msg
{

namespace builder
{

class Init_SeatCommand_has_belongings
{
public:
  explicit Init_SeatCommand_has_belongings(::qt_project::msg::SeatCommand & msg)
  : msg_(msg)
  {}
  ::qt_project::msg::SeatCommand has_belongings(::qt_project::msg::SeatCommand::_has_belongings_type arg)
  {
    msg_.has_belongings = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::msg::SeatCommand msg_;
};

class Init_SeatCommand_occupied
{
public:
  explicit Init_SeatCommand_occupied(::qt_project::msg::SeatCommand & msg)
  : msg_(msg)
  {}
  Init_SeatCommand_has_belongings occupied(::qt_project::msg::SeatCommand::_occupied_type arg)
  {
    msg_.occupied = std::move(arg);
    return Init_SeatCommand_has_belongings(msg_);
  }

private:
  ::qt_project::msg::SeatCommand msg_;
};

class Init_SeatCommand_seat_id
{
public:
  Init_SeatCommand_seat_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeatCommand_occupied seat_id(::qt_project::msg::SeatCommand::_seat_id_type arg)
  {
    msg_.seat_id = std::move(arg);
    return Init_SeatCommand_occupied(msg_);
  }

private:
  ::qt_project::msg::SeatCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::msg::SeatCommand>()
{
  return qt_project::msg::builder::Init_SeatCommand_seat_id();
}

}  // namespace qt_project

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__BUILDER_HPP_
