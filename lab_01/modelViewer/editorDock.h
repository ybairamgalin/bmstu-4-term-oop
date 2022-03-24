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

QDockWidget *editorGetDock(editorDock_t *editorDock);

QPushButton &getAddEdgeButton(editorDock_t &dock);
QPushButton &getDeleteButton(editorDock_t &dock);

edge_t getNewEdge(editorDock_t &dock, int &error);

#endif // EDITORDOCK_H
