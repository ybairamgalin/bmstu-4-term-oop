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
    figure.points = pointsInit();
    figure.connections = connectionsInit();
    figure.basis = basisInit();
}

figure_t &figureInit()
{
    figure_t *figure = new figure_t;
    setInitValues(*figure);

    return *figure;
}

static void deleteFields(figure_t &figure)
{
    pointsDelete(figure.points);
    connectionsDelete(figure.connections);
}

error_t figureDelete(figure_t &figure)
{
    deleteFields(figure);
    delete &figure;

    return OK;
}

error_t addEdge(figure_t &figure, const edge &edge)
{
    addPoint(figure.points, p1(edge));
    addPoint(figure.points, p2(edge));

    error_t err = OK;
    size_t firstIndex = index(figure.points, p1(edge), err);
    size_t secondIndex = index(figure.points, p2(edge), err);

    if (firstIndex == secondIndex)
        return NOT_EDGE;

    addConnection(figure.connections,
                  connection{firstIndex, secondIndex});

//    if (figure.lng >= MAX_FIGURE_EDGES)
//        return MAX_EDGES;

//    figure.edges[figure.lng++] = edge;

    return OK;
}

error_t translate(figure_t &figure, point3d delta)
{
    translate(figure.points, delta);

    return OK;
}

error_t scale(figure_t &figure, point3d factor)
{
    scale(figure.points, factor);

    return OK;
}

error_t rotate(figure_t &figure, point3d angle)
{
    rotate(figure.points, angle);

    return OK;
}

//int getLng(const figure_t &figure)
//{
//    return figure.lng;
//}

//edge_t getEdge(const figure_t &figure, const int index)
//{
//    return figure.edges[index];
//}

error_t draw(figure_t &figure, drawer_t &drawer)
{
    error_t err = OK;
    err = clearAll(drawer);

    if (err)
        return err;

    for (size_t i = 0; i < getLng(figure.connections) && !err; i++)
    {
        point3d p1 = getPoint(figure.points,
                              getConnectionP1(figure.connections, i));
        point3d p2 = getPoint(figure.points,
                              getConnectionP2(figure.connections, i));

        err = drawEdge(figure.basis, edge{p1, p2}, drawer);
    }

    return err;
}

error_t displayEdges(figure_t &figure, edgeDisplayer_t &displayer)
{
    error_t err = OK;
    err = cleanDisplay(displayer);

    displayer.cleaner(*(displayer.display));

    if (err)
        return err;

    for (size_t i = 0; i < getLng(figure.connections); i++)
    {
        point3d p1 = getPoint(figure.points,
                              getConnectionP1(figure.connections, i));
        point3d p2 = getPoint(figure.points,
                              getConnectionP2(figure.connections, i));

        displayEdge(displayer, edge{p1, p2});
    }

    return OK;
}
