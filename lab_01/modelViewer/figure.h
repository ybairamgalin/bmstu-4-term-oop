#ifndef FIGURE_H
#define FIGURE_H

#include <stdio.h>

#include "edge.h"
#include "point3d.h"
#include "errors.h"

#ifndef MAX_FIGURE_EDGES
#define MAX_FIGURE_EDGES 100
#endif

struct figure
{
    edge_t edges[MAX_FIGURE_EDGES];
    int lng;
};

typedef struct figure figure_t;

figure_t *figureCreate(const char *filename = nullptr);
void figureDelete(figure_t &);

void translate(figure_t &, point3d delta);
void scale(figure_t &, point3d factor);
void rotate(figure_t &, point3d angle);

void addEdge(figure_t &, const edge_t &edge);

int getLng(const figure_t &figure);
edge_t getEdge(const figure_t &figure, const int index);

#endif // FIGURE_H
