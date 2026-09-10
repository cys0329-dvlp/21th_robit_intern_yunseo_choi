#ifndef MY_TOPIC_PKG__INT_ARRAY_PUBLISHER_HPP_
#define MY_TOPIC_PKG__INT_ARRAY_PUBLISHER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/int_array.hpp"

class IntArrayPublisher : public rclcpp::Node
{
public:
  IntArrayPublisher();
  void run();  // 사용자 입력을 받아서 퍼블리시하는 루프

private:
  rclcpp::Publisher<custom_interfaces::msg::IntArray>::SharedPtr publisher_;
};

#endif