//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include <vector>
//#include<dirent.h>
//
////#include"iterating/interating_img.cpp"  
//using namespace std;
//using namespace cv;
//int main() {
//    vector<int> v;
//    Mat image;
//    DIR* dir = opendir("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\");
//    //DIR* dir = opendir("C:\\office works\\color_check\\others\\");
//    struct dirent* ent;
//    int i = -1;
//    int others_count = 0;
//    int green_count = 0;
//    int dark_green_count = 0;
//    int light_green_count = 0;
//    int yellow_count = 0, dark_yellow_count = 0, light_yellow_count = 0;
//    int blue_count = 0, dark_blue_count = 0, light_blue_count = 0;
//    //1.iterating through dir
//    while ((ent = readdir(dir)) != NULL) {
//
//
//        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
//            string filePath = string("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\") + ent->d_name;
//            //string filePath = string("C:\\office works\\color_check\\others\\") + ent->d_name;
//
//            image = cv::imread(filePath);
//            imshow("original image", image);
//
//            cout << "image number:" << i << endl;
//
//            //2.convert color to hsvfull
//            Mat hsv;
//            cvtColor(image, hsv, COLOR_RGB2HSV_FULL);
//
//            //3.create a rectangle
//            int rows = image.rows;
//            int cols = image.cols;
//
//            // particular area
//            Rect rectangle(rows / 2, cols / 2, 10, 10);
//            Mat roiImage = hsv(rectangle);
//
//            //4.split those rect and store in a vector
//            vector<Mat> hsv_channels;
//            split(roiImage, hsv_channels);
//
//            //5.take only hue value
//            Mat hue_channel = hsv_channels[0];
//
//            //6.find mean of that hue values 
//            Scalar mean_val;
//            mean_val = mean(hue_channel);
//
//            //cvt scalar into double
//            double avg_val = mean_val[0];
//
//            //take only val value
//            Mat val_channel = hsv_channels[2];
//
//            Scalar mean_val_value;
//            mean_val_value = mean(val_channel);
//
//            //cvt scalar into double
//            double avg_val_value = mean_val_value[0];
//
//            //7.condition for seperating
//            if (avg_val > 79 && avg_val < 100)
//            {
//                green_count++;
//                imwrite("C:\\office works\\color_check\\green\\green_seperated\\Image_20241014110326593.jpg\\" + string(ent->d_name), image);
//
//                if (avg_val_value > 115 && avg_val_value < 137)
//                {
//                    dark_green_count++;
//                    imwrite("C:\\office works\\color_check\\green\\val and hue\\Image_20241014110326593.jpg\\dark_green\\" + string(ent->d_name), image);
//                }
//                else
//                {
//                    light_green_count++;
//                    imwrite("C:\\office works\\color_check\\green\\val and hue\\Image_20241014110326593.jpg\\dark_green\\" + string(ent->d_name), image);
//                }
//            }
//            else
//            {
//                others_count++;
//                if (avg_val > 135)
//                {
//                    yellow_count++;
//                    imwrite("C:\\office works\\color_check\\yellow\\yellow_seperated\\" + string(ent->d_name), image);
//                    if (avg_val_value < 175)
//                    {
//                        dark_yellow_count++;
//                        imwrite("C:\\office works\\color_check\\yellow\\val and hue\\Image_20241014110326593.jpg\\dark_yellow\\" + string(ent->d_name), image);
//                    }
//                    else
//                    {
//                        light_yellow_count++;
//                        imwrite("C:\\office works\\color_check\\yellow\\val and hue\\Image_20241014110326593.jpg\\light_yellow\\" + string(ent->d_name), image);
//                    }
//                }
//                if (avg_val < 35)
//                {
//                    blue_count++;
//                    imwrite("C:\\office works\\color_check\\blue\\blue_seperated\\" + string(ent->d_name), image);
//                    if (avg_val_value < 135)
//                    {
//                        dark_blue_count++;
//                        imwrite("C:\\office works\\color_check\\blue\\val and hue\\Image_20241014110326593.jpg\\dark blue\\" + string(ent->d_name), image);
//                    }
//                    else
//                    {
//                        light_blue_count++;
//                        imwrite("C:\\office works\\color_check\\blue\\val and hue\\Image_20241014110326593.jpg\\light blue\\" + string(ent->d_name), image);
//                    }
//                }
//            }
//
//        }
//        i++;
//    }
//    if (green_count > others_count)
//    {
//        cout << "Green capsule is the most" << green_count << endl;
//        if (dark_green_count > light_green_count)
//            cout << "Dark green capsule is the most:" << dark_green_count << endl;
//        else
//            cout << "Light green capsule is the most:" << light_green_count << endl;
//    }
//    else
//    {
//        if (yellow_count > blue_count)
//        {
//            cout << "Yellow capsule is the most" << yellow_count << endl;
//            if (dark_yellow_count > light_yellow_count)
//                cout << "Dark Yellow capsule is the most:" << dark_yellow_count << endl;
//            else
//                cout << "Light Yellow capsule is the most:" << light_yellow_count << endl;
//        }
//        else
//        {
//            cout << "Blue capsule is the most" << blue_count << endl;
//            if (dark_blue_count > light_blue_count)
//                cout << "Dark blue capsule is the most:" << dark_blue_count << endl;
//            else
//                cout << "Light blue capsule is the most:" << light_blue_count << endl;
//        }
//    }
//
//
//    closedir(dir);
//    return 0;
//}
