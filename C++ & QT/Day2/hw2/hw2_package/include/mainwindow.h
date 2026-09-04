#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQueue>
#include <QString>
#include <QLineEdit>
#include <vector>

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

private slots:
    void on_pushButton_4_clicked();  // 입력창 추가 버튼
    void on_pushButton_3_clicked();    // 등록 버튼
    void on_pushButton_2_clicked();  // 완료 버튼

private:
    Ui::MainWindow *ui;
    QQueue<QString> todoQueue;
    std::vector<QLineEdit*> inputBoxes;

    void updateDisplay();
    void clearInputBoxes();
};

#endif // MAINWINDOW_H
