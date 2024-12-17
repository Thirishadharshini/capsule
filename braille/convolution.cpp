//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<dirent.h>
//#include<vector>
//using namespace std;
//using namespace cv;
//
//
// 
//
//int main() {
//
//    auto startMain = std::chrono::high_resolution_clock::now();
//
//    // Mat imgOriginal = imread("/media/prem/Windows-SSD/Users/engrp/MVS/Data/MV-CL042-91GC (DA2615757)/try3/Image_20241113145648961.bmp", IMREAD_GRAYSCALE);
//    Mat imgOriginal = imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\1.bmp", IMREAD_GRAYSCALE);
//    namedWindow("imgOriginal", WINDOW_NORMAL);
//    imshow("imgOriginal", imgOriginal);
//    // waitKey();
//    cv::Rect myROI(550, 1200, 500, 1200);
//    Mat imgCropped = imgOriginal(myROI).clone();
//    //namedWindow("imgCropped", WINDOW_NORMAL);
//    imshow("imgCropped", imgCropped);
//
//    Mat convertedImage;
//
//    auto startConv = std::chrono::high_resolution_clock::now();
//
//
//   
//    if (imgCropped.type() != CV_8U) {
//        throw std::runtime_error("Input Image has to be in GrayScale and 8 Bit Depth");
//    }
//    if (convertedImage.type() != CV_8U) {
//        throw std::runtime_error("Output Image has to be in GrayScale and 8 Bit Depth");
//    }
//
//    Mat signedImage(imgCropped.size(), CV_16S, Scalar(0));
//
//    GaussianBlur(imgCropped, imgCropped, Size(5, 5), 2, 2);
//
//    imgCropped.convertTo(signedImage, CV_16SC1);
//
//    Mat filterX(signedImage.size(), CV_16S);
//    Mat kernelX = (Mat_<double>(5, 5) << -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1);
//    filter2D(signedImage, filterX, -1, kernelX);
//
//    Mat convertedImageX(filterX.size(), CV_8U);
//
//    //namedWindow("convertedX", WINDOW_NORMAL);
//    imshow("convertedX", convertedImageX);
//
//    Mat filterX2(signedImage.size(), CV_16S);
//    Mat kernelX2 = (Mat_<double>(5, 5) << 1, 1, 0, -1, -1,
//        -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1,
//        -1, -1, 0, 1, 1);
//    filter2D(signedImage, filterX2, -1, kernelX2);
//
//    Mat convertedImageX2(filterX2.size(), CV_8U);
//    filterX2.convertTo(convertedImageX2, CV_8UC1);
//    //namedWindow("convertedX2", WINDOW_NORMAL);
//    imshow("convertedX2", convertedImageX2);
//
//    Mat filterY(signedImage.size(), CV_16S, Scalar(0));
//    Mat kernelY = (Mat_<double>(5, 5) << -1, -1, -1, -1, -1,
//        -1, -1, -1, -1, -1,
//        0, 0, 0, 0, 0,
//        1, 1, 1, 1, 1,
//        1, 1, 1, 1, 1);
//
//    filter2D(signedImage, filterY, -1, kernelY);
//
//    Mat convertedImageY(filterY.size(), CV_8U);
//    filterY.convertTo(convertedImageY, CV_8UC1);
//    //namedWindow("convertedY", WINDOW_NORMAL);
//    imshow("convertedY", convertedImageY);
//
//
//    Mat filterY2(signedImage.size(), CV_16S, Scalar(0));
//
//    Mat kernelY2 = (Mat_<double>(5, 5) << 1, 1, 1, 1, 1,
//        1, 1, 1, 1, 1,
//        0, 0, 0, 0, 0,
//        -1, -1, -1, -1, -1,
//        -1, -1, -1, -1, -1);
//
//    filter2D(signedImage, filterY2, -1, kernelY2);
//
//    Mat convertedImageY2(filterY2.size(), CV_8U);
//    filterY2.convertTo(convertedImageY2, CV_8UC1);
//    //namedWindow("convertedY2", WINDOW_NORMAL);
//    imshow("convertedY2", convertedImageY2);
//
//    //Mat convertedImage;
//    add(convertedImageY2, convertedImageY, convertedImage);
//    namedWindow("add", WINDOW_NORMAL);
//    imshow("add", convertedImage);
//
//    convertedImage = convertedImageY.clone();
//
//    auto endConv = std::chrono::high_resolution_clock::now();
//    auto convDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endConv - startConv);
//    std::cout << "Execution time of signedConvolution: " << convDuration.count() << " ms" << std::endl;
//
//    imshow("signedConvolution", convertedImage);
//    // cv::waitKey(0);
//    threshold(convertedImage, convertedImage, 75, 255, THRESH_BINARY);
//   // namedWindow("threshold", WINDOW_NORMAL);
//    imshow("threshold", convertedImage);
//    Mat kernel = (Mat_<uint8_t>(3, 3) << 0, 1, 0,
//        0, 1, 0,
//        0, 1, 0);
//
//    std::cout << kernel << std::endl;
//    dilate(convertedImage, convertedImage, kernel, cv::Point(-1, -1), 4);
//   // namedWindow("dilate", WINDOW_NORMAL);
//    imshow("dilate", convertedImage);
//    
//
//    Mat imgContour(convertedImage.size(), CV_8UC1, Scalar(0));
//    std::vector<std::vector<Point>> contourPoints;
//    findContours(convertedImage, contourPoints, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//
//
//    std::vector<std::vector<cv::Point> > contours_poly(contourPoints.size());
//        std::vector<cv::Rect> boundRect(contourPoints.size());
//        //std::vector<cv::Point2f>centers(contours.size());
//        std::vector<float>mean_gray(contourPoints.size());
//        cv::Mat roi;
//        for (size_t i = 0; i < contourPoints.size(); i++)
//        {
//            approxPolyDP(contourPoints[i], contours_poly[i], 3, true);
//            boundRect[i] = boundingRect(contours_poly[i]);
//           // minEnclosingCircle(contours_poly[i], centers[i], radius[i]);
//        }
//        for (size_t i = 0; i < contourPoints.size(); i++)
//        {
//            if (cv::contourArea(contourPoints[i]) > 200)
//            {
//                int s1 = boundRect[i].tl().x;
//                int s2 = boundRect[i].tl().y;
//                cv::Rect roi(s1, s2, 42, 32);
//                cv::Mat img_roi = imgCropped(roi);
//                cv::Scalar mean = cv::mean(imgCropped(roi));
//                std::cout << "mean: " << mean << std::endl;
//                mean_gray.push_back(mean[0]);
//                cv::Point center(s1 + img_roi.cols / 2, s2 + img_roi.rows / 2);
//                cv::Point end(boundRect[i].tl().x + 42, boundRect[i].tl().y + 32);
//                drawContours(imgCropped, contours_poly, (int)i, cv::Scalar(255, 200, 0), cv::FILLED);
//                cv::rectangle(imgCropped, boundRect[i].tl(), end, cv::Scalar(255, 255, 255), 2);
//                circle(imgCropped, center, 2, 0, 3);
//                
//               
//            }
//        }
//        imshow("roi 1", imgCropped);
//        cv::waitKey();
//        auto endMain = std::chrono::high_resolution_clock::now();
//        auto mainDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endMain - startMain);
//        std::cout << "Execution time of the entire algorithm: " << mainDuration.count() << " ms" << std::endl;
//
//}
