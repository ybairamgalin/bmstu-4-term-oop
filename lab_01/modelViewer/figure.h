#ifndef FIGURE_H
#define FIGURE_H

#include <stdio.h>

#include "edge.h"
#include "point3d.h"
#include "point2d.h"
#include "errors.h"
#include "drawer.h"

#ifndef MAX_FIGURE_EDGES
#define MAX_FIGURE_EDGES 1000
#endif

struct basis
{
    point2d vectorX;
    point2d vectorY;
    point2d vectorZ;
};

typedef struct basis basis_t;

struct figure
{
    edge_t edges[MAX_FIGURE_EDGES];
    int lng;
    basis_t basis;
};

typedef struct figure figure_t;

figure_t &figureInit();
error_t figureDelete(figure_t &);

error_t readFigureFromFile(figure_t &figure, const char *filename);

error_t translate(figure_t &, point3d delta);
error_t scale(figure_t &, point3d factor);
error_t rotate(figure_t &, point3d angle);

error_t addEdge(figure_t &, const edge_t &edge);
error_t draw(figure_t &, drawer_t &drawer);

int getLng(const figure_t &figure);
edge_t getEdge(const figure_t &figure, const int index);

#endif // FIGURE_H
