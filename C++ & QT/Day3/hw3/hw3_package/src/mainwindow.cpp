#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <QChar>
#include <QStringList>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.start(); // 프로그램 시작 시 타이머 초기화 구동
}

MainWindow::~MainWindow()
{
    delete ui;
}


// [핵심] 자음과 모음을 수학적으로 계산해 1글자로 조립하는 함수
QString MainWindow::combineHangeul(QString ch, QString vo)
{
    if (ch.isEmpty() || vo.isEmpty()) return ch + vo;

    // 유니코드 표준 자음/모음 배치 순서 명단
    QStringList choList = { "ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ" };
    QStringList jungList = { "ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ" };

    int choIdx = choList.indexOf(ch);
    int jungIdx = jungList.indexOf(vo);

    // 명단에 없는 특수문자나 영어가 섞여있다면 결합하지 않고 단순 나열
    if (choIdx == -1 || jungIdx == -1) return ch + vo;

    // 한글 유니코드 공식 (초성번호 * 588 + 중성번호 * 28)
    int hangeulCode = 44032 + (choIdx * 588) + (jungIdx * 28);
    return QString(QChar(hangeulCode));
}

// 모든 연타 카운터를 한 번에 비워주는 청소 함수
void MainWindow::clearAllCounts()
{
    abc_count = 0; def_count = 0; ghi_count = 0; jkl_count = 0; mno_count = 0;
    pqrs_count = 0; tuv_count = 0; wxyz_count = 0; ABC_count = 0; DEF_count = 0;
    GHI_count = 0; JKL_count = 0; MNO_count = 0; PQRS_count = 0; TUV_count = 0;
    WXYZ_count = 0; EXT_count = 0; ext_count = 0; COMMA_count = 0;
}

void MainWindow::on_abc_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 1 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;                // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (abc_count == 0) {
        current_char = "a";
        abc_count++;
    } else if (abc_count == 1) {
        current_char = "b";
        abc_count++;
    } else if (abc_count == 2) {
        current_char = "c";
        abc_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 1;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}

void MainWindow::on_def_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 2 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;                 // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (def_count == 0) {
        current_char = "d";
        def_count++;
    } else if (def_count == 1) {
        current_char = "e";
        def_count++;
    } else if (def_count == 2) {
        current_char = "f";
        def_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 2;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}

void MainWindow::on_ghi_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 3 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;          // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (ghi_count == 0) {
        current_char = "g";
        ghi_count++;
    } else if (ghi_count == 1) {
        current_char = "h";
        ghi_count++;
    } else if (ghi_count == 2) {
        current_char = "i";
        ghi_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 3;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}

