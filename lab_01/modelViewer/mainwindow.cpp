#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(minWindowSize);
    ui = uiCreate(this);

    addDockWidget(Qt::RightDockWidgetArea, getEditorDock(ui));
    addDockWidget(Qt::RightDockWidgetArea, getTransformationDock(ui));
    setCentralWidget(getRenderArea(ui));

    connect(&getAddEdgeButton(*ui), SIGNAL(released()),
            this, SLOT(onAddEdgeButtonClick()));
    connect(&getDeleteEdgeButton(*ui), SIGNAL(released()),
            this, SLOT(onDeleteEdgeButtonCLick()));
    connect(&getTranslateButton(*ui), SIGNAL(released()),
            this, SLOT(onTranslateButtonClick()));
    connect(&getScaleButton(*ui), SIGNAL(released()),
            this, SLOT(onScaleButtonClick()));
    connect(&getRotateButton(*ui), SIGNAL(released()),
            this, SLOT(onRotateButtonCLick()));
}

MainWindow::~MainWindow()
{
    uiDelete(ui);
}

void MainWindow::onAddEdgeButtonClick()
{
    int error = 0;

    edge_t edge = getNewEdge(*ui, error);

    if (error)
    {
        // TODO
        return;
    }

    addEdge(*figure, edge);
    uiUpdate(*figure);
}

void MainWindow::onDeleteEdgeButtonCLick()
{
    qDebug() << "CLICKED DELETE";
}
void MainWindow::onTranslateButtonClick()
{
    qDebug() << "CLICKED TRANSLATE";
}

void MainWindow::onScaleButtonClick()
{
    qDebug() << "CLICKED SCALE";
}

void MainWindow::onRotateButtonCLick()
{
    qDebug() << "CLICKED ROTATE";
}
