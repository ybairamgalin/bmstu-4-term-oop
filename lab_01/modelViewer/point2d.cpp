#include <point2d.h>

point2d *point2dCreate(double x, double y)
{
    point2d *point = new point2d;

    point->x = x;
    point->y = y;

    return point;
}

void point2dDelete(point2d &point)
{
    delete &point;
}

double point2dGetX(point2d &point)
{
    return point.x;
}

double point2dGetY(point2d &point)
{
    return point.y;
}

point2d mul(point2d &point, double num)
{
    return point2d{point.x * num, point.y * num};
}

point2d add(point2d &p1, point2d &p2)
{
    return point2d{p1.x + p2.x, p1.y + p2.y};
}
