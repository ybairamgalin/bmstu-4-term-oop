#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    task_t task;
    task.type = START_UP;
    handleTask(task);

    setMinimumSize(minWindowSize);
    ui = uiCreate(this);

    addDockWidget(Qt::RightDockWidgetArea, getEditorDock(ui));
    addDockWidget(Qt::RightDockWidgetArea, getTransformationDock(ui));
    setCentralWidget(getRenderArea(ui));

    connectButtons();
}

MainWindow::~MainWindow()
{
    uiDelete(ui);
}

void MainWindow::connectButtons()
{
    connect(&getAddEdgeButton(*ui), SIGNAL(released()),
            this, SLOT(onAddEdgeButtonClick()));
    connect(&getTranslateButton(*ui), SIGNAL(released()),
            this, SLOT(onTranslateButtonClick()));
    connect(&getScaleButton(*ui), SIGNAL(released()),
            this, SLOT(onScaleButtonClick()));
    connect(&getRotateButton(*ui), SIGNAL(released()),
            this, SLOT(onRotateButtonCLick()));
}

error_t MainWindow::updateView(taskType_t type, data_t &data)
{
    task_t task;
    task.type = type;
    task.data = data;

    error_t err = handleTask(task);

    if (err)
        return err;

    task.type = DRAW;
    task.data.drawer = getDrawer(*ui);
    err = handleTask(task);

    if (err)
        return err;

    task.type = DISPLAY_EDGES;
    task.data.displayer = getDisplayer(*ui);
    err = handleTask(task);

    return err;
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

    data_t data;
    data.edge = edge;
    err = updateView(ADD_EDGE, data);

    if (err)
        showWarning(this, err);
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

    data_t data;
    data.point = point;
    err = updateView(TRANSLATE, data);

    if (err)
        showWarning(this, err);
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

    data_t data;
    data.point = point;
    err = updateView(SCALE, data);

    if (err)
        showWarning(this, err);
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

    data_t data;
    data.point = point;
    err = updateView(ROTATE, data);

    if (err)
        showWarning(this, err);
}
