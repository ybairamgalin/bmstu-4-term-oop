#include "drawer.h"
#include "figure.h"
#include "edge.h"

static point2d to2d(basis_t &basis, point3d point)
{
    point2d newX = mul(basis.vectorX, point3dGetX(point));
    point2d newY = mul(basis.vectorY, point3dGetY(point));
    point2d newZ = mul(basis.vectorZ, point3dGetZ(point));

    point2d result = add(newX, newY);
    result = add(result, newZ);

    return result;
}

error_t clearAll(drawer_t drawer)
{
    if (!drawer.cleaner)
        return NO_CLEANER_SET;

    drawer.cleaner(*drawer.canvas);

    return OK;
}

error_t drawEdge(basis_t &basis, edge_t edge, drawer_t &drawer)
{
    if (!drawer.lineDrawer)
        return NO_DRAWER_SET;

    point2d first = to2d(basis, p1(edge));
    point2d second = to2d(basis, p2(edge));

    drawer.lineDrawer(*(drawer.canvas), first, second);

    return OK;
}
