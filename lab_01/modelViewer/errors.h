#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>
#include <QWidget>

enum error
{
    OK = 0,
    NO_SUCH_FILE,
    P1_FIELDS,
    P2_FIELDS,
    NOT_DOUBLE
};

typedef enum error error_t;

void showWarning(QWidget *parent, const error &error);

#endif // ERRORS_H
