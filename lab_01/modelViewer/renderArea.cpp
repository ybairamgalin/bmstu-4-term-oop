#include "renderArea.h"

const static int centerX = 0;
const static int centerY = 0;
const static int vectorXdx = 100;
const static int vectorXdy = 0;
const static int vectorYdx = -70;
const static int vectorYdy = -70;
const static int vectorZdx = 0;
const static int vectorZdy = 100;

static void drawLine(renderArea &renderArea,
                     point2d p1, point2d p2)
{
    renderArea.scene->addLine(point2dGetX(p1), point2dGetY(p1),
                              point2dGetX(p2), point2dGetY(p2));
}

static void clearAll(renderArea &renderArea)
{
    renderArea.scene->clear();
}

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

//static void drawFigure(renderArea &renderArea, const figure_t &figure)
//{
//    for (int i = 0; i < figure.lng; i++)
//    {
//        point2d p1 = to2d(renderArea, figure.edges[i].p1);
//        point2d p2 = to2d(renderArea, figure.edges[i].p2);

//        renderArea.scene->addLine(point2dGetX(p1), point2dGetY(p1),
//                                  point2dGetX(p2), point2dGetY(p2));
//    }
//}

renderArea_t *renderAreaCreate()
{
    renderArea_t *renderArea = new renderArea_t;

    renderArea->paintWidget = new QGraphicsView;
    renderArea->scene = new QGraphicsScene;

    renderArea->center = point2dCreate(centerX, centerY);
    renderArea->vectorX = point2dCreate(vectorXdx, vectorXdy);
    renderArea->vectorY = point2dCreate(vectorYdx, vectorYdy);
    renderArea->vectorZ = point2dCreate(vectorZdx, vectorZdy);

    renderArea->scene->setSceneRect(QRectF(0, 0, 1, 1));
//    drawBg(*renderArea);

    renderArea->paintWidget->setScene(renderArea->scene);
    renderArea->paintWidget->scale(1, -1);

    return renderArea;
}

void renderAreaDelete(renderArea &renderArea)
{
    point2dDelete(*renderArea.center);
    point2dDelete(*renderArea.vectorX);
    point2dDelete(*renderArea.vectorY);
    point2dDelete(*renderArea.vectorZ);
    delete renderArea.scene;
    delete &renderArea;
}

QWidget *getPaintWidget(renderArea_t *renderArea)
{
    return renderArea->paintWidget;
}

//void renderAreaUpdate(renderArea &renderArea, const figure_t &figure)
//{
//    renderArea.scene->clear();
//    drawBg(renderArea);
//    drawFigure(renderArea, figure);
//}

drawer_t getDrawer(renderArea &renderArea)
{
    return drawer_t{&renderArea, drawLine, clearAll};
}
