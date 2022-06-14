#include "mainwindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent)
{
    _ui = std::make_shared<Ui::MainWindow>();
    _ui->setupUi(this);
}

MainWindow::~MainWindow() { }
