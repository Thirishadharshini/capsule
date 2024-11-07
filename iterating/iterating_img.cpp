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
//    int count= 2;
//    cout << "InitCount:"<<count << endl;
//    while ((ent = readdir(dir)) != NULL) {
//       
//        cout << "Count:" << count << endl;
//        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
//            string filePath = string("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\") + ent->d_name;
//            image = cv::imread(filePath);
//            imshow("original image", image);
//            Mat hsv;
//            cvtColor(image, hsv, COLOR_RGB2HSV_FULL);
//            imshow("converted image", hsv);
//            cout << "Count:"<<count << endl;
//            int rows = image.rows;
//            int cols = image.cols;
// 
//            int centerX = cols / 2;
//            int centerY = rows / 2;
//
//            cv::Vec3b pixelColor = hsv.at<Vec3b >(centerY, centerX);
//
//           
//            std::cout << "Center Pixel Color (hsv): ("
//                << (int)pixelColor[0] << ", "
//                << (int)pixelColor[1] << ", "
//                << (int)pixelColor[2] << ")" << std::endl;
//
//            //  pair<int, int>v;
//            cout << count << endl;
//            v.push_back((int)pixelColor[0]);
//            //cout << v[count];
//            for (int a : v)
//            {
//                cout << a;
//            }
//            cout << "inside for loop "<<count<< endl;
//            
//            string name = string(ent->d_name) + ".jpg";
//            cout << "inside for loop " << name << endl;
//            if (!v.empty() && count <=v.size()) {
//
//                cout << "inside for loop " << name << endl;
//                cout << v[count];
//                if (v[count] > 82 && v[count] < 85)
//                {
//                    cout << "inside for loop " << name << endl;
//                    //imwrite("C:/office works/color_check/seperated/Image_20241014110326593.jpg/" + (ent->d_name+".jpg"), image);
//                    imwrite("C:\\office works\\color_check\\seperated\\Image_20241014110326593.jpg\\" + name, image);
//
//                }
//            }
//
//            waitKey(0);
//
//        }count++;           
//    }
//    closedir(dir);
//    return 0;
//}            //imwrite("C:\\office works\\Files_RWF_White\\white_light\\sharpened new kernel\\" +(ent->d_name+to_string(6)+".jpg"), sharp);
//
////			imwrite(string("C:/office works\Files_RWF_White\\white_light\\sharpened new kernel\\")+ent->d_name+"_6", sharp);
//
//
