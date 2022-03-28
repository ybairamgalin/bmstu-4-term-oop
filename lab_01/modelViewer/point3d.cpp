#include "point3d.h"

point3d point3dInit(const double x, const double y,
                    const double z)
{
    point3d point = {x, y, z};

    return point;
}

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

point3d translate(point3d point, point3d delta)
{
    return point3d{point.x + delta.x, point.y + delta.y, point.z + delta.z};
}

point3d scale(point3d point, point3d factor, point3d center)
{
    point3d result;
    result.x = point.x * factor.x;
    result.y = point.y * factor.y;
    result.z = point.z * factor.z;

    return result;
}

static point3d rotateX(const point3d point, const double angle,
                       const point3d center)
{
    double angleRad = angle * M_PI / 180.0;

    point3d result;
    result.x = point.x;
    result.y = point.y * cos(angleRad) - point.z * sin(angleRad);
    result.z = point.z * cos(angleRad) + point.y * sin(angleRad);

    return result;
}

static point3d rotateY(const point3d point, const double angle,
                       const point3d center)
{
    double angleRad = angle * M_PI / 180.0;

    point3d result;
    result.x = point.x * cos(angleRad) - point.z * sin(angleRad);
    result.y = point.y;
    result.z = point.z * cos(angleRad) + point.x * sin(angleRad);

    return result;
}

static point3d rotateZ(const point3d point, const double angle,
                       const point3d center)
{
    double angleRad = angle * M_PI / 180.0;

    point3d result;
    result.x = point.x * cos(angleRad) - point.y * sin(angleRad);
    result.y = point.y * cos(angleRad) + point.x * sin(angleRad);
    result.z = point.z;

    return result;
}

point3d rotate(point3d point, point3d angle, point3d center)
{
    point3d result;
    result = rotateX(point, angle.x, center);
    result = rotateY(result, angle.y, center);
    result = rotateZ(result, angle.z, center);

    return result;
}

QString toQString(point3d point)
{
    return "(" + QString::number(point.x) + ", " +
                 QString::number(point.y) + ", " +
                 QString::number(point.z) + "" + ")";
}
