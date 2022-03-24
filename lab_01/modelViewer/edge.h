#ifndef EDGE_H
#define EDGE_H

#include "point3d.h"

struct edge
{
    point3d p1;
    point3d p2;
};

typedef struct edge edge_t;

edge_t edgeInit(const point3d p1, const point3d p2);

#endif // EDGE_H
