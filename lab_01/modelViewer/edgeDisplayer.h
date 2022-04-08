#ifndef EDGEDISPLAYER_H
#define EDGEDISPLAYER_H

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

#endif // EDGEDISPLAYER_H
