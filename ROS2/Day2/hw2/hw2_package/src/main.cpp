#include "mainwindow.h"

#include <QApplication>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::cout << "ROS_DOMAIN_ID: "
              << (std::getenv("ROS_DOMAIN_ID") ?
                      std::getenv("ROS_DOMAIN_ID") : "없음")
              << std::endl;

    MainWindow w;
    w.show();
    return a.exec();
}
