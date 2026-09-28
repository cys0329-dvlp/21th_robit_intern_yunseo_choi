#include "pytorch_object_detection/infernce_node/inference_node.hpp"
#include <std_msgs/msg/header.hpp>
#include <cv_bridge/cv_bridge.hpp> 
//ROS2 이미지 형식과 OpenCV의 이미지 형식을 서로 변환해주는 다리 역할
//처음 카메라 이미지를 읽었을 때는 OpenCV 이미지임 -> 얘를 ROS2 이미지로 변환해서 ROS2의 다른 노드로 보내는 역할
#include <vector>
#include <openvino/openvino.hpp> //OpenVINO C++ API를 사용하기 위한 헤더
#include <algorithm>
#include <chrono>

cv::Mat InferenceNode::letterbox(
    const cv::Mat& image, 
    const cv::Size& target_size
)
{
    //가로와 세로 중 더 많이 줄여야하는 쪽의 비율을 선택하는 기능 -> 더 작은 쪽에 맞춰서 비율을 줄여야 원본이 파괴되지않기 때문
    double scale = std::min(
        static_cast<double>(target_size.width) / image.cols,
        static_cast<double>(target_size.height) / image.rows
    );

    //새로운 이미지 크기 계산(아직 padding은 진행 x)
    int new_width = static_cast<int>(image.cols * scale);
    int new_height = static_cast<int>(image.rows * scale);

    //새로 계산된 이미지 크기 저장
    cv::Mat resized;
    cv::resize(
        image, 
        resized, 
        cv::Size(new_width, new_height)
    );


    //목표 크기 - 새로 생긴 크기 -> 오차 계산해서 padding 추가
    int padding_width = target_size.width - new_width;
    int padding_height = target_size.height - new_height;

    //위, 아래, 좌우 padding 크기 계산
    int top = padding_height /2;
    int bottom = padding_height - top;
    int left = padding_width /2;
    int right = padding_width - left;

    cv::Mat output;

    //이미지 주변에 계산된 padding값들을 추가해주는 함수
    cv::copyMakeBorder(
        resized,
        output,
        top,
        bottom,
        left,
        right,
        cv::BORDER_CONSTANT,
        cv::Scalar(114,114,114) //114는 회색
    );
    
    return output;
}