// 화면 전환 기능
void MainWindow::on_EK_clicked()     { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_KE_clicked()     { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::on_SC_clicked()     { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::on_CS_clicked()     { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::on_EK_2_clicked()   { ui->stackedWidget->setCurrentIndex(2); }

void MainWindow::on_jkl_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 4 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (jkl_count == 0) {
        current_char = "j";
        jkl_count++;
    } else if (jkl_count == 1) {
        current_char = "k";
        jkl_count++;
    } else if (jkl_count == 2) {
        current_char = "l";
        jkl_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 4;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_mno_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 5 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;       // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (mno_count == 0) {
        current_char = "m";
        mno_count++;
    } else if (mno_count == 1) {
        current_char = "n";
        mno_count++;
    } else if (mno_count == 2) {
        current_char = "o";
        mno_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 5;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_pqrs_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 6 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (pqrs_count == 0) {
        current_char = "p";
        pqrs_count++;
    } else if (pqrs_count == 1) {
        current_char = "q";
        pqrs_count++;
    } else if (pqrs_count == 2) {
        current_char = "r";
        pqrs_count++;
    }
    else if (pqrs_count == 3) {
        current_char = "s";
        pqrs_count =0;;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 6;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_tuv_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 7 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;       // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (tuv_count == 0) {
        current_char = "t";
        tuv_count++;
    } else if (tuv_count == 1) {
        current_char = "u";
        tuv_count++;
    } else if (tuv_count == 2) {
        current_char = "v";
        tuv_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 7;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_wxyz_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 8 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;       // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (wxyz_count == 0) {
        current_char = "w";
        wxyz_count++;
    } else if (wxyz_count == 1) {
        current_char = "x";
        wxyz_count++;
    } else if (wxyz_count == 2) {
        current_char = "y";
        wxyz_count++;
    }
    else if (wxyz_count == 3) {
        current_char = "z";
        wxyz_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 8;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_ABC_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 9 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;     // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (ABC_count == 0) {
        current_char = "A";
        ABC_count++;
    } else if (ABC_count == 1) {
        current_char = "B";
        ABC_count++;
    } else if (ABC_count == 2) {
        current_char = "C";
        ABC_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 9;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_DEF_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 10 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;       // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (DEF_count == 0) {
        current_char = "D";
        DEF_count++;
    } else if (DEF_count == 1) {
        current_char = "E";
        DEF_count++;
    } else if (DEF_count == 2) {
        current_char = "F";
        DEF_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 10;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_GHI_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 11 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;       // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (GHI_count == 0) {
        current_char = "G";
        GHI_count++;
    } else if (GHI_count == 1) {
        current_char = "H";
        GHI_count++;
    } else if (GHI_count == 2) {
        current_char = "I";
        GHI_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 11;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_JKL_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 12 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;      // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (JKL_count == 0) {
        current_char = "J";
        JKL_count++;
    } else if (JKL_count == 1) {
        current_char = "K";
        JKL_count++;
    } else if (JKL_count == 2) {
        current_char = "L";
        JKL_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 12;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_MNO_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 13 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (MNO_count == 0) {
        current_char = "M";
        MNO_count++;
    } else if (MNO_count == 1) {
        current_char = "N";
        MNO_count++;
    } else if (MNO_count == 2) {
        current_char = "O";
        MNO_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 13;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_PQRS_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 14 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (PQRS_count == 0) {
        current_char = "P";
        PQRS_count++;
    } else if (PQRS_count == 1) {
        current_char = "Q";
        PQRS_count++;
    }else if (PQRS_count == 2) {
        current_char = "R";
        PQRS_count++;
    }else if (PQRS_count == 3) {
        current_char = "S";
        PQRS_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 14;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_TUV_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 15 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (TUV_count == 0) {
        current_char = "T";
        TUV_count++;
    } else if (TUV_count == 1) {
        current_char = "U";
        TUV_count++;
    }else if (TUV_count == 2) {
        current_char = "V";
        TUV_count = 0;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 15;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_WXYZ_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 16 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (WXYZ_count == 0) {
        current_char = "W";
        WXYZ_count++;
    } else if (WXYZ_count == 1) {
        current_char = "X";
        WXYZ_count++;
    }else if (WXYZ_count == 2) {
        current_char = "Y";
        WXYZ_count++;
    }else if (WXYZ_count == 3) {
        current_char = "Z";
        WXYZ_count = 0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 16;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_space_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    confirmed_text += " ";
    current_char = ""; // 현재 입력 중인 임시 칸은 비워둡니다.

    // 화면 출력
    ui->textBrowser->setText(confirmed_text);

    // 버튼 상태 초기화 (연타 기능이 없는 독립형 버튼으로 설정)
    last_button = 17;
    timer.restart();
}


void MainWindow::on_SPACE_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    confirmed_text += " ";
    current_char = ""; // 현재 입력 중인 임시 칸은 비워둡니다.

    // 화면 출력
    ui->textBrowser->setText(confirmed_text);

    // 버튼 상태 초기화 (연타 기능이 없는 독립형 버튼으로 설정)
    last_button = 18;
    timer.restart();
}


void MainWindow::on_enter_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";



    // 파일은 해당 프로그램이 빌드되어 실행되는 폴더 내에 생성됨
    ofstream outFile("output.txt", ios::app);

    if (outFile.is_open()) {
        // 3. \n(줄바꿈)을 먼저 넣어서 새로운 줄을 만든 뒤 문장 출력
        outFile << "\n" << confirmed_text.toStdString();

        // 4. 파일 안전하게 닫기
        outFile.close();
    }

    // 파일에 이미 기록했으므로, 다음 입력을 위해 확정 텍스트를 비웁니다.
    // (비우지 않으면 다음에 Enter를 누를 때 이전 문장이 다시 화면에 뜨고
    //  파일에도 중복으로 저장됩니다.)
    confirmed_text = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    ui->textBrowser->setText(""); // 화면 비우기
    timer.restart();
}


void MainWindow::on_ENTER_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";

    // 파일은 해당 프로그램이 빌드되어 실행되는 폴더 내에 생성됩니다.
    ofstream outFile("output.txt", ios::app);

    if (outFile.is_open()) {
        // 3. \n(줄바꿈)을 먼저 넣어서 새로운 줄을 만든 뒤 문장 출력
        outFile << "\n" << confirmed_text.toStdString();

        // 4. 파일 안전하게 닫기
        outFile.close();
    }

    // 파일에 이미 기록했으므로, 다음 입력을 위해 확정 텍스트를 비웁니다.
    confirmed_text = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    ui->textBrowser->setText(""); // 화면 비우기
    timer.restart();
}


void MainWindow::on_comma_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    confirmed_text += ",";
    current_char = ""; // 현재 입력 중인 임시 칸은 비워둡니다.

    // 화면 출력
    ui->textBrowser->setText(confirmed_text);

    // 버튼 상태 초기화 (연타 기능이 없는 독립형 버튼으로 설정)
    last_button = 21;
    timer.restart();
}


void MainWindow::on_COMMA_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    confirmed_text += ",";
    current_char = ""; // 현재 입력 중인 임시 칸은 비워둡니다.

    // 화면 출력
    ui->textBrowser->setText(confirmed_text);

    // 버튼 상태 초기화 (연타 기능이 없는 독립형 버튼으로 설정)
    last_button = 22;
    timer.restart();
}


void MainWindow::on_EXT_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 23 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        EXT_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (EXT_count == 0) {
        current_char = ".";
        EXT_count++;
    } else if (EXT_count == 1) {
        current_char = ",";
        EXT_count++;
    }else if (EXT_count == 2) {
        current_char = "?";
        EXT_count++;
    }else if (EXT_count == 3) {
        current_char = "!";
        EXT_count =0;;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 23;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_ext_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 24 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += current_char;
        confirmed_text += current_vowel;
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        EXT_count = 0;
        ext_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (ext_count == 0) {
        current_char = ".";
        ext_count++;
    } else if (ext_count == 1) {
        current_char = ",";
        ext_count++;
    }else if (ext_count == 2) {
        current_char = "?";
        ext_count++;
    }else if (ext_count == 3) {
        current_char = "!";
        ext_count =0;;
    }

    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + current_char);

    // 상태 기록 및 타이머 재시작
    last_button = 24;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


// 모음 버튼(l/dot/m)은 last_button==25(다른 모음 버튼) 또는
// "방금 자음만 입력하고 아직 모음이 없는 상태"(=연속 조합 중)일 때만
// 확정하지 않고 계속 이어서 조합합니다.
void MainWindow::on_l_clicked() // 모음 버튼: ㅣ (모음 그룹 번호 25번 통일)
{
    bool continuingSyllable = current_vowel.isEmpty() && !current_char.isEmpty();

    if ((last_button != 25 && !continuingSyllable) || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = "";
        current_vowel = "";
        clearAllCounts();
    }

    // 모음 결합 경우의 수
    if (current_vowel == ".") { current_vowel = "ㅓ"; }
    else if (current_vowel == "..") { current_vowel = "ㅕ"; }
    else if (current_vowel == "ㅡ") { current_vowel = "ㅢ"; }
    else if (current_vowel == "ㅗ") { current_vowel = "ㅚ"; }
    else if (current_vowel == "ㅜ") { current_vowel = "ㅟ"; }
    else if (current_vowel == "ㅏ") { current_vowel = "ㅐ"; }
    else if (current_vowel == "ㅑ") { current_vowel = "ㅒ"; }
    else if (current_vowel == "ㅓ") { current_vowel = "ㅔ"; }
    else if (current_vowel == "ㅕ") { current_vowel = "ㅖ"; }
    else if (current_vowel == "ㅘ") { current_vowel = "ㅙ"; }
    else if (current_vowel == "ㅝ") { current_vowel = "ㅞ"; }
    else if (current_vowel == "ㅐ" || current_vowel == "ㅔ" || current_vowel == "ㅒ" || current_vowel == "ㅖ" || current_vowel == "ㅙ" || current_vowel == "ㅞ") {
        current_vowel = current_vowel;
    } else { current_vowel = "ㅣ"; }

    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));
    last_button = 25;
    timer.restart();
}

void MainWindow::on_dot_clicked() // 모음 버튼: · (모음 그룹 번호 25번 통일)
{
    bool continuingSyllable = current_vowel.isEmpty() && !current_char.isEmpty();

    if ((last_button != 25 && !continuingSyllable) || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = "";
        current_vowel = "";
        clearAllCounts();
    }

    // 모음 결합 경우의 수
    if (current_vowel == "ㅣ") { current_vowel = "ㅏ"; }
    else if (current_vowel == "ㅏ") { current_vowel = "ㅑ"; }
    else if (current_vowel == "ㅓ") { current_vowel = "ㅕ"; }
    else if (current_vowel == "ㅡ") { current_vowel = "ㅜ"; }
    else if (current_vowel == "ㅜ") { current_vowel = "ㅠ"; }
    else if (current_vowel == "ㅗ") { current_vowel = "ㅘ"; }
    else if (current_vowel == "ㅜ") { current_vowel = "ㅝ"; }
    else if (current_vowel == "ㅚ") { current_vowel = "ㅘ"; }
    else if (current_vowel == "ㅟ") { current_vowel = "ㅝ"; }
    else if (current_vowel == "ㅐ") { current_vowel = "ㅒ"; }
    else if (current_vowel == "ㅔ") { current_vowel = "ㅖ"; }
    else if (current_vowel == ".") { current_vowel = ".."; }
    else if (current_vowel == "ㅑ" || current_vowel == "ㅕ" || current_vowel == "ㅠ" || current_vowel == "ㅘ" || current_vowel == "ㅝ") {
        current_vowel = current_vowel;
    } else { current_vowel = "."; }

    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));
    last_button = 25;
    timer.restart();
}

