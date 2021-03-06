#ifndef FIGURE_H
#define FIGURE_H

#include <fstream>

#include "edge.h"
#include "point3d.h"
#include "point2d.h"
#include "errors.h"
#include "drawer.h"
#include "edgeDisplayer.h"
#include "points.h"
#include "connections.h"

struct basis
{
    point2d vectorX;
    point2d vectorY;
    point2d vectorZ;
};

typedef struct basis basis_t;

struct figure
{
    points_t points;
    connections_t connections;
    basis_t basis;
};

typedef struct figure figure_t;

figure_t &figureInit();
error_t figureDelete(figure_t &);

error_t readFromFile(figure_t &figure, const char *filename);
error_t saveToFile(figure &figure, const char *filename);

error_t translate(figure_t &, point3d delta);
error_t scale(figure_t &, point3d factor);
error_t rotate(figure_t &, point3d angle);

error_t addEdge(figure_t &, const edge_t &edge);
error_t draw(figure_t &, drawer_t &drawer);

error_t displayEdges(figure_t &, edgeDisplayer_t &displayer);

#endif // FIGURE_H
