#pragma once
//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<dirent.h>
//using namespace std;
//using namespace cv;
//int main() {
//	
//    DIR* dir = opendir("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\");
//    struct dirent* ent;
//    while ((ent = readdir(dir)) != NULL) {
//        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
//            string filePath = string("C:\\office works\\color_check\\cropped\\Image_20241014110326593.jpg\\") + ent->d_name;
//            Mat image = cv::imread(filePath);
//    
//			imshow("original image", image);
//            
//		
//			
//			//imwrite("C:\\office works\\Files_RWF_White\\white_light\\sharpened new kernel\\" +(ent->d_name+to_string(6)+".jpg"), sharp);
//
////			imwrite(string("C:/office works\Files_RWF_White\\white_light\\sharpened new kernel\\")+ent->d_name+"_6", sharp);
//
//			
//           
//            waitKey(0);
//        }
//    }
//    closedir(dir);
//    return 0;
//}
