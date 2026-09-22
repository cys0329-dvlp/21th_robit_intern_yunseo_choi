#include "CalDist_pkg/UI/mainwindow.hpp"
#include "ui_mainwindow.h"
#include "CalDist_pkg/Subscriber/image_subscriber.hpp"

#include <QPixmap>
#include <QProcess>
#include <QDebug>
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(
    ImageSubscriber::SharedPtr image_subscriber,
    QWidget *parent
)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      image_subscriber_(image_subscriber),
      camera_process_(nullptr)
{
    ui->setupUi(this); // 실행하면 QT designer에서 만든 버튼, QLabel 등이 QT window 에서 출력됨
    camera_process_ = new QProcess(this);


    connect(
        ui->pushButton_stop,
        &QPushButton::clicked,
        this,
        &MainWindow::on_pushButton_stop_clicked
    );

}

//Publish Start 버튼 누르면 ROS2 카메라 노드 실행
void MainWindow::on_pushButton_publishStart_clicked()
{
    if (camera_process_->state() != QProcess::NotRunning)
    {
        qDebug() << "Camera process is already running";
        return;
    }

    camera_process_->start("ros2",QStringList()<< "launch"<< "insta360_usb_cam"<< "usb_cam.launch.py");

}

//Subscribe Start 버튼 누르면 카메라 frame 읽어오기 시작
void MainWindow::on_pushButton_subscribeStart_clicked()
{
    if (!image_subscriber_)
    {
        return;
    }

    image_subscriber_->startSubscription();
}

//Stop 버튼 누르면 카메라 종료
void MainWindow::on_pushButton_stop_clicked()
{
    //카메라 frame 구독 중지
    if (image_subscriber_)
    {
        image_subscriber_->stopSubscription();
    }

    //ROS2 카메라 노드 종료
    if (camera_process_->state() != QProcess::NotRunning)
    {
        camera_process_->terminate();

        if (!camera_process_->waitForFinished(3000))
        {
            camera_process_->kill();
        }
    }

    qDebug() << "Camera stopped";
}

//DistanceA 값들 QT UI에 업데이트
void MainWindow::updateDistanceAValues(
    double REAL_ball_size,
    double camera_ball_size,
    double Distance,
    double fx
)
{
    //label마다 변수 연결해주기
    ui->label_REAL_ball_size->setText(QString::number(REAL_ball_size));

    ui->label_camera_ball_size->setText(QString::number(camera_ball_size));

    ui->label_Distance->setText(QString::number(Distance));

    ui->label_fx->setText(QString::number(fx));
}

//DistanceB 값들 QT UI에 업데이트
void MainWindow::updateDistanceBValues(
    double h,
    double theta,
    double Distance
)
{
    //label마다 변수 연결해주기 
    ui->label_methodB_height->setText(QString::number(h));

    ui->label_methodB_theta->setText(QString::number(theta));

    ui->label_methodB_distance->setText(QString::number(Distance));
}

//QT UI에 opencv 화면 띄우는 함수
void MainWindow::updateCameraImage(const cv::Mat &frame)
{
    if (frame.empty())
    {
        return;
    }

    cv::Mat rgb_frame;

    cv::cvtColor(frame,rgb_frame,cv::COLOR_BGR2RGB);

    QImage image(rgb_frame.data,rgb_frame.cols,rgb_frame.rows,rgb_frame.step,QImage::Format_RGB888);

    ui->label_camera->setPixmap(
        QPixmap::fromImage(image.copy()).scaled(
            ui->label_camera->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        )
    );
}

//소멸자
MainWindow::~MainWindow()
{
    delete ui; 
}

//mainwindow.cpp는 그냥 UI표시만 담당