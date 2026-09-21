#pragma once

#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>
#include <string>

namespace camera_ui_pkg // 다른 클래스에 있는 변수와 충돌하지 않도록 namespace 안에 넣어주기
{

class CameraNode : public rclcpp::Node
{
public:

    // 생성자 선언 
    explicit CameraNode(
        const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

    ~CameraNode() override;

private:
    void timerCallback(); //yaml에서 헤르츠 30으로 설정 -> 1초에 30번씩 실행됨 

    bool openCaptureSource(); //카메라 여는 함수-> bool로 선언 -> 켜지면 true, 안켜지면 false 반환
    //return cap_.isOpened();를 통해 성공 여부 반환함

    std::string camera_source_;

    int frame_width_; //가로
    int frame_height_; //세로

    double publish_rate_hz_; //yaml에서 30으로 설정 -> 1초에 30번씩 불러옴

    cv::VideoCapture cap_;


    image_transport::Publisher image_pub_;

    rclcpp::TimerBase::SharedPtr timer_;
};

}