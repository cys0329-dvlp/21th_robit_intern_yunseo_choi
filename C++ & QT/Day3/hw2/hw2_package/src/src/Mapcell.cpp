#include "Mapcell.h"
#include <QMouseEvent>

MapCell::MapCell(int row, int col, QWidget *parent)
    : QFrame(parent), m_row(row), m_col(col)
{
    setFrameShape(QFrame::Box);
    setLineWidth(1);
    setAutoFillBackground(true);
    updateColor();
}

void MapCell::setType(Type type)
{
    m_type = type;
    updateColor();
}

void MapCell::setState(State state)
{
    m_state = state;
    updateColor();
}

void MapCell::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked(m_row, m_col);
    }
    QFrame::mousePressEvent(event);
}

void MapCell::updateColor()
{
    QString color;

    if (m_type == Type::Obstacle) {
        color = "#333333";       // 장애물: 어두운 회색
    } else if (m_type == Type::Start) {
        color = "#2ecc71";       // 시작점: 초록
    } else if (m_type == Type::Goal) {
        color = "#e74c3c";       // 목표점: 빨강
    } else {
        // 빈 칸일 때만 탐색 상태 색이 반영됨
        switch (m_state) {
        case State::Confirmed:
            color = "#f1c40f";   // 확정된 노드: 노랑
            break;
        case State::Visiting:
            color = "#aed6f1";   // 탐색 중인 노드: 연한 파랑
            break;
        case State::Path:
            color = "#9b59b6";   // 최종 경로: 보라
            break;
        default:
            color = "#ffffff";   // 기본: 흰색
            break;
        }
    }

    setStyleSheet(QString("background-color: %1;").arg(color));
}
