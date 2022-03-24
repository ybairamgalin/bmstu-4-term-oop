#include "renderArea.h"

static void drawBg(renderArea &renderArea)
{
    renderArea.scene->addLine(point2dGetX(*(renderArea.center)),
                              point2dGetY(*(renderArea.center)),
                              point2dGetX(*(renderArea.vectorX)),
                              point2dGetY(*(renderArea.vectorX)));

    renderArea.scene->addLine(point2dGetX(*(renderArea.center)),
                              point2dGetY(*(renderArea.center)),
                              point2dGetX(*(renderArea.vectorY)),
                              point2dGetY(*(renderArea.vectorY)));

    renderArea.scene->addLine(point2dGetX(*(renderArea.center)),
                              point2dGetY(*(renderArea.center)),
                              point2dGetX(*(renderArea.vectorZ)),
                              point2dGetY(*(renderArea.vectorZ)));
}


renderArea_t *renderAreaCreate()
{
    renderArea_t *renderArea = new renderArea_t;

    renderArea->paintWidget = new QGraphicsView;
    renderArea->scene = new QGraphicsScene;

    // TODO ADD CONSTS
    renderArea->center = point2dCreate(0, 0);
    renderArea->vectorX = point2dCreate(100, 0);
    renderArea->vectorY = point2dCreate(0, 100);
    renderArea->vectorZ = point2dCreate(-70, -70);

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
