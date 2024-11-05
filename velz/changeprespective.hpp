#ifndef CHANGEPERSPECTIVE_HPP
#define CHANGEPERSPECTIVE_HPP

#include<opencv2/opencv.hpp>
#include <iostream>

class changeperspective{
	 
public:
	cv::Mat ChangePerspective(std::string path);



private:
	cv::Mat input, output;
	int a;
	cv::Mat threshimg;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Point2f> approx;
	cv::Mat transformedimg;
	cv::Mat perspectivetrans;

};

#endif // CHANGEPERSPECTIVE_HPP
