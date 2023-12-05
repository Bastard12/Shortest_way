cmake_minimum_required(VERSION 3.5)

project(Shortest_way VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(WIN32)
set(CMAKE_PREFIX_PATH C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
set(QT_DIR C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
endif()


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

install(FILES "dependences/win/Qt5Core.dll" DESTINATION ${CMAKE_BINARY_DIR}/Release)
install(FILES "dependences/win/Qt5Gui.dll" DESTINATION ${CMAKE_BINARY_DIR}/Release)
install(FILES "dependences/win/Qt5Widgets.dll" DESTINATION ${CMAKE_BINARY_DIR}/Release)
install(DIRECTORY "dependences/win/platforms" DESTINATION ${CMAKE_BINARY_DIR}/Release)
