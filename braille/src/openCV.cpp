//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<dirent.h>
//#include<vector>
//
//
//if (src.type() != CV_8U) {
//    throw std::runtime_error("Input Image has to be in GrayScale and 8 Bit Depth");
//}
//if (dst.type() != CV_8U) {
//    throw std::runtime_error("Output Image has to be in GrayScale and 8 Bit Depth");
//}
//
//Mat signedImage(src.size(), CV_16S, Scalar(0));
//
//GaussianBlur(src, src, Size(5, 5), 2, 2);
//
//src.convertTo(signedImage, CV_16SC1);
//
//Mat filterX(signedImage.size(), CV_16S);
//Mat kernelX = (Mat_<double>(5, 5) << -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1);
//filter2D(signedImage, filterX, -1, kernelX);
//
//Mat convertedImageX(filterX.size(), CV_8U);
//
//namedWindow("convertedX", WINDOW_NORMAL);
//imshow("convertedX", convertedImageX);
//
//Mat filterX2(signedImage.size(), CV_16S);
//Mat kernelX2 = (Mat_<double>(5, 5) << 1, 1, 0, -1, -1,
//    -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1,
//    -1, -1, 0, 1, 1);
//filter2D(signedImage, filterX2, -1, kernelX2);
//
//Mat convertedImageX2(filterX2.size(), CV_8U);
//filterX2.convertTo(convertedImageX2, CV_8UC1);
//namedWindow("convertedX2", WINDOW_NORMAL);
//imshow("convertedX2", convertedImageX2);
//
//Mat filterY(signedImage.size(), CV_16S, Scalar(0));
//// Mat kernelY = 3 * (Mat_<double>(3, 3) << -1, -1, -1,
////                                      0,  0,  0,
////                                      1,  1,  1);
//Mat kernelY = (Mat_<double>(5, 5) << -1, -1, -1, -1, -1,
//    -1, -1, -1, -1, -1,
//    0, 0, 0, 0, 0,
//    1, 1, 1, 1, 1,
//    1, 1, 1, 1, 1);
//// Mat kernelY = (1 / 8.0) * (Mat_<double>(7, 7) << -1, -1, -1, -1, -1, -1, -1,
////                           -1, -1, -1, -1, -1, -1, -1,
////                           -1, -1, -1, -1, -1, -1, -1,
////                           0, 0, 0, 0, 0, 0, 0,
////                           1, 1, 1, 1, 1, 1, 1,
////                           1, 1, 1, 1, 1, 1, 1,
////                           1, 1, 1, 1, 1, 1, 1);
//// int kernelSize = 3;
//// Mat kernelY = createSquareKernelY(kernelSize, 1.0);
//
//// std::cout << "Kernel:" << kernelY << std::endl;
//filter2D(signedImage, filterY, -1, kernelY);
//
//Mat convertedImageY(filterY.size(), CV_8U);
//filterY.convertTo(convertedImageY, CV_8UC1);
//namedWindow("convertedY", WINDOW_NORMAL);
//imshow("convertedY", convertedImageY);
//
//
//Mat filterY2(signedImage.size(), CV_16S, Scalar(0));
//
//Mat kernelY2 = (Mat_<double>(5, 5) << 1, 1, 1, 1, 1,
//    1, 1, 1, 1, 1,
//    0, 0, 0, 0, 0,
//    -1, -1, -1, -1, -1,
//    -1, -1, -1, -1, -1);
//
//filter2D(signedImage, filterY2, -1, kernelY2);
//
//Mat convertedImageY2(filterY2.size(), CV_8U);
//filterY2.convertTo(convertedImageY2, CV_8UC1);
//namedWindow("convertedY2", WINDOW_NORMAL);
//imshow("convertedY2", convertedImageY2);
//
//// GaussianBlur(convertedImageY, convertedImageY, Size(5, 5), 2, 2);
//// namedWindow("postBlur", WINDOW_NORMAL);
//// imshow("postBlur", convertedImageY);
//
//Mat convertedImage;
//add(convertedImageY2, convertedImageY, convertedImage);
//namedWindow("add", WINDOW_NORMAL);
//imshow("add", convertedImage);
//
//// Mat imgOr;
//// bitwise_or(convertedImageX, convertedImageY, imgOr);
//// namedWindow("bitwise_or", WINDOW_NORMAL);
//// imshow("bitwise_or", imgOr);
//
//// convertedImageY = 4 * convertedImageY;
//
//dst = convertedImageY.clone();
//}
//
//int main() {
//    // Mat imgOriginal = imread("/media/prem/Windows-SSD/Users/engrp/MVS/Data/MV-CL042-91GC (DA2615757)/try3/Image_20241113145648961.bmp", IMREAD_GRAYSCALE);
//    Mat imgOriginal = imread("C:\\Users\\User\\source\\repos\\capsule\\braille\\braille_images\\1.bmp", IMREAD_GRAYSCALE);
//    namedWindow("imgOriginal", WINDOW_NORMAL);
//    imshow("imgOriginal", imgOriginal);
//    // waitKey();
//    cv::Rect myROI(800, 1400, 987-800, 2156-1400);
//    Mat imgCropped = imgOriginal(myROI).clone();
//    namedWindow("imgCropped", WINDOW_NORMAL);
//    imshow("imgCropped", imgCropped);
//
//    Mat convertedImage;
//
//    // cv::GaussianBlur(imgCropped, imgCropped, Size(9,9), 0);
//    // cv::Laplacian(imgCropped, convertedImage, CV_8U, 19);
//
//    signedConvolution::signedConvolution(imgOriginal(myROI), convertedImage);
//    // convertedImage.convertTo(convertedImage, CV_8UC1);
//    namedWindow("signedConvolution", WINDOW_NORMAL);
//    imshow("signedConvolution", convertedImage);
//    // cv::waitKey(0);
//
//
//    // GaussianBlur(convertedImage, convertedImage, Size(5,5), 1, 1);
//    // namedWindow("postBlur", WINDOW_NORMAL);
//    // imshow("postBlur", convertedImage);
//
//    // Mat kernelDialte = getStructuringElement(MORPH_RECT, Size(3, 3));
//    // dilate(convertedImage, convertedImage, kernelDialte, Point(-1,-1), 3);
//    // namedWindow("postDialte", WINDOW_NORMAL);
//    // imshow("postDialte", convertedImage);
//
//    threshold(convertedImage, convertedImage, 75, 255, THRESH_BINARY);
//    namedWindow("threshold", WINDOW_NORMAL);
//    imshow("threshold", convertedImage);
//
//    // adaptiveThreshold(convertedImage, convertedImage, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, -5);
//    // namedWindow("adaptiveThreshold", WINDOW_NORMAL);
//    // imshow("adaptiveThreshold", convertedImage);
//
//    Mat kernel = (Mat_<uint8_t>(3, 3) << 0, 1, 0,
//                       0, 1, 0,
//                       0, 1, 0);
//
//    std::cout<<kernel<<std::endl;
//
//    // Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//    dilate(convertedImage, convertedImage, kernel, cv::Point(-1,-1), 2);
//    namedWindow("dilate", WINDOW_NORMAL);
//    imshow("dilate", convertedImage);
//    cv::waitKey();
//
//    Mat imgContour(convertedImage.size(), CV_8UC1, Scalar(0));
//    std::vector<std::vector<Point>> contourPoints;
//    findContours(convertedImage, contourPoints, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    for (size_t i = 0; i < contourPoints.size(); i++) {
//        int area = contourArea(contourPoints[i]);
//        // std::cout<<"Area:"<<area<<std::endl;
//        if (area > 200) {
//            drawContours(imgContour, contourPoints, i, Scalar(255), -1);
//        }
//    }
//    namedWindow("findContours", WINDOW_NORMAL);
//    imshow("findContours", imgContour);
//
//    // kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//    // erode(imgContour, imgContour, kernel);
//    // namedWindow("erode", WINDOW_NORMAL);
//    // imshow("erode", imgContour);
//
//    // GaussianBlur(imgContour, imgContour, Size(5, 5), 1, 1);
//    // namedWindow("GaussianBlur", WINDOW_NORMAL);
//    // imshow("GaussianBlur", imgContour);
//
//
//
//    waitKey(0);
//    return 0;
//}
