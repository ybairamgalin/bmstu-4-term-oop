#include "ui.h"

ui_t *uiCreate(QMainWindow *parent)
{
    ui_t *ui = new ui_t;

    ui->editorDock = editorDockCreate(parent);
    ui->transformationDock = transformationDockCreate(parent);
    ui->renderArea = renderAreaCreate();

    return ui;
}

void uiDelete(ui_t *ui)
{
    editorDockDelete(ui->editorDock);
    transformationDockDelete(ui->transformationDock);
}

void uiUpdate(ui_t &ui, figure_t &figure)
{
    renderAreaUpdate(*(ui.renderArea), figure);
    editorDockUpdate(*(ui.editorDock), figure);
}

QWidget *getRenderArea(ui_t *ui)
{
    return getPaintWidget(ui->renderArea);
}

QDockWidget *getEditorDock(ui_t *ui)
{
    return editorGetDock(ui->editorDock);
}

QDockWidget *getTransformationDock(ui_t *ui)
{
    return tranformationGetDock(ui->transformationDock);
}

QPushButton &getAddEdgeButton(ui_t &ui)
{
    return getAddEdgeButton(*(ui.editorDock));
}

QPushButton &getDeleteEdgeButton(ui_t &ui)
{
    return getDeleteButton(*(ui.editorDock));
}

QPushButton &getTranslateButton(ui_t &ui)
{
    return getTranslateButton(*(ui.transformationDock));
}

QPushButton &getScaleButton(ui_t &ui)
{
    return getScaleButton(*(ui.transformationDock));
}

QPushButton &getRotateButton(ui_t &ui)
{
    return getRotateButton(*(ui.transformationDock));
}

edge_t getNewEdge(const ui_t &ui, error &error)
{
    return getNewEdge(*(ui.editorDock), error);
}

point3d getScale(ui_t &ui, error &error)
{
    return getScale(*(ui.transformationDock), error);
}

point3d getRotation(ui_t &ui, error &error)
{
    return getRotation(*(ui.transformationDock), error);
}

point3d getTranslation(ui_t &ui, error &error)
{
    return getTranslation(*(ui.transformationDock), error);
}

drawer_t getDrawer(ui_t &ui)
{
    return getDrawer(*(ui.renderArea));
}

edgeDisplayer_t getDisplayer(ui_t &ui)
{
    return getDisplayer(*(ui.editorDock));
}
