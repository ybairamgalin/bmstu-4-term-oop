QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connections.cpp \
    drawer.cpp \
    edge.cpp \
    edgeDisplayer.cpp \
    editorDock.cpp \
    errors.cpp \
    figure.cpp \
    main.cpp \
    mainwindow.cpp \
    point2d.cpp \
    point3d.cpp \
    points.cpp \
    renderArea.cpp \
    taskHandler.cpp \
    transformationDock.cpp \
    ui.cpp

HEADERS += \
    connection.h \
    connections.h \
    drawer.h \
    edge.h \
    edgeDisplayer.h \
    editorDock.h \
    errors.h \
    figure.h \
    mainwindow.h \
    point2d.h \
    point3d.h \
    points.h \
    renderArea.h \
    taskHandler.h \
    transformationDock.h \
    ui.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../README.md \
    figure_1.txt \
    readme.md
