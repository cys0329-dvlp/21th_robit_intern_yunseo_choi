// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qt_project:srv/GetRoute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/srv/get_route.hpp"


#ifndef QT_PROJECT__SRV__DETAIL__GET_ROUTE__TRAITS_HPP_
#define QT_PROJECT__SRV__DETAIL__GET_ROUTE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qt_project/srv/detail/get_route__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qt_project
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRoute_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: seat_ids
  {
    if (msg.seat_ids.size() == 0) {
      out << "seat_ids: []";
    } else {
      out << "seat_ids: [";
      size_t pending_items = msg.seat_ids.size();
      for (auto item : msg.seat_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRoute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: seat_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.seat_ids.size() == 0) {
      out << "seat_ids: []\n";
    } else {
      out << "seat_ids:\n";
      for (auto item : msg.seat_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRoute_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qt_project

namespace rosidl_generator_traits
{

[[deprecated("use qt_project::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qt_project::srv::GetRoute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  qt_project::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qt_project::srv::to_yaml() instead")]]
inline std::string to_yaml(const qt_project::srv::GetRoute_Request & msg)
{
  return qt_project::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qt_project::srv::GetRoute_Request>()
{
  return "qt_project::srv::GetRoute_Request";
}

template<>
inline const char * name<qt_project::srv::GetRoute_Request>()
{
  return "qt_project/srv/GetRoute_Request";
}

template<>
struct has_fixed_size<qt_project::srv::GetRoute_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qt_project::srv::GetRoute_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<qt_project::srv::GetRoute_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace qt_project
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRoute_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: route
  {
    if (msg.route.size() == 0) {
      out << "route: []";
    } else {
      out << "route: [";
      size_t pending_items = msg.route.size();
      for (auto item : msg.route) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRoute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: route
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.route.size() == 0) {
      out << "route: []\n";
    } else {
      out << "route:\n";
      for (auto item : msg.route) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRoute_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qt_project

namespace rosidl_generator_traits
{

[[deprecated("use qt_project::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qt_project::srv::GetRoute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  qt_project::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qt_project::srv::to_yaml() instead")]]
inline std::string to_yaml(const qt_project::srv::GetRoute_Response & msg)
{
  return qt_project::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qt_project::srv::GetRoute_Response>()
{
  return "qt_project::srv::GetRoute_Response";
}

template<>
inline const char * name<qt_project::srv::GetRoute_Response>()
{
  return "qt_project/srv/GetRoute_Response";
}

template<>
struct has_fixed_size<qt_project::srv::GetRoute_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qt_project::srv::GetRoute_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<qt_project::srv::GetRoute_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace qt_project
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetRoute_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetRoute_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetRoute_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qt_project

namespace rosidl_generator_traits
{

[[deprecated("use qt_project::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qt_project::srv::GetRoute_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  qt_project::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qt_project::srv::to_yaml() instead")]]
inline std::string to_yaml(const qt_project::srv::GetRoute_Event & msg)
{
  return qt_project::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qt_project::srv::GetRoute_Event>()
{
  return "qt_project::srv::GetRoute_Event";
}

template<>
inline const char * name<qt_project::srv::GetRoute_Event>()
{
  return "qt_project/srv/GetRoute_Event";
}

template<>
struct has_fixed_size<qt_project::srv::GetRoute_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qt_project::srv::GetRoute_Event>
  : std::integral_constant<bool, has_bounded_size<qt_project::srv::GetRoute_Request>::value && has_bounded_size<qt_project::srv::GetRoute_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<qt_project::srv::GetRoute_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qt_project::srv::GetRoute>()
{
  return "qt_project::srv::GetRoute";
}

template<>
inline const char * name<qt_project::srv::GetRoute>()
{
  return "qt_project/srv/GetRoute";
}

template<>
struct has_fixed_size<qt_project::srv::GetRoute>
  : std::integral_constant<
    bool,
    has_fixed_size<qt_project::srv::GetRoute_Request>::value &&
    has_fixed_size<qt_project::srv::GetRoute_Response>::value
  >
{
};

template<>
struct has_bounded_size<qt_project::srv::GetRoute>
  : std::integral_constant<
    bool,
    has_bounded_size<qt_project::srv::GetRoute_Request>::value &&
    has_bounded_size<qt_project::srv::GetRoute_Response>::value
  >
{
};

template<>
struct is_service<qt_project::srv::GetRoute>
  : std::true_type
{
};

template<>
struct is_service_request<qt_project::srv::GetRoute_Request>
  : std::true_type
{
};

template<>
struct is_service_response<qt_project::srv::GetRoute_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QT_PROJECT__SRV__DETAIL__GET_ROUTE__TRAITS_HPP_
