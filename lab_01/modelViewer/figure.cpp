#include "figure.h"

const static int startVectorXdx = 100;
const static int startVectorXdy = 0;
const static int startVectorYdx = -70;
const static int startVectorYdy = -70;
const static int startVectorZdx = 0;
const static int startVectorZdy = 100;

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

static void move(figure_t &dest, figure_t &source)
{
    deleteFields(dest);
    dest = source;
    delete &source;
}


static edge_t getEdge(points_t &points, connections_t &cons,
                      size_t index, error_t &err)
{
    if (index >= getLng(cons))
    {
        err = INDEX_TOO_HIGH;
        return edge{point3d{0, 0, 0}, point3d{0, 0, 0}};
    }

    point3d p1 = getPoint(points, getConnectionP1(cons, index));
    point3d p2 = getPoint(points, getConnectionP2(cons, index));

    err = OK;
    return edge{p1, p2};
}

error readFigureFromFile(figure_t &figure, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (!file)
        return NO_SUCH_FILE;

    figure_t &newFigure = figureInit();
    double x1, y1, z1, x2, y2, z2;
    error_t err = OK;

    while (fscanf(file, "%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1,
                   &x2, &y2, &z2) == 6 && !err)
        err = addEdge(newFigure, edge{point3d{x1, y1, z1},
                                      point3d{x2, y2, z2}});

    fclose(file);

    if (err)
    {
        figureDelete(newFigure);
        return err;
    }

    move(figure, newFigure);
    return err;
}

error saveFigureToFile(figure &figure, const char *filename)
{
    error_t err = OK;
    FILE *file = fopen(filename, "w");

    if (!file)
        return NO_SUCH_FILE;

    for (size_t i = 0; i < getLng(figure.connections); i++)
    {
        edge_t edge = getEdge(figure.points, figure.connections, i, err);

        if (!err)
            fprintf(file, "%s\n", toCString(edge));
    }

    fclose(file);

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

error_t addEdge(figure_t &figure, const edge &edge)
{
    addPoint(figure.points, p1(edge));
    addPoint(figure.points, p2(edge));

    error_t err = OK;
    size_t firstIndex = index(figure.points, p1(edge), err);

    if (err)
        return err;

    size_t secondIndex = index(figure.points, p2(edge), err);

    if (err)
        return err;

    if (firstIndex == secondIndex)
        return NOT_EDGE;

    addConnection(figure.connections,
                  connection{firstIndex, secondIndex});

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

error_t draw(figure_t &figure, drawer_t &drawer)
{
    error_t err = OK;
    err = clearAll(drawer);

    if (err)
        return err;

    for (size_t i = 0; i < getLng(figure.connections) && !err; i++)
    {
        edge_t edge = getEdge(figure.points, figure.connections, i, err);

        if (!err)
            err = drawEdge(figure.basis, edge, drawer);
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

    for (size_t i = 0; i < getLng(figure.connections) && !err; i++)
    {
        edge_t edge = getEdge(figure.points, figure.connections, i, err);

        if (!err)
            displayEdge(displayer, edge);
    }

    return OK;
}
