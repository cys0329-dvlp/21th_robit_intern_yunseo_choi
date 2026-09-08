#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QElapsedTimer>

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

    void udp_read();

    QUdpSocket *text_socket = new QUdpSocket(this);
    ~MainWindow();

private slots:

    void flashButton(QObject *obj);

    void on_sendBtn_clicked();

    void on_abc_clicked();
    void on_def_clicked();
    void on_EK_clicked();
    void on_KE_clicked();
    void on_SC_clicked();
    void on_CS_clicked();
    void on_EK_2_clicked();

    void on_ghi_clicked();

    void on_jkl_clicked();

    void on_mno_clicked();

    void on_pqrs_clicked();

    void on_tuv_clicked();

    void on_wxyz_clicked();

    void on_ABC_clicked();

    void on_DEF_clicked();

    void on_GHI_clicked();

    void on_JKL_clicked();

    void on_MNO_clicked();

    void on_PQRS_clicked();

    void on_TUV_clicked();

    void on_WXYZ_clicked();

    void on_space_clicked();

    void on_SPACE_clicked();

    void on_enter_clicked();

    void on_ENTER_clicked();

    void on_comma_clicked();

    void on_COMMA_clicked();

    void on_EXT_clicked();

    void on_ext_clicked();

    void on_l_clicked();

    void on_dot_clicked();

    void on_m_clicked();

    void on_k_enter_clicked();

    void on_rz_clicked();

    void on_sf_clicked();

    void on_ex_clicked();

    void on_wc_clicked();

    void on_tg_clicked();

    void on_qv_clicked();

    void on_da_clicked();

    void on_k_space_clicked();

    void on_k_Del_clicked();

    void on_DEL_clicked();

    void on_del_clicked();


private:
    Ui::MainWindow *ui;
    QHostAddress ROBIT_IP = QHostAddress("172.100.4.158");
    QHostAddress ROBOT_IP = QHostAddress("172.100.7.122");

    uint16_t TEXT_PORT = 10004;

    int abc_count = 0;
    int ABC_count = 0;
    int def_count = 0;
    int DEF_count = 0;
    int ghi_count = 0;
    int GHI_count = 0;
    int jkl_count = 0;
    int JKL_count = 0;
    int mno_count = 0;
    int MNO_count = 0;
    int pqrs_count = 0;
    int PQRS_count = 0;
    int tuv_count = 0;
    int TUV_count = 0;
    int wxyz_count = 0;
    int WXYZ_count = 0;
    int COMMA_count = 0;
    int EXT_count = 0;
    int ext_count = 0;
    int rz_count = 0;
    int sf_count = 0;
    int ex_count = 0;
    int wc_count = 0;
    int tg_count = 0;
    int qv_count = 0;
    int da_count = 0;

    QString confirmed_text = ""; // [보관함 A] 완전히 확정되어 누적된 전체 텍스트
    QString current_char = "";   // [보관함 B] 현재 버튼을 연타하며 바뀌는 중인 한 글자

    QString current_vowel;

    // 직전에 누른 버튼을 기억 (0: 없음, 1: abc 버튼, 2: def 버튼)
    int last_button = 0;

    // --- 시간 제한을 위한 변수 추가 ---
    QElapsedTimer timer;         // 시간을 측정하는 시계
    const int TIMEOUT_MS = 800;  // 같은 글자 연타 인정 시간 (0.8초)

    // 자음과 모음을 합쳐주는 유니코드 결합 함수
    QString combineHangeul(QString ch, QString vo);
    // 모든 자음 카운트를 일괄 초기화해주는 함수
    void clearAllCounts();

};


#endif // MAINWINDOW_H
