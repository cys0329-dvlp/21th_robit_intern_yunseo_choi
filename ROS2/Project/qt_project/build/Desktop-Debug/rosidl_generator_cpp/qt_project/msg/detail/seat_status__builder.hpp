// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/msg/seat_status.hpp"


#ifndef QT_PROJECT__MSG__DETAIL__SEAT_STATUS__BUILDER_HPP_
#define QT_PROJECT__MSG__DETAIL__SEAT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qt_project/msg/detail/seat_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qt_project
{

namespace msg
{

namespace builder
{

class Init_SeatStatus_absence_start_time
{
public:
  explicit Init_SeatStatus_absence_start_time(::qt_project::msg::SeatStatus & msg)
  : msg_(msg)
  {}
  ::qt_project::msg::SeatStatus absence_start_time(::qt_project::msg::SeatStatus::_absence_start_time_type arg)
  {
    msg_.absence_start_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::msg::SeatStatus msg_;
};

class Init_SeatStatus_has_belongings
{
public:
  explicit Init_SeatStatus_has_belongings(::qt_project::msg::SeatStatus & msg)
  : msg_(msg)
  {}
  Init_SeatStatus_absence_start_time has_belongings(::qt_project::msg::SeatStatus::_has_belongings_type arg)
  {
    msg_.has_belongings = std::move(arg);
    return Init_SeatStatus_absence_start_time(msg_);
  }

private:
  ::qt_project::msg::SeatStatus msg_;
};

class Init_SeatStatus_occupied
{
public:
  explicit Init_SeatStatus_occupied(::qt_project::msg::SeatStatus & msg)
  : msg_(msg)
  {}
  Init_SeatStatus_has_belongings occupied(::qt_project::msg::SeatStatus::_occupied_type arg)
  {
    msg_.occupied = std::move(arg);
    return Init_SeatStatus_has_belongings(msg_);
  }

private:
  ::qt_project::msg::SeatStatus msg_;
};

class Init_SeatStatus_seat_id
{
public:
  Init_SeatStatus_seat_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SeatStatus_occupied seat_id(::qt_project::msg::SeatStatus::_seat_id_type arg)
  {
    msg_.seat_id = std::move(arg);
    return Init_SeatStatus_occupied(msg_);
  }

private:
  ::qt_project::msg::SeatStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::msg::SeatStatus>()
{
  return qt_project::msg::builder::Init_SeatStatus_seat_id();
}

}  // namespace qt_project

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_STATUS__BUILDER_HPP_
