#ifndef DRAWER_H
#define DRAWER_H

#include "point2d.h"

struct renderArea;
typedef struct renderArea renderArea_t;

typedef void (*lineDrawer_t)(renderArea_t &renderArea,
                             point2d p1, point2d p2);

struct drawer
{
    renderArea_t *canvas;
    lineDrawer_t lineDrawer;
};

typedef struct drawer drawer_t;

#endif // DRAWER_H
