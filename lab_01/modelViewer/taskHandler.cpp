#include "taskHandler.h"

error_t handleTask(task_t task)
{
    static figure_t model = figureInit();

    error_t err = OK;

    switch (task.type)
    {
    case READ_FROM_FILE:
        err = readFigureFromFile(model, task.filename);
        break;
    case SAVE_TO_FILE:
        err = saveFigureToFile(model, task.filename);
        break;
    case ADD_EDGE:
        err = addEdge(model, task.edge);
        break;
    case TRANSLATE:
        err = translate(model, task.point);
        break;
    case SCALE:
        err = scale(model, task.point);
        break;
    case ROTATE:
        err = rotate(model, task.point);
        break;
    case DISPLAY_EDGES:
        err = displayEdges(model, task.displayer);
        break;
    case DRAW:
        err = draw(model, task.drawer);
        break;
    case DESTROY:
        err = figureDelete(model);
        break;
    default:
        err = UNKNOWN_TASK;
    }

    return err;
}
