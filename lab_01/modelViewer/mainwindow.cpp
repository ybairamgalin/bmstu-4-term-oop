#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(minWindowSize);
    ui = uiCreate(this);

    addDockWidget(Qt::RightDockWidgetArea, getEditorDock(ui));
    addDockWidget(Qt::RightDockWidgetArea, getTransformationDock(ui));

    setCentralWidget(getRenderArea(ui));
}

MainWindow::~MainWindow()
{
    uiDelete(ui);
}
