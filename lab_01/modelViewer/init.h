#ifndef INIT_H
#define INIT_H

#include "figure.h"
#include "mainwindow.h"

error_t createApp(figure_t **model, const char *filename);

error_t destroyApp(figure_t &model);

#endif // INIT_H
