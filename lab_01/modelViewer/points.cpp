#include "points.h"

const static size_t startCapacity = 64;

points& pointsInit()
{
    points_t *points = new points_t;

    points->points = new point3d[startCapacity];
    points->lng = 0;
    points->capacity = startCapacity;

    return *points;
}

static void deleteFields(points_t &points)
{
    delete points.points;
}

void pointsDelete(points_t &points)
{
    deleteFields(points);
    delete &points;
}

static void resize(point3d *&points, const size_t lng,
                   size_t &capacity)
{
    point3d *newPoints = new point3d[capacity * 2];
    memcpy(newPoints, points, sizeof(point3d) * lng);

    delete points;

    points = newPoints;
    capacity *= 2;
}

void addPoint(points_t &points, point3d point)
{
    // TODO ADD EXIST CHECK

    if (points.lng + 1 >= points.capacity)
        resize(points.points, points.lng, points.capacity);

    points.points[points.lng++] = point;
}

size_t getLng(points_t &points)
{
    return points.lng;
}

point3d getPoint(points_t &points, size_t index)
{
    if (index >= points.lng)
        return point3d{0, 0, 0};

    return points.points[index];
}

size_t index(points_t &points, point3d point, error_t &err)
{
    size_t index = 0;
    bool found = false;
    err = OK;

    for (size_t i = 0; i < points.lng && !found; i++)
        if (equal(points.points[i], point))
        {
            index = i;
            found = true;
        }

    if (!found)
        err = POINT_NOT_FOUND;

    return index;
}

void translate(points_t &points, point3d delta)
{
    for (size_t i = 0; i < points.lng; i++)
        points.points[i] = translate(points.points[i], delta);
}

void scale(points_t &points, point3d factor)
{
    for (size_t i = 0; i < points.lng; i++)
        points.points[i] = scale(points.points[i], factor);
}

void rotate(points_t &points, point3d angle)
{
    for (size_t i = 0; i < points.lng; i++)
        points.points[i] = rotate(points.points[i], angle);
}
