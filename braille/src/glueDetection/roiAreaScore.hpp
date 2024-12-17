#ifndef ROIAREASCORE
#define ROIAREASCORE

#include <iomanip>
#include <sstream>
#include <opencv2/opencv.hpp>

namespace roiAreaScore {
    std::string roiAreaScore(cv::Mat img, cv::Rect roi);
}

#endif  // ROIAREASCORE