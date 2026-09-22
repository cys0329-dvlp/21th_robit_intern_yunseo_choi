#include <QApplication>
#include <QTimer>

#include <QApplication>

#include <opencv2/opencv.hpp>

#include <rclcpp/rclcpp.hpp>

#include "CalDist_pkg//UI/mainwindow.hpp"
#include "CalDist_pkg/Subscriber/image_subscriber.hpp"

#include "CalDist_pkg/Distance/define_yellow_ball.hpp"
#include "CalDist_pkg/Distance/distance_calculator.hpp"

//subscriber 생성
ImageSubscriber::SharedPtr image_subscriber;

DefineYellowBall yellow_ball_detector;

DistanceCalculator distance_calculator;

MainWindow *main_window;

//타이머가 spin을 실행하도록 설정 -> rosSpin에서 ROS 처리
void rosSpin()
{
    rclcpp::spin_some(image_subscriber);

    //.clone()추가 -> getFrame()의 원본은 const로 반환 
    cv::Mat frame = image_subscriber->getFrame().clone();

    if (frame.empty()) //프레임 안받아와질 때 예외처리
    {
        return;
    }

    
    YellowBallResult ball = yellow_ball_detector.detect(frame);

    double REAL_ball_size = 5.9;

    // 카메라 캘리브레이션 값(insta360 패키지 참고)
    double fx = 471.953641;
    double fy = 476.574144;
    double cx = 309.509126;
    double cy = 228.222101;

    //A방법 변수 
    double camera_ball_size = 0.0;
    double Distance_A = 0.0;
        
    if (ball.detected)
    {
        camera_ball_size = ball.radius * 2.0;

        Distance_A = distance_calculator.calculateDistanceA(REAL_ball_size,camera_ball_size,fx);
    }

    //B방법 변수
    double h = 12.9;
    double theta = 23.3; // 세타를 처음엔 60도라고 설정하고 30cm 거리에 공 두고 거리 측정 -> 30cm와 카메라 상에서 측정된 거리 오차 기반으로 각도 설정 
    double Distance_B = 0.0;
    double total_angle_deg = theta; 

    //공 감지됐을 때 거리 측정 로직 구현 
    if (ball.detected)
    {
        double v = ball.center.y;

        double yn = (v - cy) / fy;

        Distance_B = distance_calculator.calculateDistanceB(h,theta,v,fy,cy);
    }

    //QT UI에 A,B 값들 계속 업데이트 
    main_window->updateDistanceAValues(
        REAL_ball_size,
        camera_ball_size,
        Distance_A,
        fx
    );

    main_window->updateDistanceBValues(
        h,
        theta,
        Distance_B
    );

    main_window->updateCameraImage(frame);
}


int main(int argc, char *argv[]) //프로그램의 시작점
{
    rclcpp::init(argc, argv); //ROS2 사용하기 위한 초기화

    QApplication app(argc, argv); //QT 프로그램 사용하기 위한 객체

    //ImageSubscriber 생성
    image_subscriber = std::make_shared<ImageSubscriber>();

    //mainwindow.ui에서 디자인한 화면을 띄움
    MainWindow window(image_subscriber);

    main_window = &window;

    window.show();

    QTimer ros_timer; // QT에서 주기적으로 특정 작업 실행하는 타이머

    //QT 이벤트 루프가 돌아가는 동안 ROS2의 subscriber 콜백도 주기적으로 실행시키는 역할
    //ros_timer의 timeout이 발생하면 이 코드를 실행하라는 의미 
    QObject::connect(
        &ros_timer,
        &QTimer::timeout,
        rosSpin
    );

    ros_timer.start(10); //10ms마다 timeout 신호 발생됨

    int result = app.exec(); //QT 이벤트 루프 실행 -> 버튼 클릭이나 화면 갱신 처리

    cv::destroyAllWindows();

    rclcpp::shutdown();

    return result;
}

//main.cpp는 프로그램 시작 담당 + ROS2 노드 실행 담당