#ifndef POINT3D_H
#define POINT3D_H

#include <QString>
#include <string.h>
#include <math.h>

struct point3d
{
    double x;
    double y;
    double z;
};

point3d *point3dCreate(const double x, const double y,
                       const double z);
void point3dDelete(point3d &point);

void point3dSetX(point3d &point, const double x);
double point3dGetX(const point3d &point);

void point3dSetY(point3d &point, const double y);
double point3dGetY(const point3d &point);

void point3dSetZ(point3d &point, const double z);
double point3dGetZ(const point3d &point);

point3d translate(point3d point, point3d delta);
point3d scale(point3d point, point3d factor, point3d center = {0, 0, 0});
point3d rotate(point3d point, point3d angle, point3d center = {0, 0, 0});

point3d neg(const point3d point);
bool equal(point3d first, point3d second);

std::string toString(point3d point);

#endif // POINT3D_H
