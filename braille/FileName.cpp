//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<dirent.h>
//#include<vector>
//
//
////class braille {
////public:
////	static void finding_dots()
//int main()
//{

	//cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\1.bmp");
	////cv::Mat image1 = cv::imread("C:\\Users\\User\\MVS\\Data\\light_on_image\\image_400.jpg");
	//cv::namedWindow("og image ", cv::WINDOW_FREERATIO);
	//cv::imshow("og image ", image);
	//std::cout << "type: " << image.type();
	////cv::imshow("og image1", image1);
	//cv::Mat cont = image *2.7;//2.7
	////cv::Mat cont1 = image1 * 2;
	//cv::Mat img_gray, img_gray1;
	//cv::cvtColor(cont, img_gray, cv::COLOR_BGR2GRAY);
	////cv::cvtColor(cont1, img_gray1, cv::COLOR_BGR2GRAY);
	//std::cout << "type: " << img_gray.type();
	//cv::Mat blur, blur1;
	//cv::GaussianBlur(img_gray, blur, cv::Size(15,15), 0);//11
	////cv::GaussianBlur(img_gray1, blur1, cv::Size(11, 11), 0);
	//cv::Mat edges, edges1;
	//cv::Laplacian(blur, edges, CV_8U,15);//13
	////cv::Laplacian(blur1, edges1, CV_8U, 11);

	///*cv::Mat canny_edges;
	//Canny(blur, canny_edges,30,50, 3, false);
	//cv::namedWindow("Canny edge detection ", cv::WINDOW_FREERATIO);
	//imshow("Canny edge detection ", canny_edges);*/


	///*cv::Mat morph;
	//cv::morphologyEx(edges, morph, cv::MORPH_CLOSE, cv::Mat(), cv::Point(-1, -1), 2);*/

	//cv::namedWindow("Laplacian edge detection ", cv::WINDOW_FREERATIO);
	//imshow("Laplacian edge detection ", edges);
	////imshow("Laplacian edge detection 1", edges1);
	////cv::imwrite("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\6_morpho_extract.bmp", edges);
	////cv::imwrite("C:\\Users\\User\\MVS\\Data\\light_on_image\\image_400_cont2.jpg", edges1);
	//cv::waitKey(0);


/* cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\7.bmp", cv::IMREAD_ANYDEPTH | cv::IMREAD_COLOR);
 cv::namedWindow("Original Image", cv::WINDOW_FREERATIO);
 cv::imshow("Original Image", image);
 std::cout << "Original image type: " << image.type() << std::endl;
 cv::Mat norm_image;
 cv::normalize(image, norm_image, 0, 65535, cv::NORM_MINMAX, CV_16U);
 cv::Mat cont = norm_image * 2;

 cv::Mat img_8_bit;
 cont.convertTo(img_8_bit, CV_8U, 255.0 / 65535.0);
 cv::Mat img_gray;
 cv::cvtColor(img_8_bit, img_gray, cv::COLOR_BGR2GRAY);
 cv::Mat blur;
 cv::GaussianBlur(img_gray, blur, cv::Size(17,17), 0);
 cv::Mat edges;
 cv::Laplacian(blur, edges, CV_8U,9);
 cv::namedWindow("Laplacian Edge Detection", cv::WINDOW_FREERATIO);
 cv::imshow("Laplacian Edge Detection", edges);
 cv::imwrite("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\op with 2 cont\\7_extract.bmp", edges);

 cv::waitKey(0);
 return 0;*/


// cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\7.bmp", cv::IMREAD_ANYDEPTH | cv::IMREAD_COLOR);
// cv::namedWindow("Original Image", cv::WINDOW_FREERATIO);
// cv::imshow("Original Image", image);
// cv::Rect rectangle(550,1200,500,1200);
// cv::Mat roiImage = image(rectangle);
// cv::namedWindow("ROI Image", cv::WINDOW_FREERATIO);
// cv::imshow("ROI Image", roiImage);
// cv::Mat Gray;
// cv::cvtColor(roiImage, Gray, cv::COLOR_BGR2GRAY);
//
// cv::Mat adaptiveThresh;
// cv::adaptiveThreshold(Gray, adaptiveThresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C,
//	 cv::THRESH_BINARY_INV, 75, 10);
// cv::namedWindow("Adaptive Thresholding", cv::WINDOW_FREERATIO);
// cv::imshow("Adaptive Thresholding", adaptiveThresh);
// cv::waitKey(0);
//
// std::vector<std::vector<cv::Point>> contours;
// std::vector<cv::Vec4i> hierarchy;
// findContours(adaptiveThresh, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
// for (int i = 0; i < contours.size(); i++)
// {
//	 if (cv::contourArea(contours[i]) > 70)
//	 {
//		 drawContours(roiImage, contours, i, cv::Scalar(255, 0, 0), cv::FILLED);
//		 cv::namedWindow("blank", cv::WINDOW_FREERATIO);
//		 imshow("blank", roiImage);
//		 cv::waitKey(0);
//	 }
// }
//
//
// cv::Mat thresh;
// cv::threshold(Gray, thresh, 130, 255, cv::THRESH_BINARY);
// //cv::namedWindow("thresh Image", cv::WINDOW_FREERATIO);
// cv::imshow("thresh Image", thresh);
// std::vector<std::vector<cv::Point>> contours1;
// std::vector<cv::Vec4i> hierarchy1;
// findContours(thresh, contours1, hierarchy1, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
// 
// cv::Mat blankImage = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
// //imshow("blank", blankImage);
// //cv::waitKey(0);
// for (int i = 0; i < contours1.size(); i++)
// {
// 	if (cv::contourArea(contours1[i]) <200 && cv::contourArea(contours1[i]) > 30)
// 	{
// 		drawContours(blankImage, contours1, i, cv::Scalar(255, 255, 255), cv::FILLED);
// 		//imshow("blank", blankImage);
// 		//cv::waitKey(0);
// 	}
// }
// cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3), cv::Point(-1, -1));
// cv::Mat dilate;
// cv::dilate(blankImage, dilate, element, cv::Point(-1, -1), 2);
// //imshow("dilate img", dilate);
// //cv::waitKey(0);
//
// cv::Mat combinedImage;
// bitwise_or(thresh, dilate, combinedImage);
// //imshow("Combined Image", combinedImage);
//// cv::waitKey(0);
// cv::Mat image_copy = roiImage.clone();
// ////std::cout << "second contour start" << std::endl;
// std::vector<std::vector<cv::Point>> contours2;
// std::vector<cv::Vec4i> hierarchy2;
// findContours(combinedImage, contours2, hierarchy2, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
// for (int i = 0; i < contours1.size(); i++)
// {
// 	if(cv::contourArea(contours2[i])>70)
// 	{
// 		drawContours(image_copy, contours2, i, cv::Scalar(0, 255, 0), cv::FILLED);
//		cv::namedWindow("None approximation", cv::WINDOW_FREERATIO);
// 		imshow("None approximation", image_copy);
// 		cv::waitKey(0);
// 	}
// }

//// load the image
//	cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\1.bmp");
//	//cv::namedWindow("og image ", cv::WINDOW_FREERATIO);
//	//cv::imshow("og image ", image);
//
//	//region of interest
//	cv::Rect rectangle(550, 1200, 500, 1100);
//	cv::Mat roiImage = image(rectangle);
//	cv::imshow("ROI Image", roiImage);
//	cv::Mat img_gray1;
//	cv::cvtColor(roiImage, img_gray1, cv::COLOR_BGR2GRAY);
//	cv::Mat adaptiveThresh;
//	cv::adaptiveThreshold(img_gray1, adaptiveThresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C,
//		cv::THRESH_BINARY_INV, 75, 10);
//
//	cv::imshow("Adaptive Thresholding", adaptiveThresh);
//	cv::waitKey(0);
//		std::vector<std::vector<cv::Point>> contours;
//	std::vector<cv::Vec4i> hierarchy;
//	findContours(adaptiveThresh, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//	for (int i = 0; i < contours.size(); i++)
//	{
//		if ( cv::contourArea(contours[i]) > 30)
//		{
//			drawContours(roiImage, contours, i, cv::Scalar(255, 0,0), cv::FILLED);
//			imshow("blank", roiImage);
//			cv::waitKey(0);
//		}
//	}

