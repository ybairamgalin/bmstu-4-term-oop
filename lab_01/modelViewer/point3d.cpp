#include "point3d.h"

point3d *point3dCreate(const double x, const double y,
                       const double z)
{
    point3d *point = new point3d;

    point->x = x;
    point->y = y;
    point->z = z;

    return point;
}

void point3dDelete(point3d &point)
{
    delete &point;
}

void point3dSetX(point3d &point, const double x)
{
    point.x = x;
}

double point3dGetX(const point3d &point)
{
    return point.x;
}

void point3dSetY(point3d &point, const double y)
{
    point.y = y;
}

double point3dGetY(const point3d &point)
{
    return point.y;
}

void point3dSetZ(point3d &point, const double z)
{
    point.z = z;
}

double point3dGetZ(const point3d &point)
{
    return point.z;
}
