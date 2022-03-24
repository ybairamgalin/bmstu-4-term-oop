#ifndef FIGURE_H
#define FIGURE_H

#include "edge.h"

#ifndef MAX_FIGURE_EDGES
#define MAX_FIGURE_EDGES 100
#endif

struct figure
{
    edge_t edges[MAX_FIGURE_EDGES];
    int lng;
};

typedef struct figure figure_t;

void addEdge(figure_t &, const edge_t &edge);

#endif // FIGURE_H
