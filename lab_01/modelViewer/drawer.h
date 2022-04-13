#ifndef DRAWER_H
#define DRAWER_H

#include "point2d.h"
#include "errors.h"

struct renderArea;
typedef struct renderArea renderArea_t;

struct edge;
struct basis;

typedef void (*lineDrawer_t)(renderArea_t &renderArea,
                             point2d p1, point2d p2);

typedef void (*cleaner_t)(renderArea_t &renderArea);

struct drawer
{
    renderArea_t *canvas;
    lineDrawer_t lineDrawer;
    cleaner_t cleaner;
};

typedef struct drawer drawer_t;

error_t drawEdge(basis &basis, edge edge, drawer_t &drawer);
error_t clearAll(drawer_t drawer);


#endif // DRAWER_H
