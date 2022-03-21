#include "ui.h"

ui_t *uiCreate(QMainWindow *parent)
{
    ui_t *ui = new ui_t;

    ui->editorDock = editorDockCreate(parent);
    parent->addDockWidget(Qt::LeftDockWidgetArea, editorGetDock(ui->editorDock));

    return ui;
}

void uiDelete(ui_t *ui)
{
    editorDockDelete(ui->editorDock);
}
