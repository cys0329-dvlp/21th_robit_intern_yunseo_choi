#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QLayoutItem>
#include <QMessageBox>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QVector>
#include <QPoint>
#include <algorithm>
#include <cmath>
using namespace std;

// 상하좌우 + 대각선 8방향 이동. 리포트와 동일하게 직선 10, 대각선 14 cost 사용
// (실제 대각선 비용은 14.14.. 이지만 정수 계산을 위해 14로 반올림)
int kDirRow[8]  = { -1,  1,  0, 0, -1,  1, -1, 1 };
int kDirCol[8]  = {  0,  0, -1, 1, -1, -1,  1, 1 };
int kDirCost[8] = { 10, 10, 10,10, 14, 14, 14,14 };

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

    // page_3 안의 라디오버튼들은 같은 부모 위젯에 있어서 기본적으로 하나로 묶여버림.
    // 장애물 모드와 지점 시작 모드를 독립적으로 선택할 수 있도록
    // 명시적으로 두 개의 QButtonGroup으로 분리함.
    obstacleModeGroup = new QButtonGroup(this);
    obstacleModeGroup->addButton(ui->radioButton_4); // Drawing
    obstacleModeGroup->addButton(ui->radioButton_8); // Percent

    pointModeGroup = new QButtonGroup(this);
    pointModeGroup->addButton(ui->radioButton_9);  // Start
    pointModeGroup->addButton(ui->radioButton_10); // Goal

    connect(ui->radioButton_4, &QRadioButton::toggled, this, [this](bool checked){
        if (checked) currentClickMode = ClickMode::DrawObstacle;
    });
    connect(ui->radioButton_8, &QRadioButton::toggled, this, [this](bool checked){
        if (checked) {
            currentClickMode = ClickMode::None;
            generateRandomObstacles();
        }
    });
    connect(ui->radioButton_9, &QRadioButton::toggled, this, [this](bool checked){
        if (checked) currentClickMode = ClickMode::SetStart;
    });
    connect(ui->radioButton_10, &QRadioButton::toggled, this, [this](bool checked){
        if (checked) currentClickMode = ClickMode::SetGoal;
    });

    updateStepUI(); // 시작할 때 Obstacle 단계만 열어두고 나머지는 잠금
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

// ===========================================================
// 격자 생성 / 삭제
// ===========================================================

void MainWindow::clearGrid(QGridLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget *w = item->widget()) {
            w->deleteLater();
        }
        delete item;
    }
}

void MainWindow::createGrid(QGridLayout *layout, std::vector<std::vector<MapCell*>> &cellStorage, int rows, int cols)
{
    clearGrid(layout);
    cellStorage.assign(rows, std::vector<MapCell*>(cols, nullptr));

    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    QWidget *container = layout->parentWidget();
    int totalWidth  = container->width();
    int totalHeight = container->height();

    int baseW  = totalWidth  / cols;
    int baseH  = totalHeight / rows;
    int extraW = totalWidth  % cols;
    int extraH = totalHeight % rows;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            MapCell *cell = new MapCell(row, col);

            int w = baseW + (col < extraW ? 1 : 0);
            int h = baseH + (row < extraH ? 1 : 0);
            cell->setFixedSize(w, h);

            connect(cell, &MapCell::clicked, this, &MainWindow::onCellClicked);

            layout->addWidget(cell, row, col);
            cellStorage[row][col] = cell;
        }
    }
}

// 맵 사이즈 결정 (Map Setting 페이지)


void MainWindow::on_pushButton_2_clicked()
{
    int rows = 0;
    int cols = 0;

    if (ui->radioButton_5->isChecked()) {        // 소
        rows = 10; cols = 10;
        ui->textBrowser->setText("10px 생성됨");
    } else if (ui->radioButton_6->isChecked()) { // 중
        rows = 15; cols = 15;
        ui->textBrowser->setText("15px 생성됨");
    } else if (ui->radioButton_7->isChecked()) { // 대
        rows = 20; cols = 20;
        ui->textBrowser->setText("20px 생성됨");
    } else {
        QMessageBox::information(this, "맵 크기 선택", "맵 크기를 먼저 선택해주세요.");
        return;
    }

    mapRows = rows;
    mapCols = cols;

    mapData.assign(rows, std::vector<MapCell::Type>(cols, MapCell::Type::Empty));
    startPos = { -1, -1 };
    goalPos  = { -1, -1 };

    createGrid(ui->gridLayout_2, cellsAStar, rows, cols);    // A* 쪽
    createGrid(ui->gridLayout_3, cellsDijkstra, rows, cols); // Dijkstra 쪽

    // 맵을 새로 만들면 설정 단계도 처음(장애물)부터 다시 시작
    setupStep = SetupStep::Obstacle;
    currentClickMode = ClickMode::None;

    if (aStarTimer)    aStarTimer->stop();
    if (dijkstraTimer) dijkstraTimer->stop();

    updateStepUI();
}

