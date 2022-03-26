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

edge_t translate(edge_t edge, point3d delta);
edge_t scale(edge_t edge, point3d factor);
edge_t rotate(edge_t edge, point3d angle, point3d center = {0.0, 0.0, 0.0});

#endif // EDGE_H
