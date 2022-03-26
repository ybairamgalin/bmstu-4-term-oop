#include "renderArea.h"

static void drawBg(renderArea &renderArea)
{
    renderArea.scene->addLine(point2dGetX(*(renderArea.center)),
                              point2dGetY(*(renderArea.center)),
                              point2dGetX(*(renderArea.vectorX)),
                              point2dGetY(*(renderArea.vectorX)),
                              QPen(QColor(Qt::red)));

    renderArea.scene->addLine(point2dGetX(*(renderArea.center)),
                              point2dGetY(*(renderArea.center)),
                              point2dGetX(*(renderArea.vectorY)),
                              point2dGetY(*(renderArea.vectorY)),
                              QPen(QColor(Qt::green)));

    renderArea.scene->addLine(point2dGetX(*(renderArea.center)),
                              point2dGetY(*(renderArea.center)),
                              point2dGetX(*(renderArea.vectorZ)),
                              point2dGetY(*(renderArea.vectorZ)),
                              QPen(QColor(Qt::blue)));
}

static point2d to2d(renderArea &renderArea, point3d point)
{
    point2d newX = mul(*(renderArea.vectorX), point3dGetX(point));
    point2d newY = mul(*(renderArea.vectorY), point3dGetY(point));
    point2d newZ = mul(*(renderArea.vectorZ), point3dGetZ(point));

    point2d result = add(newX, newY);
    result = add(result, newZ);

    return result;
}

static void drawFigure(renderArea &renderArea, figure_t &figure)
{

}

renderArea_t *renderAreaCreate()
{
    renderArea_t *renderArea = new renderArea_t;

    renderArea->paintWidget = new QGraphicsView;
    renderArea->scene = new QGraphicsScene;

    // TODO ADD CONSTS
    renderArea->center = point2dCreate(0, 0);
    renderArea->vectorX = point2dCreate(100, 0);
    renderArea->vectorY = point2dCreate(-70, -70);
    renderArea->vectorZ = point2dCreate(0, 100);

    renderArea->scene->setSceneRect(QRectF(0, 0, 1, 1));
    drawBg(*renderArea);

    renderArea->paintWidget->setScene(renderArea->scene);
    renderArea->paintWidget->scale(1, -1);

    return renderArea;
}

void renderAreaDelete(renderArea &renderArea)
{
    // TODO
}

QWidget *getPaintWidget(renderArea_t *renderArea)
{
    return renderArea->paintWidget;
}

void renderAreaUpdate(renderArea &renderArea, const figure_t &figure)
{
    renderArea.scene->clear();
    drawBg(renderArea);

    for (int i = 0; i < figure.lng; i++)
    {
        point2d p1 = to2d(renderArea, figure.edges[i].p1);
        point2d p2 = to2d(renderArea, figure.edges[i].p2);

        renderArea.scene->addLine(point2dGetX(p1), point2dGetY(p1),
                                  point2dGetX(p2), point2dGetY(p2));
    }
}
