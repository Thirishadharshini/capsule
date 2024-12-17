#ifndef CHANGEBRIGHTNESS
#define CHANGEBRIGHTNESS

#include <opencv2/opencv.hpp>

namespace changeBrightness
{
    void changeBrightness(cv::Mat& img, double value);
} // namespace changeBrightness

#endif