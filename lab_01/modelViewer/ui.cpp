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
    return getPaintArea(ui->renderArea);
}

QDockWidget *getEditorDock(ui_t *ui)
{
    return editorGetDock(ui->editorDock);
}

QDockWidget *getTransformationDock(ui_t *ui)
{
    return tranformationGetDock(ui->transformationDock);
}
