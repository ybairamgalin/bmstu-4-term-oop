#ifndef EDGE_H
#define EDGE_H

#include "point3d.h"

struct edge
{
    point3d p1;
    point3d p2;
};

typedef struct edge edge_t;

edge_t translate(edge_t edge, point3d delta);
edge_t scale(edge_t edge, point3d factor, point3d center = {0.0, 0.0, 0.0});
edge_t rotate(edge_t edge, point3d angle, point3d center = {0.0, 0.0, 0.0});

point3d p1(edge_t edge);
point3d p2(edge_t edge);

#endif // EDGE_H
