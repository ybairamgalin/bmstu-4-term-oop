#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "point2d.h"

struct renderArea
{
    QGraphicsView *paintWidget;
    QGraphicsScene *scene;

    point2d *center;
    point2d *vectorX;
    point2d *vectorY;
    point2d *vectorZ;
};

typedef struct renderArea renderArea_t;

renderArea_t *renderAreaCreate();
void renderAreaDelete(renderArea &renderArea);

QWidget *getPaintWidget(renderArea_t *);

#endif // RENDERAREA_H