// 셀 타입 반영 (두 격자 동시에)


void MainWindow::setCellType(int row, int col, MapCell::Type type)
{
    mapData[row][col] = type;
    cellsAStar[row][col]->setType(type);
    cellsDijkstra[row][col]->setType(type);
}

// 격자 클릭 처리 (현재 클릭 모드에 따라 동작)

void MainWindow::onCellClicked(int row, int col)
{
    if (mapData.empty()) return; // 맵 크기 먼저 설정 안 했으면 무시

    switch (currentClickMode) {
    case ClickMode::DrawObstacle: {
        if (mapData[row][col] == MapCell::Type::Start ||
            mapData[row][col] == MapCell::Type::Goal) {
            return; // 시작/목표점은 장애물로 덮어쓰지 않음
        }
        MapCell::Type newType = (mapData[row][col] == MapCell::Type::Obstacle)
                                    ? MapCell::Type::Empty
                                    : MapCell::Type::Obstacle;
        setCellType(row, col, newType);
        break;
    }
    case ClickMode::SetStart: {
        if (mapData[row][col] == MapCell::Type::Obstacle) return;
        if (startPos.first >= 0) {
            setCellType(startPos.first, startPos.second, MapCell::Type::Empty);
        }
        setCellType(row, col, MapCell::Type::Start);
        startPos = { row, col };
        break;
    }
    case ClickMode::SetGoal: {
        if (mapData[row][col] == MapCell::Type::Obstacle) return;
        if (goalPos.first >= 0) {
            setCellType(goalPos.first, goalPos.second, MapCell::Type::Empty);
        }
        setCellType(row, col, MapCell::Type::Goal);
        goalPos = { row, col };
        break;
    }
    case ClickMode::None:
    default:
        break; // Percent 모드 등: 직접 클릭으로는 아무 동작 안 함
    }
}

// ===========================================================
// 퍼센트 기반 랜덤 장애물 생성
// ===========================================================

void MainWindow::generateRandomObstacles()
{
    if (mapData.empty()) {
        QMessageBox::information(this, "맵 크기 선택", "맵 크기를 먼저 선택해주세요.");
        return;
    }

    bool ok = false;
    int percent = QInputDialog::getInt(this, "장애물 비율",
                                       "장애물 비율(%)을 입력하세요:",
                                       20, 0, 100, 1, &ok);
    if (!ok) return;

    // 기존 장애물만 초기화 (시작/목표점은 유지)
    for (int r = 0; r < mapRows; ++r) {
        for (int c = 0; c < mapCols; ++c) {
            if (mapData[r][c] == MapCell::Type::Obstacle) {
                setCellType(r, c, MapCell::Type::Empty);
            }
        }
    }

    QVector<QPoint> candidates;
    for (int r = 0; r < mapRows; ++r) {
        for (int c = 0; c < mapCols; ++c) {
            if (mapData[r][c] == MapCell::Type::Empty) {
                candidates.append(QPoint(r, c));
            }
        }
    }

    std::shuffle(candidates.begin(), candidates.end(), *QRandomGenerator::global());

    int obstacleCount = (mapRows * mapCols) * percent / 100;
    obstacleCount = std::min(obstacleCount, static_cast<int>(candidates.size()));

    for (int i = 0; i < obstacleCount; ++i) {
        setCellType(candidates[i].x(), candidates[i].y(), MapCell::Type::Obstacle);
    }
}

// ===========================================================
// 설정 단계별 UI 활성/비활성 처리
// ===========================================================

void MainWindow::updateStepUI()
{
    bool obstacleStep = (setupStep == SetupStep::Obstacle);
    bool startStep     = (setupStep == SetupStep::Start);
    bool goalStep       = (setupStep == SetupStep::Goal);

    ui->radioButton_4->setEnabled(obstacleStep);
    ui->radioButton_8->setEnabled(obstacleStep);
    ui->pushButton_5->setEnabled(obstacleStep);

    ui->radioButton_9->setEnabled(startStep);
    ui->radioButton_10->setEnabled(goalStep);
    ui->pushButton_4->setEnabled(startStep || goalStep);

    // 모든 설정이 끝나야 Path Search의 Start 버튼 활성화
    ui->pushButton->setEnabled(setupStep == SetupStep::Done);
}

