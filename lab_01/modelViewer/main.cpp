#include <QApplication>
#include "mainwindow.h"
#include "taskHandler.h"

const char *filename = "../../../../modelViewer/figure_1.txt";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();

    return a.exec();
}
