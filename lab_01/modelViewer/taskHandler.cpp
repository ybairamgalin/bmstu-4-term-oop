#include "taskHandler.h"

error_t handleTask(const task_t task)
{
    static figure_t model = figureInit();

    data_t data = task.data;
    error_t err = OK;

    switch (task.type)
    {
    case ADD_EDGE:
        err = addEdge(model, data.edge);
        break;
    case TRANSLATE:
        err = translate(model, data.point);
        break;
    case SCALE:
        err = scale(model, data.point);
        break;
    case ROTATE:
        err = rotate(model, data.point);
        break;
    case DISPLAY_EDGES:
        err = displayEdges(model, data.displayer);
        break;
    case DRAW:
        err = draw(model, data.drawer);
        break;
    case DESTROY:
        err = figureDelete(model);
        break;
    default:
        err = UNKNOWN_TASK;
    }

    return err;
}