void MainWindow::on_m_clicked() // 모음 버튼: ㅡ (모음 그룹 번호 25번 통일)
{
    bool continuingSyllable = current_vowel.isEmpty() && !current_char.isEmpty();

    if ((last_button != 25 && !continuingSyllable) || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = "";
        current_vowel = "";
        clearAllCounts();
    }

    // 모음 결합 경우의 수
    if (current_vowel == ".") { current_vowel = "ㅗ"; }
    else if (current_vowel == "..") { current_vowel = "ㅛ"; }
    else if (current_vowel == "ㅣ") { current_vowel = "ㅡ"; }
    else if (current_vowel == "ㅏ") { current_vowel = "ㅐ"; }
    else if (current_vowel == "ㅑ") { current_vowel = "ㅒ"; }
    else if (current_vowel == "ㅓ") { current_vowel = "ㅔ"; }
    else if (current_vowel == "ㅕ") { current_vowel = "ㅖ"; }
    else if (current_vowel == "ㅘ") { current_vowel = "ㅙ"; }
    else if (current_vowel == "ㅝ") { current_vowel = "ㅞ"; }
    else if (current_vowel == "ㅡ" || current_vowel == "ㅗ" || current_vowel == "ㅛ") {
        current_vowel = current_vowel;
    } else { current_vowel = "ㅡ"; }

    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));
    last_button = 25;
    timer.restart();
}


