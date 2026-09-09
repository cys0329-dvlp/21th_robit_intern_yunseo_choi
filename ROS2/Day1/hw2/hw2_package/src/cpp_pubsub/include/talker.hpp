#ifndef TALKER_HPP_
#define TALKER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"

class Talker : public rclcpp::Node
{
public:
    Talker();

private:
    void publish_number();

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr text_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_ = 0;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr float_publisher_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr bool_publisher_;
};

#endif  // TALKER_HPP_