#include "signedConvolution.hpp"

// Function to create a gradient kernel matrix with customizable size
Mat createGradientKernelX(int size, double factor) {
    // Ensure the matrix is square
    Mat kernel = Mat::zeros(size, size, CV_64F);

    // Calculate the midpoint for gradient distribution
    int mid = size / 2;

    // Fill the matrix with a gradient pattern
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j < mid - abs(mid - i)) {
                kernel.at<double>(i, j) = -1;
            } else if (j > mid + abs(mid - i)) {
                kernel.at<double>(i, j) = 1;
            } else {
                kernel.at<double>(i, j) = 0;
            }
        }
    }

    // Apply the scaling factor to the matrix
    kernel = kernel * factor;

    return kernel;
}

Mat createSquareKernelY(int size, double factor) {
    // Create a square matrix with double type initialized with zeros
    Mat kernel = Mat::zeros(size, size, CV_64F);

    // Fill the top half (approximately) with -1
    for (int i = 0; i < size / 2; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel.at<double>(i, j) = -1;
        }
    }

    // Fill the middle row with 0 if the matrix size is odd
    if (size % 2 != 0) {
        for (int j = 0; j < size; ++j) {
            kernel.at<double>(size / 2, j) = 0;
        }
    }

    // Fill the bottom half with 1
    for (int i = (size / 2) + 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            kernel.at<double>(i, j) = 1;
        }
    }

    // Apply the scaling factor to the matrix
    kernel = kernel * factor;

    return kernel;
}

void signedConvolution::signedConvolution(Mat src, Mat &dst) {
    if (src.type() != CV_8U) {
        throw std::runtime_error("Input Image has to be in GrayScale and 8 Bit Depth");
    }
    if (dst.type() != CV_8U) {
        throw std::runtime_error("Output Image has to be in GrayScale and 8 Bit Depth");
    }

    Mat signedImage(src.size(), CV_16S, Scalar(0));

    GaussianBlur(src, src, Size(5, 5), 2, 2);

    src.convertTo(signedImage, CV_16SC1);

    Mat filterX(signedImage.size(), CV_16S);   
    Mat kernelX = (Mat_<double>(5, 5) << -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1);
    filter2D(signedImage, filterX, -1, kernelX);

    Mat convertedImageX(filterX.size(), CV_8U);
     
    namedWindow("convertedX", WINDOW_NORMAL);
    imshow("convertedX", convertedImageX);

    Mat filterX2(signedImage.size(), CV_16S);   
    Mat kernelX2 = (Mat_<double>(5, 5) << 1, 1, 0, -1, -1,
                       -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1,
                       -1, -1, 0, 1, 1);
    filter2D(signedImage, filterX2, -1, kernelX2);

    Mat convertedImageX2(filterX2.size(), CV_8U);
    filterX2.convertTo(convertedImageX2, CV_8UC1);
    namedWindow("convertedX2", WINDOW_NORMAL);
    imshow("convertedX2", convertedImageX2);

    Mat filterY(signedImage.size(), CV_16S, Scalar(0));
    // Mat kernelY = 3 * (Mat_<double>(3, 3) << -1, -1, -1,
    //                                      0,  0,  0,
    //                                      1,  1,  1);
    Mat kernelY = (Mat_<double>(5, 5) << -1, -1, -1, -1, -1,
                       -1, -1, -1, -1, -1,
                       0, 0, 0, 0, 0,
                       1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1);
    // Mat kernelY = (1 / 8.0) * (Mat_<double>(7, 7) << -1, -1, -1, -1, -1, -1, -1,
    //                           -1, -1, -1, -1, -1, -1, -1,
    //                           -1, -1, -1, -1, -1, -1, -1,
    //                           0, 0, 0, 0, 0, 0, 0,
    //                           1, 1, 1, 1, 1, 1, 1,
    //                           1, 1, 1, 1, 1, 1, 1,
    //                           1, 1, 1, 1, 1, 1, 1);
    // int kernelSize = 3;
    // Mat kernelY = createSquareKernelY(kernelSize, 1.0);

    // std::cout << "Kernel:" << kernelY << std::endl;
    filter2D(signedImage, filterY, -1, kernelY);

    Mat convertedImageY(filterY.size(), CV_8U);
    filterY.convertTo(convertedImageY, CV_8UC1);
    namedWindow("convertedY", WINDOW_NORMAL);
    imshow("convertedY", convertedImageY);


    Mat filterY2(signedImage.size(), CV_16S, Scalar(0));

    Mat kernelY2 = (Mat_<double>(5, 5) << 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1,
                       0, 0, 0, 0, 0,
                       -1, -1, -1, -1, -1,
                       -1, -1, -1, -1, -1);
   
    filter2D(signedImage, filterY2, -1, kernelY2);

    Mat convertedImageY2(filterY2.size(), CV_8U);
    filterY2.convertTo(convertedImageY2, CV_8UC1);
    namedWindow("convertedY2", WINDOW_NORMAL);
    imshow("convertedY2", convertedImageY2);

    // GaussianBlur(convertedImageY, convertedImageY, Size(5, 5), 2, 2);
    // namedWindow("postBlur", WINDOW_NORMAL);
    // imshow("postBlur", convertedImageY);

    Mat convertedImage;
    add(convertedImageY2, convertedImageY, convertedImage);
    namedWindow("add", WINDOW_NORMAL);
    imshow("add", convertedImage);

    // Mat imgOr;
    // bitwise_or(convertedImageX, convertedImageY, imgOr);
    // namedWindow("bitwise_or", WINDOW_NORMAL);
    // imshow("bitwise_or", imgOr);

    // convertedImageY = 4 * convertedImageY;

    dst = convertedImageY.clone();
}