void MainWindow::on_k_enter_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";



    // 파일은 해당 프로그램이 빌드되어 실행되는 폴더 내에 생성됨
    ofstream outFile("output.txt", ios::app);

    if (outFile.is_open()) {
        // 3. \n(줄바꿈)을 먼저 넣어서 새로운 줄을 만든 뒤 문장 출력
        outFile << "\n" << confirmed_text.toStdString();

        // 4. 파일 안전하게 닫기
        outFile.close();
    }

    // 파일에 이미 기록했으므로, 다음 입력을 위해 확정 텍스트를 비웁니다.
    confirmed_text = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    COMMA_count = 0;

    ui->textBrowser->setText(""); // 화면 비우기
    timer.restart();
}


void MainWindow::on_rz_clicked()
{
    bool continuingSyllable = current_vowel.isEmpty() && !current_char.isEmpty();

    if ((last_button != 26 && !continuingSyllable) || timer.elapsed() > TIMEOUT_MS) {
        // 버튼이 바뀌거나 시간이 초과되면 지금까지 만든 글자를 완전히 확정방으로 이동
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = "";
        current_vowel = "";
        clearAllCounts();
    }

    if (abc_count == 0) { current_char = "ㄱ"; abc_count++; }
    else if (abc_count == 1) { current_char = "ㅋ"; abc_count = 0; }

    // 화면 출력: 확정 문장 + (현재 자음과 모음을 실시간 결합한 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));
    last_button = 26;
    timer.restart();
}


