#include "edge.h"

edge_t edgeInit(const point3d p1, const point3d p2)
{
    edge_t edge = { p1, p2 };

    return edge;
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

edge_t scale(edge_t edge, point3d factor)
{
    return edge_t{scale(edge.p1, factor),
                  scale(edge.p2, factor)};
}
