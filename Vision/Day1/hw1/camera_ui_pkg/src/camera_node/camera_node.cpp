#include "camera_ui_pkg/camera_node/camera_node.hpp"
#include <algorithm>
#include <cctype>
#include <cv_bridge/cv_bridge.hpp>
#include <std_msgs/msg/header.hpp>

namespace camera_ui_pkg
{

CameraNode::CameraNode(const rclcpp::NodeOptions & options): Node("camera_node", options)
{
  // config/camera_ui.yaml 에서 오버라이드되는 파라미터들.
  // 여기 선언된 기본값은 yaml이 없어도 노드가 단독 실행되도록 하기 위한 안전값.
  camera_source_ = this->declare_parameter<std::string>("camera_source", "0");
  use_synthetic_ = this->declare_parameter<bool>("use_synthetic", true);
  frame_width_ = this->declare_parameter<int>("frame_width", 640);
  frame_height_ = this->declare_parameter<int>("frame_height", 480);
  publish_rate_hz_ = this->declare_parameter<double>("publish_rate_hz", 30.0);

  if (!use_synthetic_)
  {
    if (!openCaptureSource()) 
    {
      RCLCPP_WARN(this->get_logger(),
        "실제 카메라(%s)를 열지 못했습니다. 합성 영상 모드로 대체합니다.",
        camera_source_.c_str());
      use_synthetic_ = true;
    }
  }

  // image_transport 발행자. shared_from_this() 없이 raw pointer 오버로드 사용
  // (생성자 안에서 shared_from_this()를 쓰면 정의되지 않은 동작이 될 수 있음).
  image_pub_ = image_transport::create_publisher(this, "image_raw");

  const auto period = std::chrono::duration<double>(1.0 / publish_rate_hz_);
  timer_ = this->create_wall_timer(
    std::chrono::duration_cast<std::chrono::milliseconds>(period),
    std::bind(&CameraNode::timerCallback, this));

  RCLCPP_INFO(
    this->get_logger(),
    "camera_node 시작 (mode=%s, topic=image_raw, rate=%.1fHz)",
    use_synthetic_ ? "synthetic" : "real-camera",
    publish_rate_hz_);
}

CameraNode::~CameraNode()
{
  if (cap_.isOpened()) {
    cap_.release();
  }
}

bool CameraNode::openCaptureSource()
{
  // camera_source_가 숫자만으로 되어 있으면 장치 인덱스로, 아니면 파일 경로로 취급.
  const bool is_index =
    !camera_source_.empty() &&
    std::all_of(
      camera_source_.begin(), camera_source_.end(),
      [](unsigned char c) { return std::isdigit(c); });

  if (is_index) {
    cap_.open(std::stoi(camera_source_), cv::CAP_V4L2);
  } else {
    cap_.open(camera_source_);
  }

  if (cap_.isOpened()) {
    // 이 장치(ipu6 / v4l2loopback)는 YUYV 1920x1080 30fps 단일 포맷만 지원하므로
    // FOURCC를 먼저 명시적으로 고정한 뒤 해상도를 설정한다.
    cap_.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y', 'U', 'Y', 'V'));
    cap_.set(cv::CAP_PROP_FRAME_WIDTH, frame_width_);
    cap_.set(cv::CAP_PROP_FRAME_HEIGHT, frame_height_);

    // 요청한 해상도가 실제로 적용됐는지 확인 (장치가 지원 안 하면 다른 값으로 되돌아감)
    const int actual_w = static_cast<int>(cap_.get(cv::CAP_PROP_FRAME_WIDTH));
    const int actual_h = static_cast<int>(cap_.get(cv::CAP_PROP_FRAME_HEIGHT));
    if (actual_w != frame_width_ || actual_h != frame_height_) {
      RCLCPP_WARN(
        this->get_logger(),
        "요청 해상도(%dx%d)가 아니라 장치가 지원하는 %dx%d로 열렸습니다.",
        frame_width_, frame_height_, actual_w, actual_h);
      frame_width_ = actual_w;
      frame_height_ = actual_h;
    }
  }

  return cap_.isOpened();
}

cv::Mat CameraNode::generateSyntheticFrame()
{
  cv::Mat frame(frame_height_, frame_width_, CV_8UC3, cv::Scalar(30, 30, 30));

  synthetic_frame_count_++;

  // 움직이는 원 + 프레임 번호 -> 실카메라 없이도 UI 노드에서 "영상이 갱신되고 있음"을 눈으로 확인 가능
  const int x = (synthetic_frame_count_ * 4) % std::max(frame_width_, 1);
  cv::circle(frame, cv::Point(x, frame_height_ / 2), 20, cv::Scalar(0, 0, 255), -1);

  cv::putText(
    frame, "SYNTHETIC FRAME #" + std::to_string(synthetic_frame_count_),
    cv::Point(20, 40), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(255, 255, 255), 2);

  return frame;
}

void CameraNode::timerCallback()
{
  // ---- 구현 조건 1: 콜백의 처리는 콜백 함수 안에서 완료 ----
  // 캡처 -> cv_bridge 변환 -> 퍼블리시까지 전부 이 함수 안에서 끝낸다.
  cv::Mat frame;

  if (use_synthetic_) {
    frame = generateSyntheticFrame();
  } else {
    if (!cap_.read(frame) || frame.empty()) {
      RCLCPP_WARN(this->get_logger(), "프레임을 읽지 못했습니다.");
      return;
    }
  }

  std_msgs::msg::Header header;
  header.stamp = this->now();
  header.frame_id = "camera_frame";

  const auto msg = cv_bridge::CvImage(header, "bgr8", frame).toImageMsg();
  image_pub_.publish(msg);
}

}  // namespace camera_ui_pkg

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<camera_ui_pkg::CameraNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}