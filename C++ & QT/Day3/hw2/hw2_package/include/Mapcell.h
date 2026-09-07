#ifndef MAPCELL_H
#define MAPCELL_H

#include <QFrame>

class MapCell : public QFrame
{
    Q_OBJECT

public:
    enum class Type { Empty, Obstacle, Start, Goal };
    enum class State { Idle, Visiting, Confirmed, Path };

    explicit MapCell(int row, int col, QWidget *parent = nullptr);

    int row() const { return m_row; }
    int col() const { return m_col; }

    void setType(Type type);
    Type type() const { return m_type; }

    void setState(State state);
    State state() const { return m_state; }

signals:
    void clicked(int row, int col);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int m_row;
    int m_col;
    Type m_type = Type::Empty;
    State m_state = State::Idle;

    void updateColor();
};

#endif // MAPCELL_H
