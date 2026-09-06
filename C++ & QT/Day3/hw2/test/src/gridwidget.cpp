#include "gridwidget.h"
#include <QPainter>
#include <QDebug> // 디버그 출력을 위해 포함

GridWidget::GridWidget(QWidget *parent) : QWidget(parent) {
    rows = 10; // 격자 크기를 감안해 10x10으로 예시 변경 (원하는 대로 수정 가능)
    cols = 10;

    cellWidth = 0;
    cellHeight = 0;
    offsetX = 0;
    offsetY = 0;
}

void GridWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 1));
    painter.setBrush(Qt::NoBrush);

    // 창 크기가 바뀔 때마다 셀 크기와 여백을 유연하게 업데이트
    int cellSize = qMin(width() / cols, height() / rows);
    cellWidth = cellSize;
    cellHeight = cellSize;

    offsetX = (width() - (cols * cellWidth)) / 2;
    offsetY = (height() - (rows * cellHeight)) / 2;

    // 격자 그리기
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            painter.drawRect(offsetX + c * cellWidth, offsetY + r * cellHeight, cellWidth, cellHeight);
        }
    }
}

// 마우스 클릭 시 자동 호출되는 함수
void GridWidget::mousePressEvent(QMouseEvent *event) {
    // 왼쪽 마우스 버튼 클릭만 처리
    if (event->button() == Qt::LeftButton) {
        int mouseX = event->position().x();
        int mouseY = event->position().y();

        // 여백(Offset)을 제외한 실제 격자 내부를 클릭했는지 확인
        if (mouseX >= offsetX && mouseX < offsetX + (cols * cellWidth) &&
            mouseY >= offsetY && mouseY < offsetY + (rows * cellHeight)) {

            // 마우스 좌표를 격자의 행(row), 열(col) 인덱스로 환산 (핵심 설계)
            int clickedCol = (mouseX - offsetX) / cellWidth;
            int clickedRow = (mouseY - offsetY) / cellHeight;

            // 빌드 후 실행창 하단 'Application Output' 탭에서 클릭 결과 확인 가능
            qDebug() << "클릭된 칸 -> 행(Row):" << clickedRow << ", 열(Col):" << clickedCol;

            // 하이라이트나 벽 생성을 위해 화면 갱신이 필요할 때 호출
            // update();
        }
    }
}
