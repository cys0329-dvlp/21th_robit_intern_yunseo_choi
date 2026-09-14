#include <QApplication>
#include <QTimer>
#include <rclcpp/rclcpp.hpp>

#include "qt_project/gui_monitor_node.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rclcpp::init(argc, argv);

    auto node = std::make_shared<GuiMonitorNode>();

    node->show();

    QTimer timer;

    QObject::connect(
        &timer,
        &QTimer::timeout,
        [&]()
        {
            rclcpp::spin_some(node);
        }
    );

    timer.start(10);

    int result = app.exec();

    rclcpp::shutdown();

    return result;
}