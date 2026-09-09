#include "talker.hpp"

Talker::Talker() : Node("talker")
{
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("number", 10);
    text_publisher_ = this->create_publisher<std_msgs::msg::String>("text", 10);
    float_publisher_ = this->create_publisher<std_msgs::msg::Float32>("float_number", 10);
    bool_publisher_ = this->create_publisher<std_msgs::msg::Bool>("bool_number", 10);
    timer_ = this->create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&Talker::publish_number, this)
    );
}

void Talker::publish_number()
{
    auto message = std_msgs::msg::Int32();
    message.data = count_;
    auto text_message = std_msgs::msg::String();
    text_message.data = "Hello, world! " + std::to_string(count_);
    auto float_message = std_msgs::msg::Float32();
    float_message.data = static_cast<float>(count_);
    auto bool_message = std_msgs::msg::Bool();
    bool_message.data = count_ % 2 == 0;
    RCLCPP_INFO(this->get_logger(), "Publishing: %d", message.data);
    RCLCPP_INFO(this->get_logger(), "Publishing: %s", text_message.data.c_str());
    RCLCPP_INFO(this->get_logger(), "Publishing: %f", float_message.data);
    RCLCPP_INFO(this->get_logger(), "Publishing: %d", bool_message.data);
    count_++;
    publisher_->publish(message);
    text_publisher_->publish(text_message);
    float_publisher_->publish(float_message);
    bool_publisher_->publish(bool_message);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
 
    rclcpp::spin(std::make_shared<Talker>());
 
    rclcpp::shutdown();
 
    return 0;
}