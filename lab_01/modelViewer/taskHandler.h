#ifndef TASKHANDLER_H
#define TASKHANDLER_H

#include "edge.h"
#include "point3d.h"
#include "errors.h"
#include "figure.h"
#include "drawer.h"

enum taskType
{
    START_UP,
    ADD_EDGE,
    TRANSLATE,
    SCALE,
    ROTATE,
    DESTROY,
    DRAW
};

typedef enum taskType taskType_t;

union data
{
    const char *filename;
    edge_t edge;
    point3d point;
    drawer_t drawer;
};

typedef union data data_t;

struct task
{
    taskType type;
    data data;
};

typedef struct task task_t;

error_t handleTask(const task_t task);

#endif // TASKHANDLER_H
