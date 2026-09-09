// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("number", 10);
    text_publisher_ = this->create_publisher<std_msgs::msg::String>("text", 10);
    float_publisher_ = this->create_publisher<std_msgs::msg::Float32>("float_number", 10);
    bool_publisher_ = this->create_publisher<std_msgs::msg::Bool>("bool_number", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::Int32();
    auto text_message = std_msgs::msg::String();
    auto float_message = std_msgs::msg::Float32();
    auto bool_message = std_msgs::msg::Bool();
    message.data = count_++;
    text_message.data = "Hello, world! " + std::to_string(count_++);
    float_message.data = static_cast<float>(count_++);
    bool_message.data = count_++ % 2 == 0;
    RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
    RCLCPP_INFO(this->get_logger(), "Publishing: %s", text_message.data.c_str());
    RCLCPP_INFO(this->get_logger(), "Publishing: %f", float_message.data);
    RCLCPP_INFO(this->get_logger(), "Publishing: %d", bool_message.data);
    publisher_->publish(message);
    text_publisher_->publish(text_message);
    float_publisher_->publish(float_message);
    bool_publisher_->publish(bool_message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr text_publisher_;
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr float_publisher_;
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr bool_publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
