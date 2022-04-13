#ifndef EDGEDISPLAYER_H
#define EDGEDISPLAYER_H

#include "errors.h"

struct edge;
struct editorDock;

typedef void (*displayCleaner)(editorDock &dock);
typedef void (*edgeAdder)(editorDock &dock, edge edge);

struct edgeDisplayer
{
    editorDock *display;
    displayCleaner cleaner;
    edgeAdder adder;
};

typedef struct edgeDisplayer edgeDisplayer_t;

void displayEdge(edgeDisplayer_t &displayer, edge edge);
error_t cleanDisplay(edgeDisplayer_t &displayer);

#endif // EDGEDISPLAYER_H
