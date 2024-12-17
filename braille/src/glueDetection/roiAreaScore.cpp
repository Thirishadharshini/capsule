#include "roiAreaScore.hpp"

std::string roiAreaScore::roiAreaScore(cv::Mat img, cv::Rect roi){
    float whitePixelCount = cv::countNonZero(img);
    float score = (whitePixelCount / (roi.area() * 0.85)) * 100;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << score;
    return oss.str();
}
