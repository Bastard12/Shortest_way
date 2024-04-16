cmake_minimum_required(VERSION 3.5)

project(Shortest_way VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Graph.cpp
)


add_executable(Shortest_way WIN32 ${PROJECT_SOURCES})

target_link_libraries(Shortest_way PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(WIN32)
    include(Windeployqt)
    windeployqt(${PROJECT_NAME} ${CMAKE_INSTALL_PREFIX})
endif()
