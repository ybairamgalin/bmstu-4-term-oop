#ifndef UI_H
#define UI_H

#include <QMainWindow>
#include <QWidget>

#include "transformationDock.h"
#include "editorDock.h"
#include "renderArea.h"

struct ui
{
    renderArea_t *renderArea;
    editorDock_t *editorDock;
    transformationDock_t *transformationDock;
};

typedef  ui ui_t;

ui_t *uiCreate(QMainWindow *parent = nullptr);
void uiDelete(ui_t *ui);

QWidget *getRenderArea(ui_t *ui);
QDockWidget *getEditorDock(ui_t *ui);
QDockWidget *getTransformationDock(ui_t *ui);

#endif // UI_H
