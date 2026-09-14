// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/msg/seat_status.hpp"


#ifndef QT_PROJECT__MSG__DETAIL__SEAT_STATUS__TRAITS_HPP_
#define QT_PROJECT__MSG__DETAIL__SEAT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qt_project/msg/detail/seat_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qt_project
{

namespace msg
{

inline void to_flow_style_yaml(
  const SeatStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: seat_id
  {
    out << "seat_id: ";
    rosidl_generator_traits::value_to_yaml(msg.seat_id, out);
    out << ", ";
  }

  // member: occupied
  {
    out << "occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.occupied, out);
    out << ", ";
  }

  // member: has_belongings
  {
    out << "has_belongings: ";
    rosidl_generator_traits::value_to_yaml(msg.has_belongings, out);
    out << ", ";
  }

  // member: absence_start_time
  {
    out << "absence_start_time: ";
    rosidl_generator_traits::value_to_yaml(msg.absence_start_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SeatStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: seat_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seat_id: ";
    rosidl_generator_traits::value_to_yaml(msg.seat_id, out);
    out << "\n";
  }

  // member: occupied
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "occupied: ";
    rosidl_generator_traits::value_to_yaml(msg.occupied, out);
    out << "\n";
  }

  // member: has_belongings
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_belongings: ";
    rosidl_generator_traits::value_to_yaml(msg.has_belongings, out);
    out << "\n";
  }

  // member: absence_start_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "absence_start_time: ";
    rosidl_generator_traits::value_to_yaml(msg.absence_start_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SeatStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace qt_project

namespace rosidl_generator_traits
{

[[deprecated("use qt_project::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qt_project::msg::SeatStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  qt_project::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qt_project::msg::to_yaml() instead")]]
inline std::string to_yaml(const qt_project::msg::SeatStatus & msg)
{
  return qt_project::msg::to_yaml(msg);
}

template<>
inline const char * data_type<qt_project::msg::SeatStatus>()
{
  return "qt_project::msg::SeatStatus";
}

template<>
inline const char * name<qt_project::msg::SeatStatus>()
{
  return "qt_project/msg/SeatStatus";
}

template<>
struct has_fixed_size<qt_project::msg::SeatStatus>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<qt_project::msg::SeatStatus>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<qt_project::msg::SeatStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_STATUS__TRAITS_HPP_
