#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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

    void updateView(figure_t &model);
private:
    ui_t *ui;

    const QSize minWindowSize = QSize(1300, 800);
private slots:
    void onAddEdgeButtonClick();
    void onDeleteEdgeButtonCLick();
    void onTranslateButtonClick();
    void onScaleButtonClick();
    void onRotateButtonCLick();
};

#endif // MAINWINDOW_H
