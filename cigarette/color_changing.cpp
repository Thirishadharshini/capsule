#include"color_changing.hpp"
vector<Mat> cigarettes::directory(const char* input_path)
{
    DIR* dir = opendir(input_path);
    struct dirent* ent;
    int i = 1;
    while ((ent = readdir(dir)) != NULL) {
       
        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
            
            string filePath = string(input_path) + ent->d_name;
            Mat image = cv::imread(filePath);
            img_name.push_back(ent->d_name);
            images.push_back(image);
           
        }
        i++;
    }
    return (images);
}

void cigarettes::resizing(vector<Mat>)
{
    for(int i=0;i<images.size();i++)
    {
        Mat crop_img = images[i](Range(144, 400), Range(0, 240));
        Mat gray_img;
        cvtColor(crop_img, gray_img, COLOR_BGR2GRAY);
        imshow("images", gray_img);
        Mat thresh;
        threshold(gray_img, thresh, 1, 255, THRESH_BINARY_INV);
        imshow("Binary mage", thresh);
        waitKey(0);
    }
}


//// Define HSV range for each color (green, blue, yellow)
//cv::Scalar lower_green(35, 100, 100);
//cv::Scalar upper_green(85, 255, 255);
//cv::Scalar lower_blue(100, 150, 100);
//cv::Scalar upper_blue(140, 255, 255);
//cv::Scalar lower_yellow(20, 100, 100);
//cv::Scalar upper_yellow(30, 255, 255);
//
//// Threshold the image to get only green, blue, and yellow colors
//cv::Mat maskGreen, maskBlue, maskYellow, mask;
//cv::inRange(hsvImg, lower_green, upper_green, maskGreen);
//cv::inRange(hsvImg, lower_blue, upper_blue, maskBlue);
//cv::inRange(hsvImg, lower_yellow, upper_yellow, maskYellow);
//
//// Combine the masks
//mask = maskGreen | maskBlue | maskYellow;
//
//// Optional: Morphological operations to clean up noise
//cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
//cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, kernel);
//cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
//
//// Create a white background image (same size as the input)
//cv::Mat whiteBackground = cv::Mat::ones(re_img.size(), re_img.type()) * 255; // White background
//
//// Invert the mask to find the background (invert so that background is white and capsules are black)
//cv::Mat invertedMask;
//cv::bitwise_not(mask, invertedMask);
//
//// Combine the original image and the white background based on the mask
//cv::Mat result = whiteBackground.clone();
//re_img.copyTo(result, mask);  // Copy only the capsules to the result image (colored parts)
//
//// Show the result
//cv::imshow("Result", result);
//cv::waitKey(0);
