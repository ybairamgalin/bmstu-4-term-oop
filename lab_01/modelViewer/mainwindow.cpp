#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui = uiCreate(this);
    setMinimumSize(minWindowSize);

    addDockWidget(Qt::RightDockWidgetArea, getEditorDock(ui));
    addDockWidget(Qt::RightDockWidgetArea, getTransformationDock(ui));

    setCentralWidget(getRenderArea(ui));
}

MainWindow::~MainWindow()
{
    uiDelete(ui);
}

