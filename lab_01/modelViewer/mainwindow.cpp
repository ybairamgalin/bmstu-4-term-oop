#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(minWindowSize);
    ui = uiCreate(this);
    figure = figureCreate();

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
    error err = OK;
    edge_t edge = getNewEdge(*ui, err);

    if (err)
    {
        qDebug() << "ОШИБКА";
        // TODO
        return;
    }

    addEdge(*figure, edge);
    uiUpdate(*ui, *figure);
}

void MainWindow::onDeleteEdgeButtonCLick()
{
}
void MainWindow::onTranslateButtonClick()
{
    error err = OK;
    point3d translateData = getTranslation(*ui, err);

    if (err)
    {
        // TODO
        return;
    }

    translate(*figure, translateData);
    uiUpdate(*ui, *figure);
}

void MainWindow::onScaleButtonClick()
{
    error err = OK;
    point3d scaleData = getScale(*ui, err);

    if (err)
    {
        // TODO
        return;
    }

    scale(*figure, scaleData);
    uiUpdate(*ui, *figure);
}

void MainWindow::onRotateButtonCLick()
{
    error err = OK;
    point3d rotationData = getRotation(*ui, err);

    if (err)
    {
        // TODO
        return;
    }

    rotate(*figure, rotationData);
    uiUpdate(*ui, *figure);
}
