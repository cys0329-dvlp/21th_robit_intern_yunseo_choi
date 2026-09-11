#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/point.hpp"

#include <string>

using namespace std::chrono_literals;

class VehicleNode : public rclcpp::Node
{
public:
    VehicleNode()
    : Node("vehicle")
    {
        speed_ = this->declare_parameter<double>("speed", 2.0);
        slow_speed_ = this->declare_parameter<double>("slow_speed", 0.8);
        position_ = this->declare_parameter<double>("start_position", 0.0);
        stop_line_ = this->declare_parameter<double>("stop_line", 10.0);
        max_position_ = this->declare_parameter<double>("max_position", 30.0);
        update_period_ = this->declare_parameter<double>("update_period", 0.1);

        traffic_light_state_ = "RED";
        current_speed_ = 0.0;

        light_subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "traffic_light_state",
            10,
            std::bind(
                &VehicleNode::trafficLightCallback,
                this,
                std::placeholders::_1));

        position_publisher_ =
            this->create_publisher<geometry_msgs::msg::Point>(
                "vehicle_position",
                10);

        timer_ = this->create_wall_timer(
            100ms,
            std::bind(&VehicleNode::timerCallback, this));

        RCLCPP_INFO(this->get_logger(), "Vehicle node started");
    }

private:
    void trafficLightCallback(
        const std_msgs::msg::String::SharedPtr message)
    {
        traffic_light_state_ = message->data;
    }

    void timerCallback()
    {
        if (traffic_light_state_ == "GREEN")
        {
            current_speed_ = speed_;
        }
        else if (traffic_light_state_ == "YELLOW")
        {
            // 노란불에서는 차량 속도를 조금씩 줄임
            if (current_speed_ > slow_speed_)
            {
                current_speed_ -= 0.1;

                if (current_speed_ < slow_speed_)
                {
                    current_speed_ = slow_speed_;
                }

            }
            else
            {
                // 빨간불에서는 차량이 정지
                current_speed_ = 0.0;
            }
        }
        position_ += current_speed_ * update_period_;

        if (position_ >= max_position_)
        {
            position_ = 0.0;
        }

        geometry_msgs::msg::Point message;

        message.x = position_;
        message.y = 0.0;
        message.z = current_speed_;

        position_publisher_->publish(message);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr light_subscriber_;

    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr position_publisher_;

    rclcpp::TimerBase::SharedPtr timer_;

    std::string traffic_light_state_;

    double speed_;
    double slow_speed_;
    double current_speed_;

    double position_;
    double stop_line_;
    double max_position_;
    double update_period_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<VehicleNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}