InferenceNode::InferenceNode()
    : Node("inference_node")
{
    //ROS2에 target_classes 파라미터가 있다고 선언
    this->declare_parameter<std::vector<int>>(
        "target_classes",
        std::vector<int>{0}
    );

    //파라미터 값 가져와서 target_classes_에 저장함
    target_classes_= this->get_parameter(
        "target_classes"
    ).as_integer_array();

    this->declare_parameter<std::vector<std::string>>(
        "class_names",
        std::vector<std::string>{}
    );

    std::vector<std::string> class_names = this->get_parameter("class_names").as_string_array();

    for(const std::string& class_name:class_names)
    {
        size_t separator = class_name.find(':');

        if(separator == std::string::npos)
        {
            continue;
        }

        int class_id = std::stoi(class_name.substr(0, separator));

        std::string name = class_name.substr(separator + 1);

        class_names_[class_id] = name;
    }

    //OpenVINO가 읽을 .xml파일 경로 지정
    std::string model_path = "/home/choiyuns/ros2_ws/src/pytorch_object_detection/models/yolo26n.xml";
    
    std::shared_ptr<ov::Model> model = core_.read_model(model_path);

    compiled_model_ = core_.compile_model(model, "CPU");
    
    infer_request_ = compiled_model_.create_infer_request();

    //컴파일된 YOLO모델에서 입력 포트 가져옴
    auto input_port = compiled_model_.input();
    //입력 포트가 요구하는 Tensor 크기 가져옴
    auto input_shape = input_port.get_shape();

    RCLCPP_INFO(
        this->get_logger(),
        "Model input shape: %ld, %ld, %ld, %ld",
        input_shape[0],
        input_shape[1],
        input_shape[2],
        input_shape[3]
    );

    //모델 로드가 성공되면 문자열 출력
    RCLCPP_INFO(this->get_logger(), "YOLO26n OpenVINO model loaded");
    
    //카메라 크기 고정
    cv::namedWindow("Detection", cv::WINDOW_NORMAL);
    cv::resizeWindow("Detection", 960, 540);

    //subscriber 생성
    image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/camera/image_raw", //publisher와 동일한 토픽 subscribe
        10,
        [this](const sensor_msgs::msg::Image::SharedPtr msg)
        {
            //이미지 하나가 들어올 때마다 callback실행(callback: 특정 이벤트가 발생했을 때 ROS2에서 자동으로 실행되는 함수)
            //이미지 msg -> OpenCV 이미지 cv::Mat으로 변환해서 frame에 저장하는 기능
            cv::Mat frame = cv_bridge::toCvCopy(
                msg,
                "bgr8"
            ) -> image;

            cv::Mat rgb;
            /*
                YOLO 전처리: BGR->RGB 
                frame: 변환 전 BGR이미지
                rgb: 변환 후 RGB dlalwl
                cv::COLOR_BGR2RGB: BGR -> RGB 변환
            */
            cv::cvtColor(frame, rgb, cv::COLOR_BGR2RGB);

            cv::Mat letterboxed = letterbox(
                rgb, 
                cv::Size(640, 640) //실제 YOLO input shape
            );

            cv::Mat input_float;
            //픽셀의 자료형을 바꾸는 기능
            letterboxed.convertTo(
                input_float, 
                CV_32F,
                1.0/255.0 //픽셀값 정규화
            );

            std::vector<float> input_chw(
                3*input_float.rows * input_float.cols
            );

            //channel, height, width 세가지 차원이 있기 때문에 3중 for문으로 작성
            for(int c = 0; c<3; c++)
            {
                for(int h = 0; h<input_float.rows; h++)
                {
                    for(int w = 0; w<input_float.cols; w++)
                    {
                        //3차원 CHW 좌표를 1차원 배열 위치로 변환하는 공식
                        input_chw[c*input_float.rows * input_float.cols + h*input_float.cols + w]
                        = input_float.at<cv::Vec3f>(h,w)[c];
                    }
                }
            }

            //OpenVINO가 사용하는 Tensor 객체를 만듦
            ov::Tensor input_tensor(
                ov::element::f32,
                {1, 3, 640, 640}, //모델 입력 shape
                input_chw.data() //실제 데이터 메모리를 Tensor에 전달
            );

            //OpenVINO의 InferRequest에 입력으로 지정
            infer_request_.set_input_tensor(input_tensor);

            //infer 실행 직전 시간 저장
            auto start_time = std::chrono::high_resolution_clock::now();

            //지금까지 쌓아온 입력을 YOLO 모델에 넣어서 추론 실행
            infer_request_.infer();

            //inference 끝난 직후 시간 저장
            auto end_time = std::chrono::high_resolution_clock::now();

            double inference_time = std::chrono::duration<double, std::milli>(
                end_time - start_time
            ).count();


            //YOLO가 추론한 Tensor 가져옴
            ov::Tensor output_tensor = infer_request_.get_output_tensor();

            //출력 Tensor의 크기 확인
            auto output_shape = output_tensor.get_shape();


            //OpenVINO에서 출력 Tensor의 실제 float 데이터에 접근할 수 있는 포인터를 얻음
            const float* output_data = output_tensor.data<const float>();

            std::vector<cv::Rect> boxes; //bounding box 좌표 저장
            std::vector<float> scores; //confidence score 저장
            std::vector<int> class_ids; //객체 class ID 저장

            //8400개 후보 중 가장 높은 class score와 class ID를 찾는 기능
            for(int i = 0; i<8400; i++)
            {
                float max_score = 0.0;
                int class_id = -1;

                for(int c= 0; c<80; c++)
                {
                    float score = output_data[(4+c)*8400 + i];

                    if(score>max_score)
                    {
                        max_score = score;
                        class_id = c;
                    }
                }

                if(max_score >0.3 && std::find(target_classes_.begin(), target_classes_.end(), class_id) != target_classes_.end())
                {
                    float x = output_data[0 * 8400 + i];
                    float y = output_data[1 * 8400 + i];
                    float w = output_data[2 * 8400 + i];
                    float h = output_data[3 * 8400 + i];

                    boxes.emplace_back(
                        static_cast<int>(x-w/2),
                        static_cast<int>(y-h/2),
                        static_cast<int>(w),
                        static_cast<int>(h)
                    );

                    scores.push_back(max_score);
                    class_ids.push_back(class_id);
                }
            }

            std::vector<int> indices;

            for(int class_id : target_classes_)
            {
                std::vector<cv::Rect> class_boxes;
                std::vector<float> class_scores;
                std::vector<int> class_indices;

                for(int i = 0; i<static_cast<int>(class_ids.size()); i++)
                {
                    if(class_ids[i] == class_id)
                    {
                        class_boxes.push_back(boxes[i]);
                        class_scores.push_back(scores[i]);
                        class_indices.push_back(i);
                    }
                }

                std::vector<int> nms_indices;

                cv::dnn::NMSBoxes(
                    class_boxes,
                    class_scores,
                    0.5,
                    0.45,
                    nms_indices
                );

                for(int index : nms_indices)
                {
                    indices.push_back(class_indices[index]);
                }
            }
           

            double scale = std::min(
                640.0 / frame.cols,
                640.0 / frame.rows
            );

            int new_width = static_cast<int>(frame.cols*scale);
            int new_height = static_cast<int>(frame.rows*scale);

            int padding_width = 640 - new_width;
            int padding_height = 640 - new_height;

            int left = padding_width / 2;
            int top = padding_height / 2;

            for(int index:indices)
            {
                cv::Rect box = boxes[index];

                int x = static_cast<int>((box.x - left) / scale);
                int y = static_cast<int>((box.y - top) / scale);
                int width = static_cast<int>(box.width / scale);
                int height = static_cast<int>(box.height / scale);

                //원본 frame에 사각형 그림
                cv::rectangle(
                    frame,
                    cv::Rect(x,y,width, height),
                    cv::Scalar(0,255,0),
                    2
                );

                std::string label = "ID "+ std::to_string(class_ids[index])+" "+ class_names_[class_ids[index]] + " " + std::to_string(scores[index]).substr(0,4);

                //ID와 score를 박스 위에 표시
                cv::putText(
                    frame,
                    label,
                    cv::Point(x,y -5),
                    cv::FONT_HERSHEY_SIMPLEX,
                    0.5,
                    cv::Scalar(0,255,0),
                    1
                );
            }

            cv::putText(
                frame,
                "Latency: " + std::to_string(inference_time).substr(0, 5) + " ms",
                cv::Point(20, 40),
                cv::FONT_HERSHEY_SIMPLEX,
                0.8,
                cv::Scalar(0, 255, 0),
                2
            );
        
            //화면 출력
            cv::imshow("Detection", frame);
            cv::waitKey(1);
        }
    );
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<InferenceNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}