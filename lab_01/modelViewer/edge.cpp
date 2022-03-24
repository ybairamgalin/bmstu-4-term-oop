#include "edge.h"

edge_t edgeInit(const point3d p1, const point3d p2)
{
    edge_t edge = { p1, p2 };

    return edge;
}
