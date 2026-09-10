#include "listener_node.hpp"

ListenerNode::ListenerNode()
    : QObject(nullptr),
    Node("listener_node")
{
    // chatter 토픽 Subscriber 생성 (문자열 구독)
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "chatter", 10,
        std::bind(&ListenerNode::topic_callback, this, std::placeholders::_1));
}

// 메시지를 구독했을 때 호출되는 콜백
void ListenerNode::topic_callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Subscribed: '%s'", msg->data.c_str());

    // Qt 시그널로 변환하여 MainWindow 쪽에 전달
    emit messageReceived(QString::fromStdString(msg->data));
}
