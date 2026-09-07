#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QButtonGroup>
#include <QTimer>
#include <vector>
#include <utility>
#include <queue>
#include <limits>
#include "Mapcell.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// 우선순위 큐에 넣을 노드 (리포트의 PQNode와 동일한 역할)
// f = g + h, f가 작은 노드부터 뽑히도록 operator> 정의
struct AlgoNode
{
    int f;
    int g;
    int row;
    int col;

    bool operator>(const AlgoNode &other) const { return f > other.f; }
};

// A*/Dijkstra 각각의 진행 상태 (open list, closed list, best값, parent 추적)
// useHeuristic = false 로 두면 h가 항상 0이 되어 Dijkstra와 동일하게 동작함
struct SearchState
{
    std::priority_queue<AlgoNode, std::vector<AlgoNode>, std::greater<AlgoNode>> pq;
    std::vector<std::vector<bool>> closed;
    std::vector<std::vector<int>> bestF;
    std::vector<std::vector<std::pair<int,int>>> parent;
    bool useHeuristic = true;
    bool active = false;
    bool found = false;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onModeChanged();

    void on_pushButton_2_clicked();  // 맵 사이즈 Apply
    void on_pushButton_4_clicked();  // Start 확정 / Goal 확정 (단계에 따라 재사용)
    void on_pushButton_5_clicked();  // 장애물 확정

    void on_pushButton_clicked();    // Path Search 페이지: Start
    void on_pushButton_3_clicked();  // Path Search 페이지: Stop

    void onCellClicked(int row, int col);

private:
    Ui::MainWindow *ui;

    // ---- 격자 생성/관리 ----
    void createGrid(QGridLayout *layout, std::vector<std::vector<MapCell*>> &cellStorage, int rows, int cols);
    void clearGrid(QGridLayout *layout);
    void setCellType(int row, int col, MapCell::Type type);
    void generateRandomObstacles();

    // ---- 설정 단계 관리 (장애물 -> 시작 -> 목표 -> 완료) ----
    enum class SetupStep { Obstacle, Start, Goal, Done };
    SetupStep setupStep = SetupStep::Obstacle;
    void updateStepUI();

    // ---- 맵 데이터 (A*, Dijkstra 두 격자가 공유) ----
    int mapRows = 0;
    int mapCols = 0;
    std::vector<std::vector<MapCell::Type>> mapData;
    std::vector<std::vector<MapCell*>> cellsAStar;     // gridLayout_2
    std::vector<std::vector<MapCell*>> cellsDijkstra;  // gridLayout_3

    std::pair<int,int> startPos { -1, -1 };
    std::pair<int,int> goalPos  { -1, -1 };

    enum class ClickMode { None, DrawObstacle, SetStart, SetGoal };
    ClickMode currentClickMode = ClickMode::None;

    QButtonGroup *obstacleModeGroup = nullptr; // Drawing / Percent
    QButtonGroup *pointModeGroup    = nullptr; // Start / Goal

    // ---- 경로 탐색 (A*, Dijkstra) ----
    SearchState aStarState;
    SearchState dijkstraState;
    QTimer *aStarTimer = nullptr;
    QTimer *dijkstraTimer = nullptr;

    void initSearch(SearchState &state, bool useHeuristic);
    void stepSearch(SearchState &state, std::vector<std::vector<MapCell*>> &cells, QTimer *timer);
    void drawPath(SearchState &state, std::vector<std::vector<MapCell*>> &cells);
    void resetSearchVisuals();
};
#endif // MAINWINDOW_H
