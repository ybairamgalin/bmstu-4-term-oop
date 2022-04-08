#ifndef EDITORDOCK_H
#define EDITORDOCK_H

#include <QObject>
#include <QDockWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>

#include "edge.h"
#include "errors.h"
#include "point3d.h"
#include "figure.h"
#include "edgeDisplayer.h"


#ifndef DOCK_WIDTH
#define DOCK_WIDTH 300
#endif

struct editorDock
{
    QDockWidget *dock;

    QGridLayout *grid;
    QWidget *multiWidget;

    QLabel *addEdgeLabel;
    QLineEdit *x1Edit;
    QLineEdit *y1Edit;
    QLineEdit *z1Edit;
    QLineEdit *x2Edit;
    QLineEdit *y2Edit;
    QLineEdit *z2Edit;
    QPushButton *addEdgeButton;

    QListWidget *edgesList;
    QPushButton *deleteEdgeButton;
};

typedef struct editorDock editorDock_t;

editorDock_t *editorDockCreate(QWidget *parent);
void editorDockDelete(editorDock_t *editorDock);
void editorDockUpdate(editorDock_t &dock, const figure_t &figure);

QDockWidget *editorGetDock(editorDock_t *editorDock);

QPushButton &getAddEdgeButton(editorDock_t &dock);
QPushButton &getDeleteButton(editorDock_t &dock);

edge_t getNewEdge(const editorDock_t &dock, error &error);

edgeDisplayer_t getDisplayer(editorDock_t &dock);

#endif // EDITORDOCK_H
