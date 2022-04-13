#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>
#include <QWidget>

enum error
{
    OK = 0,
    NO_SUCH_FILE,
    MAX_EDGES,
    P1_FIELDS,
    P2_FIELDS,
    NOT_DOUBLE,
    NO_DRAWER_SET,
    NO_CLEANER_SET,
    NO_DISP_CLEANER_SET,
    NO_DISP_ADDER_SET,
    NOT_EDGE,
    POINT_NOT_FOUND,
    UNKNOWN_TASK
};

typedef enum error error_t;

void showWarning(QWidget *parent, const error &error);

#endif // ERRORS_H
