#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>

#include "taskHandler.h"
#include "ui.h"
#include "figure.h"
#include "edge.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    ui_t *ui;

    const QSize minWindowSize = QSize(1300, 800);
    void connectButtons();
    error_t updateView(taskType_t type, data_t &data);
    static void mbWarning(const std::string str);

private slots:
    void onAddEdgeButtonClick();
    void onTranslateButtonClick();
    void onScaleButtonClick();
    void onRotateButtonCLick();
};

#endif // MAINWINDOW_H
