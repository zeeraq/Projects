#ifndef PROCESSIMAGE_H
#define PROCESSIMAGE_H
#include <QString>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
class Image
{
    cv::Mat img;
public:
    Image(QString name);
    cv::Mat getImage();
    cv::Mat getProcessedImage();
};
#endif // PROCESSIMAGE_H
