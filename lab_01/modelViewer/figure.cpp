#include "figure.h"

figure_t *figureCreate()
{
    figure_t *figure = new figure_t;

    figure->lng = 0;

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
