#ifndef EDITORDOCK_H
#define EDITORDOCK_H

#include <QDockWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>

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

typedef editorDock editorDock_t;

editorDock_t *editorDockCreate(QWidget *parent);
void editorDockDelete(editorDock_t *editorDock);

QDockWidget *editorGetDock(editorDock_t *editorDock);

#endif // EDITORDOCK_H
