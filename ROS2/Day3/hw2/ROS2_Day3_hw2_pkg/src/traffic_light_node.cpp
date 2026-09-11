#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <string>

using namespace std::chrono_literals;

class TrafficLightNode : public rclcpp::Node
{
public:
    TrafficLightNode()
    : Node("traffic_light")
    {
        red_time_ = this->declare_parameter<double>("red_time", 5.0);
        green_time_ = this->declare_parameter<double>("green_time", 5.0);
        yellow_time_ = this->declare_parameter<double>("yellow_time", 3.0);

        publisher_ = this->create_publisher<std_msgs::msg::String>(
            "traffic_light_state", 10);

        current_state_ = "RED";
        state_time_ = 0.0;

        timer_ = this->create_wall_timer(
            100ms,
            std::bind(&TrafficLightNode::timerCallback, this));

        RCLCPP_INFO(this->get_logger(), "Traffic light node started");
        RCLCPP_INFO(this->get_logger(), "Current state: RED");
    }

private:
    void timerCallback()
    {
        state_time_ += 0.1;

        double current_time = red_time_;

        if (current_state_ == "GREEN")
        {
            current_time = green_time_;
        }
        else if (current_state_ == "YELLOW")
        {
            current_time = yellow_time_;
        }

        if (state_time_ >= current_time)
        {
            state_time_ = 0.0;

            if (current_state_ == "RED")
            {
                current_state_ = "GREEN";
            }
            else if (current_state_ == "GREEN")
            {
                current_state_ = "YELLOW";
            }
            else
            {
                current_state_ = "RED";
            }

            RCLCPP_INFO(
                this->get_logger(),
                "Traffic light changed to %s",
                current_state_.c_str());
        }

        std_msgs::msg::String message;
        message.data = current_state_;

        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::string current_state_;

    double red_time_;
    double green_time_;
    double yellow_time_;
    double state_time_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TrafficLightNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}