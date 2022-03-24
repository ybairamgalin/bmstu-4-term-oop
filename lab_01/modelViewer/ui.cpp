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
