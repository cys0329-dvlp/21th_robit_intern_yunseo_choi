#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ---- ROS2 + 버튼 연결 ----

    // 1) ROS2 초기화 및 노드 생성
    rclcpp::init(0, nullptr);
    turtle_shape_ = std::make_shared<TurtleShape>();

    // 2) 버튼 클릭 -> TurtleShape 슬롯 연결
    //    W : 사각형, S : 삼각형, A : 원, D : 종료
    connect(
        ui->pushButton_W, &QPushButton::clicked,
        turtle_shape_.get(), &TurtleShape::onSquareButtonClicked);

    connect(
        ui->pushButton_S, &QPushButton::clicked,
        turtle_shape_.get(), &TurtleShape::onTriangleButtonClicked);

    connect(
        ui->pushButton_A, &QPushButton::clicked,
        turtle_shape_.get(), &TurtleShape::onCircleButtonClicked);

    connect(
        ui->pushButton_D, &QPushButton::clicked,
        this, &QWidget::close);

    connect(
        turtle_shape_.get(),
        &TurtleShape::cmdVelChanged,
        this,
        [this](double linear_x, double angular_z) {

            std::cout << "Signal 수신: "
                      << linear_x << ", "
                      << angular_z << std::endl;

            ui->linearLabel->setText(
                QString("Linear X : %1").arg(linear_x, 0, 'f', 2));

            ui->angularLabel->setText(
                QString("Angular Z : %1").arg(angular_z, 0, 'f', 2));
        });

    // 3) ROS2 콜백(타이머 기반 도형 그리기)을 주기적으로 처리
    ros_timer_ = new QTimer(this);
    connect(
        ros_timer_, &QTimer::timeout, this, [this]() {
            rclcpp::spin_some(turtle_shape_);
        });
    ros_timer_->start(10);  // 10ms마다 처리

    // ---- 추가된 부분 끝 ----
}

MainWindow::~MainWindow()
{
    // ---- ROS2 종료 정리 ----
    rclcpp::shutdown();

    delete ui;
}
