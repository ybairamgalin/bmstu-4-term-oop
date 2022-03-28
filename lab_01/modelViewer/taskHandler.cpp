#include "taskHandler.h"

static figure_t *model = nullptr;
static MainWindow *view = nullptr;

void handleTask(task_t task)
{
    data_t data = task.data;

    switch (task.type)
    {
    case START_UP:
        model = figureCreate(data.filename);
        view = new MainWindow;
        view->show();
        break;
    case ADD_EDGE:
        addEdge(*model, data.edge);
        break;
    case TRANSLATE:
        translate(*model, data.point);
        break;
    case SCALE:
        scale(*model, data.point);
        break;
    case ROTATE:
        rotate(*model, data.point);
        break;
    }

    view->updateView(*model);
}
