#include "talker_node.hpp"

TalkerNode::TalkerNode()
    : QObject(nullptr),
    Node("talker_node")
{
    // chatter 토픽 Publisher 생성 (문자열 퍼블리시)
    publisher_ = this->create_publisher<std_msgs::msg::String>(
        "chatter", 10);
}

// 버튼 클릭 시 QLineEdit의 텍스트를 퍼블리시
void TalkerNode::onPublishButtonClicked(const QString & text)
{
    std_msgs::msg::String msg;
    msg.data = text.toStdString();

    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());
    publisher_->publish(msg);
}
