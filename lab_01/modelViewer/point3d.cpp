#include "point3d.h"

static inline double toRad(const double degrees)
{
    return degrees * M_PI / 180.0;
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
    point3d translated = translate(point, neg(center));
    point3d result;

    result.x = translated.x * factor.x;
    result.y = translated.y * factor.y;
    result.z = translated.z * factor.z;

    result = translate(result, center);

    return result;
}

static point3d rotateX(const point3d point, const double angle)
{
    double angleRad = toRad(angle);

    point3d result;
    result.x = point.x;
    result.y = point.y * cos(angleRad) - point.z * sin(angleRad);
    result.z = point.z * cos(angleRad) + point.y * sin(angleRad);

    return result;
}

static point3d rotateY(const point3d point, const double angle)
{
    double angleRad = toRad(angle);

    point3d result;
    result.x = point.x * cos(angleRad) - point.z * sin(angleRad);
    result.y = point.y;
    result.z = point.z * cos(angleRad) + point.x * sin(angleRad);

    return result;
}

static point3d rotateZ(const point3d point, const double angle)
{
    double angleRad = toRad(angle);

    point3d result;
    result.x = point.x * cos(angleRad) - point.y * sin(angleRad);
    result.y = point.y * cos(angleRad) + point.x * sin(angleRad);
    result.z = point.z;

    return result;
}

point3d rotate(point3d point, point3d angle, point3d center)
{
    point3d result = translate(point, neg(center));

    result = rotateX(result, angle.x);
    result = rotateY(result, angle.y);
    result = rotateZ(result, angle.z);

    result = translate(result, center);

    return result;
}

std::string toString(point3d point)
{
    return "(" + std::to_string(point.x).substr(0, 5) + ", " +
                 std::to_string(point.y).substr(0, 5) + ", " +
                 std::to_string(point.z).substr(0, 5) + ")";
}

point3d neg(const point3d point)
{
    return point3d{-point.x, -point.y, -point.z};
}

bool equal(point3d first, point3d second, double eps)
{
    return std::abs(first.x - second.x) < eps &&
           std::abs(first.y - second.y) < eps &&
           std::abs(first.z - second.z) < eps;
}
