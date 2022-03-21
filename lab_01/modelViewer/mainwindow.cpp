#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui = uiCreate(this);
}

MainWindow::~MainWindow()
{
    uiDelete(ui);
}

