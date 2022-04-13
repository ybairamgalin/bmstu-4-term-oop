#ifndef POINTS_H
#define POINTS_H

#include "point3d.h"
#include "errors.h"

#ifndef START_POINTS_CAPACITY
#define START_POINTS_CAPACITY 32
#endif

struct points
{
    point3d *points;
    size_t lng;
    size_t capacity;
};

typedef struct points points_t;

points_t &pointsInit();
void pointsDelete(points_t &);

void addPoint(points_t &points, point3d point);
point3d getPoint(points_t &points, size_t index);
size_t getLng(points_t &points);

size_t index(points_t &points, point3d point, error_t &err);

void translate(points_t &points, point3d delta);
void scale(points_t &points, point3d factor);
void rotate(points_t &points, point3d angle);

#endif // POINTS_H