void MainWindow::on_sf_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 27 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        rz_count = 0;
        sf_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (sf_count == 0) {
        current_char = "ㄴ";
        sf_count++;
    } else if (sf_count == 1) {
        current_char = "ㄹ";
        sf_count=0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));

    // 상태 기록 및 타이머 재시작
    last_button = 27;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_ex_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 28 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        rz_count = 0;
        sf_count = 0;
        ex_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (ex_count == 0) {
        current_char = "ㄷ";
        ex_count++;
    } else if (ex_count == 1) {
        current_char = "ㅌ";
        ex_count=0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));

    // 상태 기록 및 타이머 재시작
    last_button = 28;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_wc_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 29 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        rz_count = 0;
        sf_count = 0;
        ex_count = 0;
        wc_count = 0;    // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (wc_count == 0) {
        current_char = "ㅈ";
        wc_count++;
    } else if (wc_count == 1) {
        current_char = "ㅊ";
        wc_count=0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));

    // 상태 기록 및 타이머 재시작
    last_button = 29;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_tg_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 30 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        rz_count = 0;
        sf_count = 0;
        ex_count = 0;
        wc_count = 0;
        tg_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (tg_count == 0) {
        current_char = "ㅅ";
        tg_count++;
    } else if (tg_count == 1) {
        current_char = "ㅎ";
        tg_count=0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));

    // 상태 기록 및 타이머 재시작
    last_button = 30;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_qv_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 31 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        rz_count = 0;
        sf_count = 0;
        ex_count = 0;
        wc_count = 0;
        tg_count = 0;
        qv_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (qv_count == 0) {
        current_char = "ㅂ";
        qv_count++;
    } else if (qv_count == 1) {
        current_char = "ㅍ";
        qv_count=0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));

    // 상태 기록 및 타이머 재시작
    last_button = 31;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_da_clicked()
{
    //다른 버튼에서 왔거나, 같은 버튼이어도 마지막 클릭 후 0.8초가 지났다면 글자 확정
    if (last_button != 32 || timer.elapsed() > TIMEOUT_MS) {
        confirmed_text += combineHangeul(current_char, current_vowel);
        current_char = ""; // 자음 임시 칸은 비워둡니다.
        current_vowel = "";

        abc_count = 0;            // 다른 버튼 카운트 초기화
        def_count = 0;
        ghi_count = 0;
        jkl_count = 0;
        mno_count = 0;
        pqrs_count = 0;
        tuv_count = 0;
        wxyz_count = 0;
        ABC_count = 0;
        DEF_count = 0;
        GHI_count = 0;
        JKL_count = 0;
        MNO_count = 0;
        PQRS_count = 0;
        TUV_count = 0;
        WXYZ_count = 0;
        rz_count = 0;
        sf_count = 0;
        ex_count = 0;
        wc_count = 0;
        tg_count = 0;
        qv_count = 0;
        da_count = 0;        // 내 카운트도 0부터 다시 시작
    }

    // 글자 순환 규칙
    if (da_count == 0) {
        current_char = "ㅇ";
        da_count++;
    } else if (da_count == 1) {
        current_char = "ㅁ";
        da_count=0;
    }
    // 화면 출력 (확정 문장 + 실시간 글자)
    ui->textBrowser->setText(confirmed_text + combineHangeul(current_char, current_vowel));

    // 상태 기록 및 타이머 재시작
    last_button = 32;
    timer.restart(); // 누른 순간부터 다시 0초부터 시간 재기
}


