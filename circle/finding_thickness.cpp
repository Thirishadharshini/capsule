                                                                                                                                        //#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<vector>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat gray = imread("circles_image_thin.png", IMREAD_GRAYSCALE);
//	Mat canny_output;
//	vector<vector<Point> > contours;
//	vector<Vec4i> hierarchy;
//
//	// detect edges using canny
//	Canny(gray, canny_output, 50, 150, 3);
//
//	// find contours
//	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
//
//	// get the moments
//	vector<Moments> mu(contours.size());
//	for (int i = 0; i < contours.size(); i++)
//	{
//		mu[i] = moments(contours[i], false);
//	}
//
//	// get the centroid of figures.
//	vector<Point2f> mc(contours.size());
//	for (int i = 0; i < contours.size(); i++)
//	{
//		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
//	}
//
//	// draw contours
//	Mat drawing(canny_output.size(), CV_8UC3, Scalar(255, 255, 255));
//	for (int i = 0; i < contours.size(); i++)
//	{
//		Scalar color = Scalar(167, 151, 0); // B G R values
//		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
//		circle(drawing, mc[i], 4, color, -1, 8, 0);
//	}
//
//	// show the resultant image
//	namedWindow("Contours", WINDOW_AUTOSIZE);
//	imshow("Contours", drawing);
//	waitKey(0);
//}
//cv::Mat gray;
			//cvtColor(image, gray, cv::COLOR_BGR2GRAY);
			//medianBlur(gray, gray, 5);
			//std::vector<cv::Vec3f> circles;
			//HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
			//	gray.rows / 16,  // change this value to detect circles with different distances to each other
			//	10, 30, 1, 50 // change the last two parameters
			//	// (min_radius & max_radius) to detect larger circles
			//);
			//for (size_t i = 0; i < circles.size(); i++)
			//{
			//	cv::Vec3i c = circles[i];
			//	cv::Point center = cv::Point(c[0], c[1]);
			//	// circle center
			//	circle(image, center, 1, cv::Scalar(0, 100, 100), 3, cv::LINE_AA);
			//	// circle outline
			//	int radius = c[2];
			//	circle(image, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
			//}
			//cv::imshow("detected circles", image);
			//cv::waitKey();

