#include "CalDist_pkg/UI/mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(
    ImageSubscriber::SharedPtr image_subscriber,
    QWidget *parent
)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      image_subscriber_(image_subscriber)
{
    ui->setupUi(this); // 실행하면 QT designer에서 만든 버튼, QLabel 등이 QT window 에서 출력됨
}

MainWindow::~MainWindow()
{
    delete ui; 
}

//mainwindow.cpp는 그냥 UI표시만 담당