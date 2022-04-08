#include "figure.h"

const static int startVectorXdx = 100;
const static int startVectorXdy = 0;
const static int startVectorYdx = -70;
const static int startVectorYdy = -70;
const static int startVectorZdx = 0;
const static int startVectorZdy = 100;

error readFigureFromFile(figure_t &figure, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (!file)
        return NO_SUCH_FILE;

    figure_t old = figure;
    double x1, y1, z1, x2, y2, z2;
    error_t err = OK;

    while (fscanf(file, "%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1,
                   &x2, &y2, &z2) == 6 && !err)
        err = addEdge(figure, edge{point3d{x1, y1, z1},
                              point3d{x2, y2, z2}});

    if (err)
        figure = old;

    return err;
}

static point2d to2d(basis_t &basis, point3d point)
{
    point2d newX = mul(basis.vectorX, point3dGetX(point));
    point2d newY = mul(basis.vectorY, point3dGetY(point));
    point2d newZ = mul(basis.vectorZ, point3dGetZ(point));

    point2d result = add(newX, newY);
    result = add(result, newZ);

    return result;
}

static error_t drawEdge(basis_t &basis, edge_t edge, drawer_t &drawer)
{
    if (!drawer.lineDrawer)
        return NO_DRAWER_SET;

    point2d first = to2d(basis, p1(edge));
    point2d second = to2d(basis, p2(edge));

    drawer.lineDrawer(*(drawer.canvas), first, second);

    return OK;
}

static error_t clearAll(drawer_t drawer)
{
    if (!drawer.cleaner)
        return NO_CLEANER_SET;

    drawer.cleaner(*drawer.canvas);

    return OK;
}

static basis_t basisInit()
{
    basis_t basis;

    basis.vectorX = point2d{startVectorXdx, startVectorXdy};
    basis.vectorY = point2d{startVectorYdx, startVectorYdy};
    basis.vectorZ = point2d{startVectorZdx, startVectorZdy};

    return basis;
}

static void setInitValues(figure &figure)
{
    figure.lng = 0;
    figure.basis = basisInit();
}

figure_t &figureInit()
{
    figure_t *figure = new figure_t;
    setInitValues(*figure);

    return *figure;
}

error_t figureDelete(figure_t &figure)
{
    delete &figure;

    return OK;
}

error_t addEdge(figure_t &figure, const edge &edge)
{
    if (figure.lng >= MAX_FIGURE_EDGES)
        return MAX_EDGES;

    figure.edges[figure.lng++] = edge;

    return OK;
}

error_t translate(figure_t &figure, point3d delta)
{
    for (int i = 0; i < figure.lng; i++)
        figure.edges[i] = translate(figure.edges[i], delta);

    return OK;
}

error_t scale(figure_t &figure, point3d factor)
{
    for (int i =  0; i < figure.lng; i++)
        figure.edges[i] = scale(figure.edges[i], factor);

    return OK;
}

error_t rotate(figure_t &figure, point3d angle)
{
    for (int i =  0; i < figure.lng; i++)
        figure.edges[i] = rotate(figure.edges[i], angle);

    return OK;
}

int getLng(const figure_t &figure)
{
    return figure.lng;
}

edge_t getEdge(const figure_t &figure, const int index)
{
    return figure.edges[index];
}

error_t draw(figure_t &figure, drawer_t &drawer)
{
    error_t err = OK;
    err = clearAll(drawer);

    if (err)
        return err;

    for (int i = 0; i < figure.lng && !err; i++)
        err = drawEdge(figure.basis, figure.edges[i], drawer);

    return OK;
}

static error_t clearDisplay(edgeDisplayer_t &displayer)
{
    if (!displayer.cleaner)
        return NO_DISP_CLEANER_SET;

    displayer.cleaner(*(displayer.display));

    return OK;
}

error_t displayEdges(figure_t &figure, edgeDisplayer_t &displayer)
{
    error_t err = OK;
    err = clearDisplay(displayer);

    if (err)
        return err;

    for (int i = 0; i < figure.lng; i++)
        displayer.adder(*(displayer.display), figure.edges[i]);

    return OK;
}
