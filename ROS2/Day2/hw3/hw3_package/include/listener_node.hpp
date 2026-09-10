#ifndef LISTENER_NODE_HPP_
#define LISTENER_NODE_HPP_

#include <QObject>
#include <QString>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

// QObject를 함께 상속하여 Qt의 signal/slot 메커니즘을 사용할 수 있게 함
// Listener: 문자열을 구독만 하는 노드
class ListenerNode : public QObject, public rclcpp::Node
{
    Q_OBJECT

public:
    ListenerNode();

signals:
    // 메시지를 구독(수신)했을 때 발생하는 시그널 -> MainWindow에서 라벨 갱신에 사용
    void messageReceived(QString msg);

private:
    // chatter 토픽 Subscriber
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    // 구독 콜백: 메시지를 받으면 Qt 시그널로 변환하여 emit
    void topic_callback(const std_msgs::msg::String::SharedPtr msg);
};

#endif  // LISTENER_NODE_HPP_
