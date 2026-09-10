#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "talker_node.hpp"
#include "listener_node.hpp"
#include <rclcpp/rclcpp.hpp>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // talker/listener 노드 분리
    std::shared_ptr<TalkerNode> talker_node_;
    std::shared_ptr<ListenerNode> listener_node_;

    // 두 노드를 함께 spin 하기 위한 executor
    rclcpp::executors::SingleThreadedExecutor executor_;

    QTimer *ros_timer_;
};
#endif // MAINWINDOW_H