// ===========================================================
// 장애물 확정 (pushButton_5)
// ===========================================================

void MainWindow::on_pushButton_5_clicked()
{
    if (mapData.empty()) {
        QMessageBox::information(this, "맵 크기 선택", "맵 크기를 먼저 선택해주세요.");
        return;
    }
    if (setupStep != SetupStep::Obstacle) return;

    setupStep = SetupStep::Start;
    currentClickMode = ClickMode::None;
    updateStepUI();
    ui->textBrowser->setText("장애물이 확정되었습니다. Start 지점을 선택하세요.");
}

// ===========================================================
// 시작/목표 지점 확정 (pushButton_4, 단계에 따라 재사용)
// ===========================================================

void MainWindow::on_pushButton_4_clicked()
{
    if (setupStep == SetupStep::Start) {
        if (startPos.first < 0) {
            QMessageBox::warning(this, "설정 필요", "맵에서 시작 지점을 클릭해주세요.");
            return;
        }
        setupStep = SetupStep::Goal;
        currentClickMode = ClickMode::None;
        updateStepUI();
        ui->textBrowser->setText("시작 지점이 확정되었습니다. 목표 지점을 선택하세요.");

    } else if (setupStep == SetupStep::Goal) {
        if (goalPos.first < 0) {
            QMessageBox::warning(this, "설정 필요", "맵에서 목표 지점을 클릭해주세요.");
            return;
        }
        setupStep = SetupStep::Done;
        currentClickMode = ClickMode::None;
        updateStepUI();
        ui->textBrowser->setText("모든 설정이 완료되었습니다. Path Search로 이동하세요.");
    }
}

// ===========================================================
// 경로 탐색: 초기화 (리포트 7) 초기값 지정 단계와 동일)
// ===========================================================

void MainWindow::initSearch(SearchState &state, bool useHeuristic)
{
    // 큐/closed/best/parent 전부 새로 초기화
    state.pq = std::priority_queue<AlgoNode, std::vector<AlgoNode>, std::greater<AlgoNode>>();
    state.closed.assign(mapRows, std::vector<bool>(mapCols, false));
    state.bestF.assign(mapRows, std::vector<int>(mapCols, std::numeric_limits<int>::max()));
    state.parent.assign(mapRows, std::vector<std::pair<int,int>>(mapCols, {-1, -1}));
    state.useHeuristic = useHeuristic;
    state.found = false;
    state.active = true;

    int sr = startPos.first, sc = startPos.second;
    int gr = goalPos.first,  gc = goalPos.second;

    // h는 맨해튼 거리 * 10 (리포트의 g(n)+h(n) 공식과 동일)
    // useHeuristic == false 이면 h를 0으로 고정 -> Dijkstra와 동일하게 동작
    int h = useHeuristic ? 10 * (std::abs(gr - sr) + std::abs(gc - sc)) : 0;
    int g = 0;
    int f = g + h;

    state.pq.push({ f, g, sr, sc });
    state.bestF[sr][sc] = f;
    state.parent[sr][sc] = { sr, sc };
}

// ===========================================================
// 경로 탐색: 한 스텝 처리 (리포트 8) while문의 한 바퀴에 해당)
// QTimer가 이 함수를 주기적으로 호출해서 애니메이션처럼 보이게 함
// ===========================================================

