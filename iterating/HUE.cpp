//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include <vector>
//#include<dirent.h>
////#include"iterating/interating_img.cpp"  
//using namespace std;
//using namespace cv;
//int main() {
//    vector<int> v;
//    Mat image;
//    DIR* dir = opendir("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\");
//    struct dirent* ent;
//    int i = -1;
//    //1.iterating through dir
//    while ((ent = readdir(dir)) != NULL) {
//
//       
//        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
//            string filePath = string("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\") + ent->d_name;
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
//            cout << "hue values of rect" << hue_channel << endl;
//
//            //6.find mean of that hue values 
//            Scalar mean_val;
//            mean_val = mean(hue_channel);
//            cout << "scalar value of mean:" << mean_val << endl;
//
//            //cvt scalar into double
//            float avg_val = mean_val[0];
//            cout << "average value:" << avg_val << endl;
//
//
//            //take only sat value
//            Mat sat_channel = hsv_channels[1];
//            cout << "sat values of rect" << sat_channel << endl;
//
//            Scalar mean_val_sat;
//            mean_val_sat = mean(sat_channel);
//            cout << "scalar value of mean for sat:" << mean_val_sat << endl;
//
//            //cvt scalar into double
//            float avg_val_sat = mean_val_sat[0];
//            cout << "average value for sat:" << avg_val_sat << endl;
//
//            //7.condition for seperating
//            if (avg_val > 79 && avg_val < 100)
//            {
//                imwrite("C:\\office works\\color_check\\seperated\\Image_20241014110326593.jpg\\" + string(ent->d_name), image);
//            }
//            else
//                imwrite("C:\\office works\\color_check\\seperated_other\\Image_20241014110326593.jpg\\" + string(ent->d_name), image);
//            waitKey(0);
//        }
//        i++;
//    }
//    closedir(dir);
//    return 0;
//}
//String commonpath = "C:\\office works\\color_check\\median\\seperated\\";
//wstring folderPath_major = L"C:\\office works\\color_check\\median\\seperated\\filtered\\";
//wstring folderPath_minor = L"C:\\office works\\color_check\\median\\seperated\\median_range\\";
//wstring folderPath_m = L"C:\\office works\\color_check\\median\\seperated\\out of range\\";
//wstring folderPath_other = L"C:\\office works\\color_check\\median\\seperated\\others\\";
//
////imwrite(wstring_to_string(folderPath_minor + img_name_w), images[i]);
//CreateDirectory(folderPath_major.c_str(), NULL);
//CreateDirectory(folderPath_minor.c_str(), NULL);
//CreateDirectory(folderPath_m.c_str(), NULL);
//CreateDirectory(folderPath_other.c_str(), NULL);
//string color_difference::wstring_to_string(const wstring& wstr) {
//    string str(wstr.length(), 0);
//    WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, &str[0], str.length(), NULL, NULL);
//    return str;
//}