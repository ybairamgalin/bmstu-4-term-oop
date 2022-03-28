#ifndef TASKHANDLER_H
#define TASKHANDLER_H

#include "edge.h"
#include "point3d.h"
#include "errors.h"
#include "figure.h"
#include "mainwindow.h"

enum taskType
{
    START_UP,
    ADD_EDGE,
    TRANSLATE,
    SCALE,
    ROTATE
};

union data
{
    const char *filename;
    edge_t edge;
    point3d point;
};

typedef union data data_t;

struct task
{
    taskType type;
    data data;
};

typedef struct task task_t;

void handleTask(task_t task);

#endif // TASKHANDLER_H
