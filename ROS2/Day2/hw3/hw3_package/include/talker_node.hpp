#ifndef TALKER_NODE_HPP_
#define TALKER_NODE_HPP_

#include <QObject>
#include <QString>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

// QObject를 함께 상속하여 Qt의 signal/slot 메커니즘을 사용할 수 있게 함
// Talker: 문자열을 퍼블리시만 하는 노드
class TalkerNode : public QObject, public rclcpp::Node
{
    Q_OBJECT

public:
    TalkerNode();

public slots:
    // Qt 버튼의 clicked() 시그널과 연결할 슬롯
    // 예) connect(ui->pushButton_publish, &QPushButton::clicked,
    //             talkerNode, &TalkerNode::onPublishButtonClicked);
    void onPublishButtonClicked(const QString & text);

private:
    // chatter 토픽 Publisher
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

#endif  // TALKER_NODE_HPP_
