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

void MainWindow::updateView(figure_t &model)
{
    uiUpdate(*ui, model);
}

void MainWindow::onAddEdgeButtonClick()
{
    error err = OK;
    edge_t edge = getNewEdge(*ui, err);

    if (err)
    {
        showWarning(this, err);
        return;
    }

    task_t task;
    task.type = ADD_EDGE;
    task.data.edge = edge;

    handleTask(task);
}

void MainWindow::onDeleteEdgeButtonCLick()
{
}

void MainWindow::onTranslateButtonClick()
{
    error err = OK;
    point3d point = getTranslation(*ui, err);

    if (err)
    {
        showWarning(this, err);
        return;
    }

    task_t task;
    task.type = TRANSLATE;
    task.data.point = point;

    handleTask(task);
}

void MainWindow::onScaleButtonClick()
{
    error err = OK;
    point3d point = getScale(*ui, err);

    if (err)
    {
        showWarning(this, err);
        return;
    }

    task_t task;
    task.type = SCALE;
    task.data.point = point;

    handleTask(task);
}

void MainWindow::onRotateButtonCLick()
{
    error err = OK;
    point3d point = getRotation(*ui, err);

    if (err)
    {
        showWarning(this, err);
        return;
    }

    task_t task;
    task.type = ROTATE;
    task.data.point = point;

    handleTask(task);
}


