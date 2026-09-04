cmake_minimum_required(VERSION 3.19)

project(Robit_intern_QT_Day2_hw1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt가 .ui/.h(Q_OBJECT)/.qrc 파일을 자동으로 처리해서
# ui_mainwindow.h, moc_*.cpp 등을 빌드 시점에 생성하도록 함
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# .cpp 파일(src/)과 .ui 파일(ui/)이 서로 다른 폴더에 있으므로
# AUTOUIC이 mainwindow.ui를 찾을 수 있도록 검색 경로를 명시적으로 지정
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(Qt6 COMPONENTS
Widgets QUIET)

if(Qt6_FOUND)
    set(QT_LIB Qt6::Widgets)
else()
    find_package(Qt5 REQUIRED
COMPONENTS Widgets)
    set(QT_LIB Qt5::Widgets)
endif()

add_executable(${PROJECT_NAME}
   src/main.cpp
   src/mainwindow.cpp
   include/mainwindow.h
   ui/mainwindow.ui
)

target_include_directories(${PROJECT_NAME}
   PRIVATE
   include
)

target_link_libraries(${PROJECT_NAME}
   PRIVATE
   ${QT_LIB}
)
