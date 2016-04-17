#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "processimage.h"
#include <QFileDialog>
#include <iostream>
#include <QGraphicsPixmapItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
    void processImage(QString imgName);
    void setDisplayImage(cv::Mat img);
    void setProcessedImage(cv::Mat imgMat);
};

#endif // MAINWINDOW_H
