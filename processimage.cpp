#include "processimage.h"
using namespace cv;
#include <QMainWindow>

Image::Image(QString name)
{
    img = cv::imread(name.toStdString(), CV_LOAD_IMAGE_UNCHANGED);
}
