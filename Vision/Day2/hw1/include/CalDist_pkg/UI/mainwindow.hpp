#ifndef CALDIST_PKG_MAINWINDOW_HPP
#define CALDIST_PKG_MAINWINDOW_HPP

#include <QMainWindow>
#include <QImage>
#include <QProcess>
#include "CalDist_pkg/Subscriber/image_subscriber.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // signal, slot을 사용하기 위한 매크로

public:
    explicit MainWindow(
        ImageSubscriber::SharedPtr image_subscriber,
        QWidget *parent = nullptr
    );

    
    ~MainWindow();

    void updateDistanceAValues(
        double REAL_ball_size,
        double camera_ball_size,
        double Distance,
        double fx
    );

    void updateDistanceBValues(
        double h,
        double theta,
        double Distance
    );

    //QT UI에 OpenCV 카메라 화면 띄우는 함수
    void updateCameraImage(const cv::Mat &frame);

private slots:

    void on_pushButton_publishStart_clicked();

    void on_pushButton_subscribeStart_clicked();

    void on_pushButton_stop_clicked();
    
private:

    Ui::MainWindow *ui;  //QT designer에서 만든 UI 객체를 가리킴

    ImageSubscriber::SharedPtr image_subscriber_;

    QProcess *camera_process_;
};

#endif