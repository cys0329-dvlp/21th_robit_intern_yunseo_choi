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
#include <string>

namespace camera_ui_pkg
{

// QWidget과 rclcpp::Node를 동시에 상속 -> 이 클래스 자체가 화면이자 ROS 노드.
class UiNode : public QWidget, public rclcpp::Node
{
  Q_OBJECT

public:
  explicit UiNode(QWidget * parent = nullptr);
  ~UiNode() override;

private slots:
  // Qt 타이머가 호출하는 슬롯 -> Qt GUI 스레드(메인 스레드)에서 실행된다.
  void onDisplayTimer();

private:
  // ROS 구독 콜백 -> rclcpp::spin()이 도는 별도 스레드에서 실행된다 (구현 조건 1).
  void imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr & msg);

  QLabel * image_label_;
  QTimer * display_timer_;

  image_transport::Subscriber image_sub_;
  double display_rate_hz_;

  // ---- 구현 조건 2: 공유 이미지 데이터는 mutex로 보호 ----
  // imageCallback()은 ROS 스핀 스레드, onDisplayTimer()는 Qt GUI 스레드에서
  // 각각 실행되므로, 두 스레드가 공유하는 latest_frame_ 접근은 반드시 lock으로 감싼다.
  std::mutex frame_mutex_;
  cv::Mat latest_frame_;
  bool has_frame_{false};
};

}  // namespace camera_ui_pkg