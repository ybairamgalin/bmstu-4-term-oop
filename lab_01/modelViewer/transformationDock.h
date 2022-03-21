#ifndef TRANSFORMATIONDOCK_H
#define TRANSFORMATIONDOCK_H

#include <QDockWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#ifndef DOCK_WIDTH
#define DOCK_WIDTH 300
#endif

struct transformationDock
{
    QDockWidget *dock;

    QGridLayout *grid;
    QWidget *multiWidget;

    QLabel *translateLabel;
    QLineEdit *dxEdit;
    QLineEdit *dyEdit;
    QLineEdit *dzEdit;
    QPushButton *translateButton;

    QLabel *scaleLabel;
    QLineEdit *kxEdit;
    QLineEdit *kyEdit;
    QLineEdit *kzEdit;
    QPushButton *scaleButton;

    QLabel *rotateLabel;
    QLineEdit *rxEdit;
    QLineEdit *ryEdit;
    QLineEdit *rzEdit;
    QPushButton *rotateButton;
};

typedef struct transformationDock transformationDock_t;

transformationDock_t *transformationDockCreate(QWidget *parent);
void transformationDockDelete(transformationDock_t *transformationDock);

QDockWidget *tranformationGetDock(transformationDock_t *transformationDock);

#endif // TRANSFORMATIONDOCK_H
