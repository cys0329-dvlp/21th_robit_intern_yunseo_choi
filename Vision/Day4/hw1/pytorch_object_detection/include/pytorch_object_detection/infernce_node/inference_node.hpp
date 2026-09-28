#ifndef PYTORCH_OBJECT_DETECTION_INFERENCE_NODE_HPP
#define PYTORCH_OBJECT_DETECTION_INFERENCE_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <openvino/openvino.hpp>
#include <cstdint>
#include <map>
#include <vector>

class InferenceNode : public rclcpp::Node
{
    public:
        InferenceNode();

    private:
        // 
        cv::Mat letterbox(
            const cv::Mat& image, //원본 RGB 이미지
            const cv::Size& targer_size //모델 입력 크
        );

        std::vector<int64_t> target_classes_;

        //class이름 저장할 변수 
        std::map<int, std::string> class_names_;

        //OpenVINO의 모델을 읽고 실행할 장치를 준비하는 시점
        ov::Core core_;

        //읽어온 모델 컴파일
        ov::CompiledModel compiled_model_;

        //실제 추론 요청 단계
        ov::InferRequest infer_request_;
        
        //subscriber 생성 
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;


};

#endif