#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ---- ROS2 + 버튼 연결 ----

    // 1) talker/listener 노드 각각 생성
    // (rclcpp::init()은 main.cpp에서 MainWindow 생성 전에 이미 호출됨)
    talker_node_ = std::make_shared<TalkerNode>();
    listener_node_ = std::make_shared<ListenerNode>();

    // 두 노드를 하나의 executor에 등록 (같은 프로세스 안에서 함께 spin)
    executor_.add_node(talker_node_);
    executor_.add_node(listener_node_);

    // 2) Publish 버튼 클릭 -> QLineEdit의 텍스트를 가져와 TalkerNode가 퍼블리시
    connect(
        ui->pushButton_publish, &QPushButton::clicked,
        this, [this]() {
            const QString text = ui->lineEdit_input->text();
            if (text.isEmpty()) {
                return;
            }
            talker_node_->onPublishButtonClicked(text);
        });

    // 3) ListenerNode가 메시지를 구독(수신)하면 -> 라벨 텍스트 갱신
    connect(
        listener_node_.get(),
        &ListenerNode::messageReceived,
        this,
        [this](QString msg) {

            std::cout << "Signal 수신: " << msg.toStdString() << std::endl;

            ui->label_received->setText(
                QString("수신 메시지 : %1").arg(msg));
        });

    // 4) ROS2 콜백(퍼블리시/서브스크라이브 처리)을 주기적으로 처리
    ros_timer_ = new QTimer(this);
    connect(
        ros_timer_, &QTimer::timeout, this, [this]() {
            executor_.spin_some();
        });
    ros_timer_->start(10);  // 10ms마다 처리


}

MainWindow::~MainWindow()
{
    // ---- ROS2 종료 정리 ----
    // rclcpp::shutdown()은 main.cpp에서 a.exec() 이후에 호출됨
    executor_.remove_node(talker_node_);
    executor_.remove_node(listener_node_);

    delete ui;
}
