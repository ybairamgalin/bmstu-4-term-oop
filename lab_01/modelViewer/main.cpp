#include <QApplication>
#include "taskHandler.h"

const char *filename = "../../../../modelViewer/figure_1.txt";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    task_t startTask{START_UP, {filename}};
    handleTask(startTask);
    return a.exec();
}
