#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    figure_t *figure;

    const QSize minWindowSize = QSize(1300, 800);
private slots:
    void onAddEdgeButtonClick();
    void onDeleteEdgeButtonCLick();
    void onTranslateButtonClick();
    void onScaleButtonClick();
    void onRotateButtonCLick();
};
#endif // MAINWINDOW_H
