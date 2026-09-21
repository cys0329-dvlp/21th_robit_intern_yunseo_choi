#pragma once

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QImage>

#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>
#include <sensor_msgs/msg/image.hpp>

#include <opencv2/opencv.hpp>

#include <mutex>

namespace camera_ui_pkg
{

class UiNode : public QWidget, public rclcpp::Node
{
    Q_OBJECT // signal, slot 기능 사용하기 위해 필요함

public:
    explicit UiNode(QWidget * parent = nullptr);

    ~UiNode() override;

private slots:
    void onDisplayTimer();

private:

    //msg: ROS2가 전달해주는 카메라 이미지 메시지 
    void imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr & msg);

    //실제 QT화면에서 카메라 영상을 보여줄 QLabel 가리킴
    QLabel * image_label_;

    //Timer의 객체를 저장하는 포인터
    QTimer * display_timer_;

    //카메라 영상을 받는 subscriber
    image_transport::Subscriber image_sub_;

    double display_rate_hz_; // QT화면을 몇 헤르츠로 갱신할지 결정

    std::mutex frame_mutex_; // latest_frame_을 보호하는 잠금 장치

    cv::Mat latest_frame_; // ROS2에서 가장 최근에 받은 프레임을 저장

    bool has_frame_{false};
};

}