//}
//	//lapacian method
//	cv::Mat cont = roiImage * 2.7;//2.7
//	cv::Mat img_gray;
//	cv::cvtColor(cont, img_gray, cv::COLOR_BGR2GRAY);
//	cv::Mat blur;
//	cv::GaussianBlur(img_gray, blur, cv::Size(3,3), 8,8);//11
//	cv::Mat edges;
//	cv::Laplacian(blur, edges, CV_8U, 15);//13
//	imshow("Laplacian Edge Detection", edges);
//
//	//threshold and contours
//	cv::Mat Gray;
//	cv::cvtColor(roiImage, Gray, cv::COLOR_BGR2GRAY);
//	cv::Mat thresh;
//	cv::threshold(Gray, thresh, 130, 255, cv::THRESH_BINARY);
//	//cv::namedWindow("thresh Image", cv::WINDOW_FREERATIO);
//	cv::imshow("thresh Image", thresh);
//	std::vector<std::vector<cv::Point>> contours;
//	std::vector<cv::Vec4i> hierarchy;
//	findContours(thresh, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//
//	// create a black blank image
//	cv::Mat blankImage0 = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//	cv::waitKey(0);
//
//	//draw contours on the black image
//	for (int i = 0; i < contours.size(); i++)
//	{
//		if (cv::contourArea(contours[i]) < 200 && cv::contourArea(contours[i]) > 30)
//		{
//			drawContours(blankImage0, contours, i, cv::Scalar(255, 255, 255), cv::FILLED);
//			imshow("blank", blankImage0);
//			cv::waitKey(0);
//		}
//	}
//	cv::Mat element0 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
//	cv::Mat dilate0;
//	cv::dilate(blankImage0, dilate0, element0, cv::Point(-1, -1), 2);
//	//imshow("dilate img 0", dilate0);
//	cv::waitKey(0);
//	cv::Mat combinedImage0;
//	bitwise_or(thresh, dilate0, combinedImage0);
//	imshow("Combined Image 0", combinedImage0);
//	cv::waitKey(0);
//
//
//	//contours for laplacian method
//	std::vector<std::vector<cv::Point>> contours0;
//	std::vector<cv::Vec4i> hierarchy0;
//	findContours(edges, contours0, hierarchy0, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//
//	//cv::Mat blankImage1 = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//
//	//cv::waitKey(0);
//	//for (int i = 0; i < contours0.size(); i++)
//	//{
//	//	if (cv::contourArea(contours0[i]) < 150 && cv::contourArea(contours0[i]) > 70)
//	//	{
//
//	//		drawContours(blankImage1, contours0, i, cv::Scalar(255, 255, 255), cv::FILLED);
//	//		imshow("blank 1", blankImage1);
//	//		cv::waitKey(0);
//	//	}
//	//}
//	//cv::Mat element1 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5), cv::Point(-1, -1));
//	//cv::Mat dilate1;
//	//cv::dilate(blankImage1, dilate1, element1, cv::Point(-1, -1), 2);
//	////imshow("dilate img 1", dilate1);
//	//cv::waitKey(0);
//
//	//cv::Mat combinedImage1;
//	//bitwise_or(edges, dilate1, combinedImage1);
//	//imshow("Combined Image 1", combinedImage1);
//	//cv::waitKey(0);
//	//cv::Mat image_copy = roiImage.clone();
//	//////std::cout << "second contour start" << std::endl;
//	//std::vector<std::vector<cv::Point>> contours1;
//	//std::vector<cv::Vec4i> hierarchy1;
//	//findContours(combinedImage1, contours1, hierarchy1, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//	cv::Mat blankImage2 = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//	for (int i = 0; i < contours0.size(); i++)
//	{
//		if (cv::contourArea(contours0[i]) > 80 && cv::contourArea(contours0[i]) < 400)
//		{
//			std::cout << "contour area: " << cv::contourArea(contours0[i]) << std::endl;
//			drawContours(roiImage, contours0, i, cv::Scalar(255, 0, 0), cv::FILLED);
//			imshow("None approximation", roiImage);
//			cv::waitKey(0);
//		}
//	}
//}
	/*cv::Mat combinedImage1;
	bitwise_or(blankImage2, combinedImage, combinedImage1);
	imshow("Combined Image1", combinedImage1);
	cv::waitKey(0);*/
	


