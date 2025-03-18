//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<dirent.h>
//#include<vector>
//#include<chrono>
//
//
//int main()
//{
//    auto startMain = std::chrono::high_resolution_clock::now();
//
//    cv::Mat image = cv::imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\1.bmp", cv::IMREAD_ANYDEPTH | cv::IMREAD_COLOR);
//    /*cv::namedWindow("Original Image", cv::WINDOW_FREERATIO);
//    cv::imshow("Original Image", image);*/
//    cv::Rect rectangle(550, 1200, 500, 1200);
//    cv::Mat roiImage = image(rectangle);
//    cv::namedWindow("ROI Image", cv::WINDOW_FREERATIO);
//    cv::imshow("ROI Image", roiImage);
//    cv::Mat blur;
//    cv::GaussianBlur(roiImage, blur, cv::Size(7, 7), 6, 6);
//    cv::Mat Gray;
//    cv::cvtColor(blur, Gray, cv::COLOR_BGR2GRAY);
//
//    cv::Mat adaptiveThresh;
//    cv::adaptiveThreshold(Gray, adaptiveThresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 85, -7);//-6
//    cv::namedWindow("Adaptive Thresholding", cv::WINDOW_FREERATIO);
//    cv::imshow("Adaptive Thresholding", adaptiveThresh);
//    // cv::waitKey(0);
//    cv::Mat adaptiveThresh_up;
//    cv::adaptiveThreshold(Gray, adaptiveThresh_up, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 75, 9);
//    cv::namedWindow("Adaptive Thresholding up", cv::WINDOW_FREERATIO);
//    cv::imshow("Adaptive Thresholding up", adaptiveThresh_up);
//    // cv::waitKey(0);
//
//
//    cv::Mat kernel = (cv::Mat_<uchar>(3, 3) << 1, 0, 0,
//        0, 1, 0,
//        0, 0, 0);
//    cv::Mat kernel1 = (cv::Mat_<uchar>(3, 3) << 0, 0, 0,
//        0, 1, 0,
//        0, 0, 1);
//    cv::Mat dilate_dn;
//    cv::dilate(adaptiveThresh, dilate_dn, kernel1, cv::Point(2, 1), 3);
//    //cv::namedWindow("dilated image of adapt", cv::WINDOW_FREERATIO);
// 
//    imshow("dilated image of down", dilate_dn);
//    cv::Mat dilate_up;
//    cv::dilate(adaptiveThresh_up, dilate_up, kernel, cv::Point(0, 2), 5);
//    //cv::namedWindow("dilated image of adapt", cv::WINDOW_FREERATIO);
//    imshow("dilated image of up", dilate_up);
//    // cv::waitKey(0);
//
//    cv::Mat bitwise;
//    cv::bitwise_or(dilate_dn, dilate_up, bitwise);
//    cv::namedWindow("bitwise", cv::WINDOW_FREERATIO);
//    cv::imshow("bitwise", bitwise);
//    // cv::waitKey(0);
//
//    std::vector<std::vector<cv::Point>> contours;
//    std::vector<cv::Vec4i> hierarchy;
//    findContours(bitwise, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
//
//    std::vector<std::vector<cv::Point> > contours_poly(contours.size());
//    std::vector<cv::Rect> boundRect(contours.size());
//    //std::vector<cv::Point2f>centers(contours.size());
//    std::vector<float>mean_gray(contours.size());
//    cv::Mat roi;
//    for (size_t i = 0; i < contours.size(); i++)
//    {
//        approxPolyDP(contours[i], contours_poly[i], 3, true);
//        boundRect[i] = boundingRect(contours_poly[i]);
//        // minEnclosingCircle(contours_poly[i], centers[i], radius[i]);
//    }
//    for (size_t i = 0; i < contours.size(); i++)
//    {
//        if (cv::contourArea(contours[i]) > 200)
//        {
//            int s1 = boundRect[i].tl().x;
//            int s2 = boundRect[i].tl().y;
//            cv::Rect roi(s1, s2, 42, 32);
//            cv::Mat img_roi = roiImage(roi);
//            cv::Scalar mean = cv::mean(Gray(roi));
//            std::cout << "mean: " << mean << std::endl;
//            mean_gray.push_back(mean[0]);
//            cv::Point center(s1 + img_roi.cols / 2, s2 + img_roi.rows / 2);
//            cv::Point end(boundRect[i].tl().x + 42, boundRect[i].tl().y + 32);
//            drawContours(roiImage, contours_poly, (int)i, cv::Scalar(255, 200, 0), cv::FILLED);
//            cv::rectangle(roiImage, boundRect[i].tl(), end, cv::Scalar(255, 255, 255), 2);
//            circle(roiImage, center, 2, 0, 3);
//
//        }
//    }
//    imshow("roi 1", roiImage);
//    cv::waitKey();
//    auto endMain = std::chrono::high_resolution_clock::now();
//    auto mainDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endMain - startMain);
//    std::cout << "Execution time of the entire algorithm: " << mainDuration.count() << " ms" << std::endl;
//
//
//}