#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "figure.h"
#include "point2d.h"
#include "point3d.h"

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

void renderAreaUpdate(renderArea &renderArea, const figure_t &figure);

drawer_t getDrawer(renderArea &renderArea);

#endif // RENDERAREA_H