void MainWindow::on_k_space_clicked()
{
    confirmed_text += combineHangeul(current_char, current_vowel);
    current_char = ""; // 자음 임시 칸은 비워둡니다.
    current_vowel = "";

    abc_count = 0;            // 다른 버튼 카운트 초기화
    def_count = 0;
    ghi_count = 0;
    jkl_count = 0;
    mno_count = 0;
    pqrs_count = 0;
    tuv_count = 0;
    wxyz_count = 0;
    ABC_count = 0;
    DEF_count = 0;
    GHI_count = 0;
    JKL_count = 0;
    MNO_count = 0;
    PQRS_count = 0;
    TUV_count = 0;
    WXYZ_count = 0;
    rz_count = 0;
    sf_count = 0;
    ex_count = 0;
    wc_count = 0;
    tg_count = 0;
    qv_count = 0;
    da_count = 0;

    confirmed_text += " ";
    current_char = ""; // 현재 입력 중인 임시 칸은 비워둡니다.

    // 화면 출력
    ui->textBrowser->setText(confirmed_text);

    // 버튼 상태 초기화 (연타 기능이 없는 독립형 버튼으로 설정)
    last_button = 33;
    timer.restart();
}


void MainWindow::on_k_Del_clicked()
{
    QString current_display = ui->textBrowser->toPlainText();

    if (!current_display.isEmpty()) {
        current_display.chop(1);

        ui->textBrowser->setText(current_display);
    }

    confirmed_text = current_display; // 남은 글자 전체를 확정방으로 이전
    current_char = "";
    current_vowel = "";

    abc_count = 0; def_count = 0; ghi_count = 0;

    last_button = 0;
    timer.restart();
}


void MainWindow::on_DEL_clicked()
{
    QString current_display = ui->textBrowser->toPlainText();

    if (!current_display.isEmpty()) {
        current_display.chop(1);

        ui->textBrowser->setText(current_display);
    }

    confirmed_text = current_display; // 남은 글자 전체를 확정방으로 이전
    current_char = "";
    current_vowel = "";

    abc_count = 0; def_count = 0; ghi_count = 0;

    last_button = 0;
    timer.restart();
}


void MainWindow::on_del_clicked()
{
    QString current_display = ui->textBrowser->toPlainText();

    if (!current_display.isEmpty()) {
        current_display.chop(1);

        ui->textBrowser->setText(current_display);
    }

    confirmed_text = current_display; // 남은 글자 전체를 확정방으로 이전
    current_char = "";
    current_vowel = "";

    abc_count = 0; def_count = 0; ghi_count = 0;

    last_button = 0;
    timer.restart();
}