void MainWindow::stepSearch(SearchState &state, std::vector<std::vector<MapCell*>> &cells, QTimer *timer)
{
    // 이미 방문 처리된(닫힌) 노드는 큐에서 계속 버림
    while (!state.pq.empty() && state.closed[state.pq.top().row][state.pq.top().col]) {
        state.pq.pop();
    }

    if (state.pq.empty()) {
        // open list가 빈 상태로 끝남 -> 경로 없음
        timer->stop();
        state.active = false;
        ui->textBrowser->append("경로를 찾지 못했습니다.");
        return;
    }

    AlgoNode node = state.pq.top();
    state.pq.pop();

    // 방문 처리 -> close list로 이동
    state.closed[node.row][node.col] = true;

    MapCell::Type curType = cells[node.row][node.col]->type();
    if (curType != MapCell::Type::Start && curType != MapCell::Type::Goal) {
        cells[node.row][node.col]->setState(MapCell::State::Confirmed); // 확정 노드: 노랑
    }

    // 목표 노드에 도달했으면 종료하고 경로 그리기
    if (node.row == goalPos.first && node.col == goalPos.second) {
        timer->stop();
        state.active = false;
        state.found = true;
        drawPath(state, cells);
        return;
    }

    // 인접한 8방향 노드들을 open list에 추가 (리포트 5번 과정)
    for (int i = 0; i < 8; ++i) {
        int nr = node.row + kDirRow[i];
        int nc = node.col + kDirCol[i];

        if (nr < 0 || nr >= mapRows || nc < 0 || nc >= mapCols) continue;
        if (mapData[nr][nc] == MapCell::Type::Obstacle) continue;
        if (state.closed[nr][nc]) continue;

        int g = node.g + kDirCost[i];
        int h = state.useHeuristic
                    ? 10 * (std::abs(goalPos.first - nr) + std::abs(goalPos.second - nc))
                    : 0;
        int f = g + h;

        // 기존에 저장된 값보다 더 좋은 경로를 발견했을 때만 갱신
        if (f < state.bestF[nr][nc]) {
            state.bestF[nr][nc] = f;
            state.parent[nr][nc] = { node.row, node.col };
            state.pq.push({ f, g, nr, nc });

            MapCell::Type t = cells[nr][nc]->type();
            if (t != MapCell::Type::Start && t != MapCell::Type::Goal) {
                cells[nr][nc]->setState(MapCell::State::Visiting); // 탐색 중: 연한 파랑
            }
        }
    }
}

// ===========================================================
// 목표에서 시작점까지 parent를 거슬러 올라가며 최종 경로 표시
// ===========================================================

void MainWindow::drawPath(SearchState &state, std::vector<std::vector<MapCell*>> &cells)
{
    int r = goalPos.first;
    int c = goalPos.second;

    while (!(r == startPos.first && c == startPos.second)) {
        MapCell::Type t = cells[r][c]->type();
        if (t != MapCell::Type::Start && t != MapCell::Type::Goal) {
            cells[r][c]->setState(MapCell::State::Path); // 최종 경로: 보라
        }

        auto p = state.parent[r][c];
        // parent가 설정되지 않은 비정상 상황 방지
        if (p.first < 0 || p.second < 0) break;
        r = p.first;
        c = p.second;
    }
}

// ===========================================================
// 이전 탐색 결과(색상) 초기화
// ===========================================================

void MainWindow::resetSearchVisuals()
{
    for (int r = 0; r < mapRows; ++r) {
        for (int c = 0; c < mapCols; ++c) {
            cellsAStar[r][c]->setState(MapCell::State::Idle);
            cellsDijkstra[r][c]->setState(MapCell::State::Idle);
        }
    }
}

// ===========================================================
// Path Search 페이지: Start 버튼 -> A*, Dijkstra 동시 시작
// ===========================================================

void MainWindow::on_pushButton_clicked()
{
    if (setupStep != SetupStep::Done) {
        QMessageBox::information(this, "설정 필요", "먼저 장애물/시작/목표 설정을 완료해주세요.");
        return;
    }

    resetSearchVisuals();

    initSearch(aStarState, true);       // A*: 휴리스틱 사용
    initSearch(dijkstraState, false);   // Dijkstra: 휴리스틱 없음 (h = 0)

    if (!aStarTimer) {
        aStarTimer = new QTimer(this);
        connect(aStarTimer, &QTimer::timeout, this, [this]() {
            stepSearch(aStarState, cellsAStar, aStarTimer);
        });
    }
    if (!dijkstraTimer) {
        dijkstraTimer = new QTimer(this);
        connect(dijkstraTimer, &QTimer::timeout, this, [this]() {
            stepSearch(dijkstraState, cellsDijkstra, dijkstraTimer);
        });
    }

    ui->textBrowser->setText("경로 탐색 중");
    aStarTimer->start(30);     // 30ms마다 한 노드씩 처리 -> 애니메이션처럼 보임
    dijkstraTimer->start(30);
}

// ===========================================================
// Path Search 페이지: Stop 버튼 -> 탐색 중단
// ===========================================================

void MainWindow::on_pushButton_3_clicked()
{
    if (aStarTimer)    aStarTimer->stop();
    if (dijkstraTimer) dijkstraTimer->stop();

    aStarState.active = false;
    dijkstraState.active = false;

    ui->textBrowser->setText("탐색이 중단되었습니다.");
}
