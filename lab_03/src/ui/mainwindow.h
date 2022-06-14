#ifndef LAB_03_MAINWINDOW_H
#define LAB_03_MAINWINDOW_H

#include <QMainWindow>

#include "../facade/facade.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    std::shared_ptr<Ui::MainWindow> _ui;
};

#endif //LAB_03_MAINWINDOW_H
