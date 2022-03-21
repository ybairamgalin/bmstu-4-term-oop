#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>

struct renderArea
{
    QWidget *paintArea;
};

typedef struct renderArea renderArea_t;

renderArea_t *renderAreaCreate();

QWidget *getPaintArea(renderArea_t *);

#endif // RENDERAREA_H
