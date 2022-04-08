#include "taskHandler.h"
#include "figure.h"
#include "init.h"

error_t handleTask(const task_t task)
{
    static figure_t model = figureInit();

    data_t data = task.data;
    error_t err = OK;

    switch (task.type)
    {
    case START_UP:
        err = readFigureFromFile(model, data.filename);
        break;
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
