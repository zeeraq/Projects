#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "processimage.h"
#include <QFileDialog>
#include <iostream>
void processImage(QString imgName);
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
void processImage(QString imgName)
{
    Image * image = new Image(imgName);
}
