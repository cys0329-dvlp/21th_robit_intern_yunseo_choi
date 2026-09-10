#include "mainwindow.h"

#include <QApplication>
#include <cstdlib>
#include <iostream>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::cout << "ROS_DOMAIN_ID: "
              << (std::getenv("ROS_DOMAIN_ID") ?
                      std::getenv("ROS_DOMAIN_ID") : "없음")
              << std::endl;

    rclcpp::init(argc, argv);

    MainWindow w;
    w.show();
    int ret = a.exec();

    rclcpp::shutdown();
    return ret;
}
