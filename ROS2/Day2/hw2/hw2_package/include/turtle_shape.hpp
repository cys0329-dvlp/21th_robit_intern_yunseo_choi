#ifndef TURTLE_SHAPE_HPP_
#define TURTLE_SHAPE_HPP_

#include <QObject>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/srv/set_pen.hpp>

#include <string>

// QObject를 함께 상속하여 Qt의 signal/slot 메커니즘을 사용할 수 있게 함
class TurtleShape : public QObject, public rclcpp::Node
{
    Q_OBJECT

public:
    TurtleShape();

signals:
    void cmdVelChanged(double linear_x, double angular_z);

public slots:
    // Qt 버튼의 clicked() 시그널과 연결할 슬롯들
    // 예) connect(ui->pushButton_square, &QPushButton::clicked,
    //             turtleShape, &TurtleShape::onSquareButtonClicked);
    void onSquareButtonClicked();
    void onTriangleButtonClicked();
    void onCircleButtonClicked();

private:
    // cmd_vel Publisher
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

    // SetPen Service Client
    rclcpp::Client<turtlesim::srv::SetPen>::SharedPtr pen_client_;

    // 0.01초마다 실행되는 타이머 (도형 그리기 상태 머신)
    rclcpp::TimerBase::SharedPtr timer_;

    // 현재 선택된 도형
    std::string shape_;

    // 그리기 상태
    int state_;

    rclcpp::Time start_time_;

    // 그리는 중인지 여부
    bool drawing_;

    // 펜 설정
    int pen_r_;
    int pen_g_;
    int pen_b_;
    int pen_width_;

    // 버튼 클릭 공통 처리 (펜 색상/두께 설정 + 그리기 시작)
    void start_drawing(
        const std::string & shape,
        int r, int g, int b, int width);

    // 펜 설정 서비스 호출
    void set_pen();

    // 경과 시간 계산
    double elapsed_time();

    // 메인 그리기 Callback
    void timer_callback();
};

#endif  // TURTLE_SHAPE_HPP_
