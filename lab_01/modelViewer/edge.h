#ifndef EDGE_H
#define EDGE_H

#include <fstream>

#include "point3d.h"
#include "errors.h"

struct edge
{
    point3d p1;
    point3d p2;
};

typedef struct edge edge_t;

edge_t fromPoints(double x1, double y1, double z1,
                  double x2, double y2, double z2);
error_t readEdgeFromFile(edge_t &edge, std::ifstream &file);

edge_t translate(edge_t edge, point3d delta);
edge_t scale(edge_t edge, point3d factor, point3d center = {0.0, 0.0, 0.0});
edge_t rotate(edge_t edge, point3d angle, point3d center = {0.0, 0.0, 0.0});

point3d p1(edge_t edge);
point3d p2(edge_t edge);

const char *toCString(edge_t edge);

#endif // EDGE_H
