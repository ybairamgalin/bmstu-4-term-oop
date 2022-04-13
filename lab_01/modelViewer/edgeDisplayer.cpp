#include "edgeDisplayer.h"
#include "edge.h"

void displayEdge(edgeDisplayer_t &displayer, edge edge)
{
    displayer.adder(*(displayer.display), edge);
}

error_t cleanDisplay(edgeDisplayer_t &displayer)
{
    if (!displayer.cleaner)
        return NO_DISP_CLEANER_SET;

    displayer.cleaner(*(displayer.display));

    return OK;
}
