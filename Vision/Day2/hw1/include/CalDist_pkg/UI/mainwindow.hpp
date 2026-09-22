#ifndef CALDIST_PKG_MAINWINDOW_HPP
#define CALDIST_PKG_MAINWINDOW_HPP

#include <QMainWindow>

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

private:

    Ui::MainWindow *ui;  //QT designer에서 만든 UI 객체를 가리킴

    ImageSubscriber::SharedPtr image_subscriber_;
};

#endif