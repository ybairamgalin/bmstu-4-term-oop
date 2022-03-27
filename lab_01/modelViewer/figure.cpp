#include "figure.h"

static error readFigureFromFile(const char *filename, figure_t &figure)
{
    system("pwd");

    FILE *file = fopen(filename, "r");

    if (!file)
        return NO_SUCH_FILE;

    double x1, y1, z1, x2, y2, z2;

    while (fscanf(file, "%lf%lf%lf%lf%lf%lf", &x1, &y1, &z1,
                   &x2, &y2, &z2) == 6)
        figure.edges[figure.lng++] = edge{point3d{x1, y1, z1},
                                          point3d{x2, y2, z2}};

    return OK;
}

figure_t *figureCreate(const char *filename)
{
    figure_t *figure = new figure_t;
    figure->lng = 0;

    if (!filename)
        return figure;

    error err = readFigureFromFile(filename, *figure);

    if (err != OK)
    {
        delete figure;
        return nullptr;
    }

    return figure;
}

void addEdge(figure_t &figure, const edge &edge)
{
    // TODO ADD CHECK
    figure.edges[figure.lng++] = edge;
}

void translate(figure_t &figure, point3d delta)
{
    for (int i =  0; i < figure.lng; i++)
        figure.edges[i] = translate(figure.edges[i], delta);
}

void scale(figure_t &figure, point3d factor)
{
    for (int i =  0; i < figure.lng; i++)
        figure.edges[i] = scale(figure.edges[i], factor);
}

void rotate(figure_t &figure, point3d angle)
{
    for (int i =  0; i < figure.lng; i++)
        figure.edges[i] = rotate(figure.edges[i], angle);
}
