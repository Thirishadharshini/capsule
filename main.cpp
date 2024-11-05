//#include"capsule files/separation_hue_val.h"
//#include"cigarette/color_changing.h"
//
//
//class remove_shadow {
//public:
//    void function(const char* inputpath)
//    {
//        cv::Mat image = cv::imread(inputpath);
//        
//        Mat re_img;
//        resize(image, re_img, Size(500, 500), INTER_AREA);
//   
//            
//
//    }
//};
//
//int main()
//{
//    // for color differentian algorithm
//     color_difference cd;
//     ////give your input path directory
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110348798.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110552648.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110623820.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110729433.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110828610.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110848184.jpg\\");
//     //cd.split_images("C:\\office works\\color_check\\cropped\\Image_20241014110904843.jpg\\");
//
//   /* cigarettes cigar;
//    cigar.resizing(cigar.directory("C:\\office works\\MixPod_Red\\"));*/
//
//     remove_shadow rc;
//     rc.function("capsule files\\img.jpg");
//
//     return 0;
//}
//
//
//for (int x = 0; x < hsv.cols; x++)
//{
//    for (int y = 0; y < hsv.rows; y++)
//    {
//        int h = image.at<cv::Vec3b>(x, y)[0];
//        cout << h << ' ';
//    }
//}cout << endl;


#include"velz/changeprespective.hpp"


int main()
{
    changeperspective cp;

    cv::Mat out = cp.ChangePerspective("C:\\Users\\User\\MVS\\Data\\Image_20241104170148900.bmp");
    imshow("outputimg", out);
    cv::waitKey(0);
}

