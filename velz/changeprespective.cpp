#include "changeprespective.hpp"

cv::Mat changeperspective::ChangePerspective(std::string path)
{
    //read the image 
    input = imread(path, cv::IMREAD_GRAYSCALE);
    imshow("input", input);

    cv::Mat sharp_img;
    cv::Mat kernel3 = (cv::Mat_<double>(3, 3) << -2, -1, 0, -1, 1, 1, 0, 1, 2);
    filter2D(input, sharp_img, -1, kernel3, cv::Point(-1, -1), 0, cv::BORDER_DEFAULT);
    
    imshow("Sharpenned", sharp_img);
    
    cv::waitKey(0);
    // thresholding
    threshold(input, threshimg, 95, 255, cv::THRESH_BINARY) ;
    imshow("threshimg", threshimg);
    std::cout << "*******";
    // find contours
    findContours(threshimg, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    // iterating the contours
    for (int i = 0; i < contours.size(); i++) {
        // iterating contours area
        a = cv::contourArea(contours[i]);
        cv::namedWindow("outputimg", cv::WINDOW_FREERATIO);
       /* drawContours(input, contours, i, cv::Scalar(255, 0, 0), 2);
        imshow("outputimg", input);
        cv::waitKey(0);*/
        // condition check if the area has four sharp corners
        if (a > 5000)
        {
           /* drawContours(input, contours, i, cv::Scalar(255, 0, 0), 2);*/
            approxPolyDP(contours[i], approx, 0.02 * arcLength(contours[i], true), true);
            imshow("outputimg", input);
            cv::waitKey(0);
            
            if (approx.size() == 4) {
               
                cv::Point2f pts1[4] = { approx[0], approx[3], approx[1],  approx[2] };
                cv::Point2f pts2[4] = { cv::Point2f(0, 0), cv::Point2f(input.cols, 0), cv::Point2f(0, input.rows), cv::Point2f(input.cols,  input.rows) };
                //after getting four points of corner transform the image
                perspectivetrans = cv::getPerspectiveTransform(pts1, pts2);
                cv::warpPerspective(input, transformedimg, perspectivetrans, input.size());
                cv::imwrite("C:\\Users\\User\\MVS\\Data\\output1.jpg", transformedimg);
            }
        }
    }
    //imshow("outputimg", input);
    cv::waitKey(0);
    return transformedimg;
}


