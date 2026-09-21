#pragma once

#include <rclcpp/rclcpp.hpp> 
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>
#include <string>

namespace camera_ui_pkg  // 다른 패키지의 같은 이름 클래스와 충돌 안나게 해주는 namespace
{

class CameraNode : public rclcpp::Node //CameraNode가 rclcpp::Node를 상속 받음
{
  public:
    explicit CameraNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());
    ~CameraNode() override;

  private:
    // 캡처, 변환, 퍼블리시를 전부 timerCallback 안에서 해결함
    void timerCallback();

    // 실제 카메라 장치를 여는 시도
    bool openCaptureSource();

    // 실카메라가 없을 때 대신 사용할 합성 테스트 프레임 생성
    cv::Mat generateSyntheticFrame();

    //config/camera_ui.yaml 에서 값 주입
    std::string camera_source_;   // "0", "1" 같은 장치 인덱스 문자열 또는 영상 파일 경로
    bool use_synthetic_;          // true면 실카메라 대신 합성 영상을 사용
    int frame_width_;
    int frame_height_;
    double publish_rate_hz_;

    cv::VideoCapture cap_;
    int synthetic_frame_count_{0};

    image_transport::Publisher image_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

}  