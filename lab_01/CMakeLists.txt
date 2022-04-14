#cmake_minimum_required(VERSION 3.17)
#project(lab_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(modelViewer)

cmake_minimum_required(VERSION 3.17)
project(lab_01)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Gui Qt6::Widgets)


add_executable(lab_01
        modelViewer/connection.h
        modelViewer/connections.cpp
        modelViewer/connections.h
        modelViewer/drawer.cpp
        modelViewer/drawer.h
        modelViewer/edge.cpp
        modelViewer/edge.h
        modelViewer/edgeDisplayer.cpp
        modelViewer/edgeDisplayer.h
        modelViewer/editorDock.cpp
        modelViewer/editorDock.h
        modelViewer/errors.cpp
        modelViewer/errors.h
        modelViewer/figure.cpp
        modelViewer/figure.h
        modelViewer/init.h
        modelViewer/main.cpp
        modelViewer/mainwindow.cpp
        modelViewer/mainwindow.h
        modelViewer/point2d.cpp
        modelViewer/point2d.h
        modelViewer/point3d.cpp
        modelViewer/point3d.h
        modelViewer/points.cpp
        modelViewer/points.h
        modelViewer/renderArea.cpp
        modelViewer/renderArea.h
        modelViewer/taskHandler.cpp
        modelViewer/taskHandler.h
        modelViewer/transformationDock.cpp
        modelViewer/transformationDock.h
        modelViewer/ui.cpp
        modelViewer/ui.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
