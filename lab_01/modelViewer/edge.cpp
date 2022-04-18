#include "edge.h"

edge_t fromPoints(double x1, double y1, double z1,
                  double x2, double y2, double z2)
{
    return edge_t{point3d{x1, y1, z1}, point3d{x2, y2, z2}};
}

error_t readEdgeFromFile(edge_t &edge, std::ifstream &file)
{
    if (!file.is_open())
        return NO_SUCH_FILE;

    error_t err = OK;
    point3d p1, p2;

    err = readPointFromFile(p1, file);

    if (err == READ_ERR)
        err = END_OF_FILE;

    if (!err)
        readPointFromFile(p2, file);

    if (!err)
        edge = edge_t{p1, p2};

    return err;
}

edge_t translate(edge_t edge, point3d delta)
{
    return edge_t{translate(edge.p1, delta),
                  translate(edge.p2, delta)};
}

edge_t rotate(edge_t edge, point3d angle, point3d center)
{
    return edge_t{rotate(edge.p1, angle, center),
                  rotate(edge.p2, angle, center)};
}

edge_t scale(edge_t edge, point3d factor, point3d center)
{
    return edge_t{scale(edge.p1, factor, center),
                  scale(edge.p2, factor, center)};
}

point3d p1(edge_t edge)
{
    return edge.p1;
}

point3d p2(edge_t edge)
{
    return edge.p2;
}

const char *toCString(edge_t edge)
{
    static char buf[64];
    snprintf(buf, sizeof(buf), "%lf %lf %lf %lf %lf %lf",
             point3dGetX(edge.p1), point3dGetY(edge.p1), point3dGetZ(edge.p1),
             point3dGetX(edge.p2), point3dGetY(edge.p2), point3dGetZ(edge.p2));

    return buf;
}
