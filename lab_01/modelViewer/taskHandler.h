#ifndef TASKHANDLER_H
#define TASKHANDLER_H

#include "edge.h"
#include "point3d.h"
#include "errors.h"
#include "figure.h"
#include "drawer.h"
#include "edgeDisplayer.h"

enum taskType
{
    READ_FROM_FILE,
    SAVE_TO_FILE,
    ADD_EDGE,
    TRANSLATE,
    SCALE,
    ROTATE,
    DISPLAY_EDGES,
    DESTROY,
    DRAW
};

typedef enum taskType taskType_t;

struct task
{
    taskType type;
    union
    {
        const char *filename;
        edge_t edge;
        point3d point;
        drawer_t drawer;
        edgeDisplayer_t displayer;
    };
};

typedef struct task task_t;

error_t handleTask(const task_t task);

#endif // TASKHANDLER_H
