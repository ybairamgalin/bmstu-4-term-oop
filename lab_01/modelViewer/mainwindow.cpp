#include "mainwindow.h"

// to use mbWarning as callback function
static MainWindow *windowInstance;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(minWindowSize);
    ui = uiCreate(this);

    addDockWidget(Qt::RightDockWidgetArea, getEditorDock(ui));
    addDockWidget(Qt::RightDockWidgetArea, getTransformationDock(ui));
    setCentralWidget(getRenderArea(ui));

    connectButtons();
    windowInstance = this;
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

error_t MainWindow::updateView(task_t task)
{
    error_t err = handleTask(task);

    if (err)
        return err;

    task.type = DRAW;
    task.drawer = getDrawer(*ui);
    err = handleTask(task);

    if (err)
        return err;

    task.type = DISPLAY_EDGES;
    task.displayer = getDisplayer(*ui);
    err = handleTask(task);

    return err;
}

void MainWindow::onAddEdgeButtonClick()
{
    error err = OK;
    edge_t edge = getNewEdge(*ui, err);

    if (err)
    {
        showWarning(mbWarning, err);
        return;
    }

    task_t task;
    task.type = ADD_EDGE;
    task.edge = edge;
    err = updateView(task);

    if (err)
        showWarning(mbWarning, err);
}

void MainWindow::onTranslateButtonClick()
{
    error err = OK;
    point3d point = getTranslation(*ui, err);

    if (err)
    {
        showWarning(mbWarning, err);
        return;
    }

    task_t task;
    task.type = TRANSLATE;
    task.point = point;
    err = updateView(task);

    if (err)
        showWarning(mbWarning, err);
}

void MainWindow::onScaleButtonClick()
{
    error err = OK;
    point3d point = getScale(*ui, err);

    if (err)
    {
        showWarning(mbWarning, err);
        return;
    }

    task_t task;
    task.type = SCALE;
    task.point = point;
    err = updateView(task);

    if (err)
        showWarning(mbWarning, err);
}

void MainWindow::onRotateButtonCLick()
{
    error err = OK;
    point3d point = getRotation(*ui, err);

    if (err)
    {
        showWarning(mbWarning, err);
        return;
    }

    task_t task;
    task.type = ROTATE;
    task.point = point;
    err = updateView(task);

    if (err)
        showWarning(mbWarning, err);
}

void MainWindow::mbWarning(const std::string str)
{
    QMessageBox::warning(windowInstance, "Warning",
                         QString::fromStdString(str));
}
