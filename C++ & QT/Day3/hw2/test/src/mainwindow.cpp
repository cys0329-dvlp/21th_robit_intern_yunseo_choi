#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->radioButton,   &QRadioButton::toggled, this, &MainWindow::onModeChanged);
    connect(ui->radioButton_2, &QRadioButton::toggled, this, &MainWindow::onModeChanged);
    connect(ui->radioButton_3, &QRadioButton::toggled, this, &MainWindow::onModeChanged);

    ui->radioButton->setChecked(true); // 기본 모드: Map Setting
    onModeChanged();                  // 시작할 때 화면도 맞춰주기
}

void MainWindow::onModeChanged()
{
    if (ui->radioButton->isChecked()) {
        ui->stackedWidget->setCurrentIndex(0); // Map Setting
    } else if (ui->radioButton_2->isChecked()) {
        ui->stackedWidget->setCurrentIndex(1); // Path Search
    } else if (ui->radioButton_3->isChecked()) {
        ui->stackedWidget->setCurrentIndex(2); // Map Editing
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
        int rows = 10;
        int cols = 10;

        if (ui->radioButton_5->isChecked()) {        // 소
            rows = 20; cols = 20;
            ui->textBrowser->setText("20px 생성됨");
        } else if (ui->radioButton_6->isChecked()) { // 중
            rows = 40; cols = 40;
            ui->textBrowser->setText("40px 생성됨");
        } else if (ui->radioButton_7->isChecked()) { // 대
            rows = 60; cols = 60;
            ui->textBrowser->setText("60px 생성됨");
        }

}

