#include "changeBrightness.hpp"

void changeBrightness::changeBrightness(cv::Mat& img, double value) {
    cv::Mat hsv;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);

    std::vector<cv::Mat> channels;

    cv::split(hsv, channels);
    channels[2] = channels[2] * value;
    cv::threshold(channels[2], channels[2], 255, 255, cv::THRESH_TRUNC);
    cv::merge(channels, hsv);
    cv::cvtColor(hsv, img, cv::COLOR_HSV2BGR);
}

