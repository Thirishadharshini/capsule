//#include <opencv2/opencv.hpp>
//#include<iostream>
//#include<vector>
//
//int main()
//{
//	cv::Mat img = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\capsule files\\image\\checker_box.jpg");
//	imshow("og image", img);
//	cv::Mat cont = img * 2;
//	cv::Mat img_gray;
//	cv::cvtColor(cont, img_gray, cv::COLOR_BGR2GRAY);
//	cv::Mat thresh;
//	threshold(img_gray, thresh, 50, 255, cv::THRESH_BINARY);
//	
//	std::vector<std::vector<cv::Point>> contours;
//	std::vector<cv::Vec4i> hierarchy;
//	findContours(thresh, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//	for (std::vector<std::vector<cv::Point> >::iterator it = contours.begin(); it != contours.end(); )
//		{
//		std::cout << "length of contour " << it->size() << std::endl;
//		if (it->size() < 1000)
//     		it = contours.erase(it);
//		else
//			++it;
//		}
//	cv::Point pt1;
//	cv::Point pt2;
//	for (int i = 0; i < contours.size(); i++) {
//		// Print edge points (first and last point) of each contour
//		std::cout << "Contour " << i << " edge points:" << std::endl;
//		cv::Point pt1 = contours[i][0];
//		std::cout << "First point: " << contours[i][0] << std::endl;
//		cv::Point pt2 = contours[i][contours[i].size() - 1];
//		std::cout << "Last point: " << contours[i][contours[i].size() - 1] << std::endl;
//	}
//	int max_height = img.rows;
//	int max_width = img.cols;
//
//	std::vector<cv::Point2f> input_pts;
//	input_pts.push_back(pt1);
//	input_pts.push_back(pt2);
//	
//
//	// Output points for new transformed image
//	std::vector<cv::Point2f> output_pts;
//	output_pts.push_back(cv::Point2f(0, 0));
//	output_pts.push_back(cv::Point2f(0, max_width));
//	
//
//	// Compute the perspective transform matrix M
//	cv::Mat M = cv::getPerspectiveTransform(input_pts, output_pts);
//
//	// Apply perspective transform
//	cv::Mat out;
//	cv::warpPerspective(img, out, M, cv::Size(max_height, max_width), cv::INTER_LINEAR);
//
//	// Display output
//	cv::imshow("Transformed Image", out);
//	cv::waitKey(0);
//	cv::destroyAllWindows();
//
//
//	
//	cv::waitKey(0);
//}
#include <opencv2/opencv.hpp>
#include<iostream>
#include<vector>

int main() {
    cv::Mat img = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\capsule files\\image\\checker_board.jpg");
    cv::imshow("Original Image", img);

    cv::Mat cont = img * 2;
    cv::Mat img_gray;
    cv::cvtColor(cont, img_gray, cv::COLOR_BGR2GRAY);
    cv::Mat thresh;
    cv::threshold(img_gray, thresh, 50, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(thresh, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    for (auto it = contours.begin(); it != contours.end(); ) {
        std::cout << "Length of contour: " << it->size() << std::endl;
        if (it->size() < 1000)
            it = contours.erase(it);
        else
            ++it;
    }

    int max_height = 0  ;
    int max_width = img.cols-1;

    // Select the largest contour
    auto largest_contour = contours[0];
    for (const auto& contour : contours) {
        if (contour.size() > largest_contour.size())
            largest_contour = contour;
    }

    // Define input points
    std::vector<cv::Point2f> input_pts;
    input_pts.push_back(largest_contour[0]);
    input_pts.push_back(largest_contour[largest_contour.size() - 1]);
    input_pts.push_back(largest_contour[largest_contour.size() / 2]);
    input_pts.push_back(largest_contour[1]);

    // Define output points
    std::vector<cv::Point2f> output_pts;
    output_pts.push_back(cv::Point2f(0, 0));
    output_pts.push_back(cv::Point2f(max_width, 0));
    output_pts.push_back(cv::Point2f(0, max_height));
    output_pts.push_back(cv::Point2f(max_width, max_height));

    // Compute perspective transform matrix
    cv::Mat M = cv::getPerspectiveTransform(input_pts, output_pts);

    // Apply perspective transform
    cv::Mat out;
    cv::warpPerspective(img, out, M, cv::Size(max_width, max_height), cv::INTER_LINEAR);

    // Display output
    cv::imshow("Transformed Image", out);
    cv::waitKey(0);
    cv::destroyAllWindows();

  
}