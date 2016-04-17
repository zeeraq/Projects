#include "mainwindow.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("Select Image"),
                QDir::homePath(),
                tr("Image Files (*.png *.jpg)")
                );
    cout << "Selected file "<<fileName.toStdString() << endl;
    processImage(fileName);
}

void MainWindow::setDisplayImage(cv::Mat imgMat)
{
    cout << "image type " << imgMat.type() <<" rows " << imgMat.rows << " cols " << imgMat.cols << endl;
    cv::Mat resized;
    cv::resize(imgMat, resized, cv::Size(ui->displayLabel->width(),ui->displayLabel->height()),0,0, cv::INTER_CUBIC);
    QImage img = QImage((uchar*)resized.data, resized.cols, resized.rows, resized.step, QImage::Format_RGB888);
    ui->displayLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::setProcessedImage(cv::Mat imgMat)
{
    cv::Mat resized;
    cv::resize(imgMat, resized, cv::Size(ui->displayLabel->width(),ui->displayLabel->height()),0,0, cv::INTER_CUBIC);
    QImage img = QImage((uchar*)resized.data, resized.cols, resized.rows, resized.step, QImage::Format_Indexed8/* QImage::Format_RGB888*/);
    ui->processedLabel->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::processImage(QString imgName)
{
    Image * image = new Image(imgName);
    setDisplayImage(image->getImage());
    setProcessedImage(image->getProcessedImage());
}
