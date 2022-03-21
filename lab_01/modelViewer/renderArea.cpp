#include "renderArea.h"

renderArea_t *renderAreaCreate()
{
    renderArea_t *renderArea = new renderArea_t;

    renderArea->paintArea = new QWidget;

    return renderArea;
}

QWidget *getPaintArea(renderArea_t *renderArea)
{
    return renderArea->paintArea;
}
