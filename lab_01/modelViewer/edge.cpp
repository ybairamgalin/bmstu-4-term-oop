#include "edge.h"

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
