#include <QApplication>
#include <QTimer>

#include <QApplication>

#include <opencv2/opencv.hpp>

#include <rclcpp/rclcpp.hpp>

#include "CalDist_pkg//UI/mainwindow.hpp"
#include "CalDist_pkg/Subscriber/image_subscriber.hpp"

#include "CalDist_pkg/Distance/define_yellow_ball.hpp"

//subscriber 생성
ImageSubscriber::SharedPtr image_subscriber;

DefineYellowBall yellow_ball_detector;

//타이머가 spin을 실행하도록 설정 -> rosSpin에서 ROS 처리
void rosSpin()
{
    rclcpp::spin_some(image_subscriber);

    //.clone()추가 -> getFrame()의 원본은 const로 반환 
    cv::Mat frame = image_subscriber->getFrame().clone();

    if (!frame.empty())
    {
        yellow_ball_detector.detect(frame);

        cv::imshow("Camera", frame);
        cv::waitKey(1);
    }

}


int main(int argc, char *argv[]) //프로그램의 시작점
{
    rclcpp::init(argc, argv); //ROS2 사용하기 위한 초기화

    QApplication app(argc, argv); //QT 프로그램 사용하기 위한 객체

    //ImageSubscriber 생성
    image_subscriber = std::make_shared<ImageSubscriber>();

    //mainwindow.ui에서 디자인한 화면을 띄움
    MainWindow window(image_subscriber);
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