//     cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\1.bmp");
//	 //region of interest
//	cv::Rect rectangle(630, 1200, 500, 1100);
//	cv::Mat roiImage = image(rectangle);
//	cv::imshow("ROI Image", roiImage);
//	//cv::Mat cont = roiImage * 0.89;
//	cv::Mat blur;
//	cv::GaussianBlur(roiImage, blur, cv::Size(5,5),5);
//	cv::Mat Gray;
//	cv::cvtColor(blur, Gray, cv::COLOR_BGR2GRAY);
//	cv::namedWindow("gray Image", cv::WINDOW_FREERATIO);
//	cv::imshow("gray Image", Gray);
//	cv::Mat thresh;
//	cv::threshold(Gray, thresh, 95, 255, cv::THRESH_BINARY_INV);
//	cv::namedWindow("thresh Image", cv::WINDOW_FREERATIO);
//	cv::imshow("thresh Image", thresh);
//	 cv::waitKey(0);
//
//	 std::vector<std::vector<cv::Point>> contours;
//	std::vector<cv::Vec4i> hierarchy;
//	findContours(thresh, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//	
//	// create a black blank image
//	cv::Mat blankImage0 = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//	cv::waitKey(0);
//	//draw contours on the black image
//	for (int i = 0; i < contours.size(); i++)
//	{
//		if ( cv::contourArea(contours[i]) >0)
//		{
//			std::cout << "contour area: " << cv::contourArea(contours[i]) << std::endl;
//			drawContours(blankImage0, contours, i, cv::Scalar(255, 255, 255), cv::FILLED);
//			cv::namedWindow("blank", cv::WINDOW_FREERATIO);
//			imshow("blank", blankImage0);
//			cv::waitKey(0);
//		}
//	}
//	cv::Mat element1 = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(7,7), cv::Point(-1, -1));
//	cv::Mat dilate1,erode;
//	cv::dilate(blankImage0, dilate1, element1, cv::Point(-1, -1), 3);
//	cv::erode( dilate1,erode, element1, cv::Point(-1, -1), 2);
//	imshow("dilate img 1",erode);
//	cv::waitKey(0);
//	cv::Mat combinedImage1;
//	bitwise_or(thresh, erode, combinedImage1);
//	cv::namedWindow("Combined Image 1", cv::WINDOW_FREERATIO);
//	imshow("Combined Image 1", combinedImage1);
//	cv::waitKey(0);
//	cv::Mat image_copy = roiImage.clone();
//	////std::cout << "second contour start" << std::endl;
//	std::vector<std::vector<cv::Point>> contours1;
//	std::vector<cv::Vec4i> hierarchy1;
//	findContours(combinedImage1, contours1, hierarchy1, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//	cv::Mat blankImage2 = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//	for (int i = 0; i < contours1.size(); i++)
//	{
//		if (cv::contourArea(contours1[i]) >250 && cv::contourArea(contours1[i]) < 4000)
//		{
//			std::cout << "contour area: " << cv::contourArea(contours1[i]) << std::endl;
//			drawContours(roiImage, contours1, i, cv::Scalar(255, 0,0), cv::FILLED);
//			cv::namedWindow("None approximation", cv::WINDOW_FREERATIO);
//			imshow("None approximation", roiImage);
//			cv::waitKey(0);
//		}
//	}
////}
//cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\7.bmp", cv::IMREAD_ANYDEPTH | cv::IMREAD_COLOR);
//cv::namedWindow("Original Image", cv::WINDOW_FREERATIO);
//cv::imshow("Original Image", image);
////ROI
//cv::Rect rectangle(550, 1200, 500, 1200);
//cv::Mat roiImage = image(rectangle);
//cv::namedWindow("ROI Image", cv::WINDOW_FREERATIO);
//cv::imshow("ROI Image", roiImage);
////convert to gray image
//cv::Mat Gray;
//cv::cvtColor(roiImage, Gray, cv::COLOR_BGR2GRAY);
////use adaptive threshold
//cv::Mat adaptiveThresh;
//cv::adaptiveThreshold(Gray, adaptiveThresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C,
//    cv::THRESH_BINARY_INV, 75, 10);
//cv::namedWindow("Adaptive Thresholding", cv::WINDOW_FREERATIO);
//cv::imshow("Adaptive Thresholding", adaptiveThresh);
//cv::waitKey(0);
////find contours
//std::vector<std::vector<cv::Point>> contours;
//std::vector<cv::Vec4i> hierarchy;
//findContours(adaptiveThresh, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//cv::Mat blankImage_adaptive = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//for (int i = 0; i < contours.size(); i++)
//{
//    if (cv::contourArea(contours[i]) > 70)
//    {
//        drawContours(blankImage_adaptive, contours, i, cv::Scalar(255, 255, 255), cv::FILLED);
//        cv::namedWindow("blank", cv::WINDOW_FREERATIO);
//        imshow("blank", blankImage_adaptive);
//        cv::waitKey(0);
//    }
//}
//cv::Mat element_adapt = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
//cv::Mat dilate_adapt;
//cv::dilate(blankImage_adaptive, dilate_adapt, element_adapt, cv::Point(-1, -1), 2);
//cv::namedWindow("dilated image of adapt", cv::WINDOW_FREERATIO);
//imshow("dilated image of adapt", dilate_adapt);
//cv::waitKey(0);
//
//cv::Mat thresh;
//cv::threshold(Gray, thresh, 130, 255, cv::THRESH_BINARY);
//cv::namedWindow("thresh Image", cv::WINDOW_FREERATIO);
//cv::imshow("thresh Image", thresh);
//std::vector<std::vector<cv::Point>> contours1;
//std::vector<cv::Vec4i> hierarchy1;
//findContours(thresh, contours1, hierarchy1, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//
//cv::Mat blankImage = cv::Mat::zeros(roiImage.rows, roiImage.cols, CV_8UC1);
//for (int i = 0; i < contours1.size(); i++)
//{
//    if (cv::contourArea(contours1[i]) < 200 && cv::contourArea(contours1[i]) > 30)
//    {
//        drawContours(blankImage, contours1, i, cv::Scalar(255, 255, 255), cv::FILLED);
//        //imshow("blank", blankImage);
//        //cv::waitKey(0);
//    }
//}
//cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
//cv::Mat dilate;
//cv::dilate(blankImage, dilate, element, cv::Point(-1, -1), 2);
////imshow("dilate img", dilate);
////cv::waitKey(0);
//
//cv::Mat combinedImage;
//bitwise_or(thresh, dilate, combinedImage);
////imshow("Combined Image", combinedImage);
//// cv::waitKey(0);
//cv::Mat image_copy = dilate_adapt.clone();
//////std::cout << "second contour start" << std::endl;
//std::vector<std::vector<cv::Point>> contours2;
//std::vector<cv::Vec4i> hierarchy2;
//findContours(combinedImage, contours2, hierarchy2, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//for (int i = 0; i < contours1.size(); i++)
//{
//    if (cv::contourArea(contours2[i]) > 70)
//    {
//        drawContours(image_copy, contours2, i, cv::Scalar(255, 255, 255), cv::FILLED);
//        cv::namedWindow("None approximation", cv::WINDOW_FREERATIO);
//        imshow("None approximation", image_copy);
//        cv::waitKey(0);
//    }
//}