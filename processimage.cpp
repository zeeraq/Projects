#include "processimage.h"
using namespace cv;
using namespace std;
#include <QMainWindow>

Image::Image(QString name)
{
    img = cv::imread(name.toStdString(), CV_LOAD_IMAGE_UNCHANGED);
}

cv::Mat Image::getImage()
{
    cv::Mat imgClone = img.clone();
    return imgClone;
}

cv::Mat Image::getProcessedImage()
{
    cv::Mat proc = img.clone();
    cv::cvtColor(proc,proc,cv::COLOR_BGR2GRAY);
    cv::adaptiveThreshold(proc, proc, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 39, 15);
    int dilation_size = 3;
    Mat element = getStructuringElement(
                cv::MORPH_RECT,
                cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1),
                cv::Point(dilation_size, dilation_size)
                                        );
    cv::dilate(proc, proc,element);
    int erosion_size = 1;
    Mat element2 = getStructuringElement(
                cv::MORPH_RECT,
                cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                cv::Point(erosion_size, erosion_size)
                                        );
    cv::erode(proc, proc, element2);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    RNG rng(12345);
    cv::Mat clone = proc.clone();
    cv::findContours(clone, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
    cv::Mat drawing = Mat::zeros(proc.size(), CV_8UC3);
    for( int i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }
    cv::resize(drawing, drawing, cv::Size(900,600),0,0, cv::INTER_CUBIC);
    imshow("win3", drawing);

    return proc;
}
