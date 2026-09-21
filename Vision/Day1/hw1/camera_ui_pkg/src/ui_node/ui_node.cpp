#include "camera_ui_pkg/ui_node/ui_node.hpp"

#include <cv_bridge/cv_bridge.hpp>

#include <QVBoxLayout>
#include <QPixmap>
#include <QApplication>

#include <thread>

namespace camera_ui_pkg
{

UiNode::UiNode(QWidget * parent)
: QWidget(parent),
  Node("ui_node")
{
  display_rate_hz_ = this->declare_parameter<double>("display_rate_hz", 30.0);

  //Qt UI 구성
  setWindowTitle("camera_ui (Qt)");
  image_label_ = new QLabel(this);
  image_label_->setAlignment(Qt::AlignCenter);
  image_label_->setMinimumSize(640, 480);
  image_label_->setText("영상 수신 대기 중...");

  auto * layout = new QVBoxLayout(this);
  layout->addWidget(image_label_);
  setLayout(layout);

  //ROS publish
  image_sub_ = image_transport::create_subscription(
    this, "image_raw",
    std::bind(&UiNode::imageCallback, this, std::placeholders::_1),
    "raw");

  //Qt 타이머로 화면 주기 갱신
  display_timer_ = new QTimer(this);
  connect(display_timer_, &QTimer::timeout, this, &UiNode::onDisplayTimer);
  display_timer_->start(static_cast<int>(1000.0 / display_rate_hz_));

  RCLCPP_INFO(
    this->get_logger(), "ui_node(Qt) 시작 (rate=%.1fHz, subscribe=image_raw)",
    display_rate_hz_);
}

UiNode::~UiNode() = default;

void UiNode::imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr & msg)
{
  // 콜백의 처리는 콜백 함수 안에서 완료
  // 이 함수는 rclcpp::spin()이 도는 ROS 스레드에서 호출된다.
  cv_bridge::CvImageConstPtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvShare(msg, "bgr8");
  } catch (const cv_bridge::Exception & e) {
    RCLCPP_ERROR(this->get_logger(), "cv_bridge 변환 실패: %s", e.what());
    return;
  }

  // 공유 이미지 데이터는 mutex로 보호
  std::lock_guard<std::mutex> lock(frame_mutex_);
  latest_frame_ = cv_ptr->image.clone();
  has_frame_ = true;
}

void UiNode::onDisplayTimer()
{
  // 이 함수는 Qt GUI 스레드에서 호출
  cv::Mat frame;
  {
    std::lock_guard<std::mutex> lock(frame_mutex_);
    if (!has_frame_) {
      return;
    }
    frame = latest_frame_.clone();  // lock을 짧게 쥐기 위해 복사만 하고 즉시 해제
  }

  // OpenCV는 BGR, Qt QImage는 RGB 순서를 기대하므로 변환 필요
  cv::Mat rgb;
  cv::cvtColor(frame, rgb, cv::COLOR_BGR2RGB);

  QImage qimg(
    rgb.data, rgb.cols, rgb.rows,
    static_cast<int>(rgb.step), QImage::Format_RGB888);

  // qimg는 rgb의 메모리를 그대로 참조하므로, rgb가 스코프를 벗어나기 전에
  // .copy()로 깊은 복사를 떠서 QPixmap에 넘김
  image_label_->setPixmap(
    QPixmap::fromImage(qimg.copy())
      .scaled(image_label_->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

}  // namespace camera_ui_pkg

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  QApplication app(argc, argv);

  auto node = std::make_shared<camera_ui_pkg::UiNode>();
  node->resize(680, 560);
  node->show();

  // rclcpp::spin()은 블로킹 호출이라 Qt 이벤트 루프와 분리된 스레드에서 돌림
  std::thread ros_thread([&node]() {
    rclcpp::spin(node);
  });

  const int result = app.exec();  // Qt 이벤트 루프

  rclcpp::shutdown();  // spin()을 블로킹에서 풀어줌
  ros_thread.join();

  return result;
}