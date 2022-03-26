#ifndef UI_H
#define UI_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

#include "transformationDock.h"
#include "editorDock.h"
#include "renderArea.h"

#include "edge.h"
#include "figure.h"
#include "point3d.h"

struct ui
{
    renderArea_t *renderArea;
    editorDock_t *editorDock;
    transformationDock_t *transformationDock;
};

typedef struct ui ui_t;

ui_t *uiCreate(QMainWindow *parent = nullptr);
void uiDelete(ui_t *ui);

void uiUpdate(ui_t &ui, figure_t &figure);
edge_t getNewEdge(const ui_t &ui, error &error);
point3d getScale(ui_t &ui, error &error);
point3d getRotation(ui_t &ui, error &error);
point3d getTranslation(ui_t &ui, error &error);

QWidget *getRenderArea(ui_t *ui);
QDockWidget *getEditorDock(ui_t *ui);
QDockWidget *getTransformationDock(ui_t *ui);

QPushButton &getAddEdgeButton(ui_t &ui);
QPushButton &getDeleteEdgeButton(ui_t &ui);
QPushButton &getTranslateButton(ui_t &ui);
QPushButton &getScaleButton(ui_t &ui);
QPushButton &getRotateButton(ui_t &ui);

#endif // UI_H
