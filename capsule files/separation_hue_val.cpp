//#include"separation_hue_val.h"
//
////iterating the directory
//vector<Mat> color_difference::iterating_dir(const char* filepath)
//{
//    DIR* dir = opendir(filepath);
//    struct dirent* ent;
//  
//    while ((ent = readdir(dir)) != NULL) {
//        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
//            string filePath = string(filepath) + ent->d_name;
//            Mat image = cv::imread(filePath);
//            if (image.rows > 80 && image.cols >80)
//            {
//                images.push_back(image);
//                img_name.push_back(ent->d_name);
//            }
//            /*else
//            {
//                img_name_other.push_back(ent->d_name);
//                cout << " failed image:" << ent->d_name;
//                imwrite("C:\\office works\\color_check\\cropped\\" + string(ent->d_name), image);
//                waitKey(0);
//            }*/
//        }
//    }
//    closedir(dir);
//    return images;
//}
////finding hsv value for separation
//double color_difference::hsv_separation(vector<Mat> images)
//{
//    for (int i = 0; i < images.size(); i++)
//    {
//        int rows = images[i].rows;
//        int cols = images[i].cols;
//        int x = rows / 2;
//        int y = cols / 2;
//        int range = (int)(0.2 * min(rows, cols));
//        Rect rectangle(x - range, y - range, 2 * range, 2 * range);
//        Mat roiImage = images[i](rectangle);
//
//        //convert image to hsvfull for accuracy
//        Mat hsv;
//        cvtColor(roiImage, hsv, COLOR_RGB2HSV_FULL);
//        vector<Mat> hsv_channels;
//        split(hsv, hsv_channels);
//        Mat channel = hsv_channels[0];//'0' refers to hue channel
//        Scalar mean_val;
//        mean_val = mean(channel);
//        double avg_val = mean_val[0];
//        hue_vector.push_back(avg_val);
//        
//        Mat val_channel = hsv_channels[2];//'2' refers to Value channel
//        Scalar mean_val_value;
//        mean_val_value = mean(val_channel);
//        double avg_val_value = mean_val_value[0];
//        val_vector.push_back(avg_val_value);
//    }
//    return 0;
//}
//// finding median
//double color_difference::find_median(vector<double> v)
//{
//    sort(v.begin(), v.end());//sort the vector
//    double median;
//    if (v.size() % 2 == 0) 
//        median = (v[v.size() / 2- 1] + v[v.size() / 2]) / 2.0;
//    else 
//        median = v[v.size() / 2.0];
//    return median;
//}
////creating folder
//void makefolder(const char* dirName) 
//{
//        if (_mkdir(dirName) == -1) {
//            char buffer[256];
//            strerror_s(buffer, sizeof(buffer), errno);
//            cerr << "Error: " << buffer <<endl;
//        }
//        else {
//            cout << "Directory created successfully" << endl;
//    }
//}
//void color_difference::split_images(const char* inputpath)
//{
//   string inputPath = inputpath;//store as string
//   hsv_separation(iterating_dir(inputpath));   
//   double mid_hue=find_median(hue_vector);
//   double mid_val=find_median(val_vector);
//
//   String filtercolorfolder = inputPath + "filtered\\";
//   String Inrangefolder = inputPath + "in_range\\";
//   String out_of_rangefolder = inputPath + "out_of_range\\";
//   String unwantedfolder = inputPath + "waste_color\\";
//   makefolder(filtercolorfolder.c_str());
//   makefolder(Inrangefolder.c_str());
//   makefolder(out_of_rangefolder.c_str());
//   makefolder(unwantedfolder.c_str());
//
//   //check the condition and write the images in separate folder 
//   for (int i = 0; i < images.size(); i++) {
//       string filename = to_string(i) + ".jpg";
//       double hue_Value = hue_vector[i];
//       double val_Value = val_vector[i];
//       if (hue_Value<=mid_hue+15 && hue_Value>mid_hue-15) 
//       {
//           imwrite(filtercolorfolder + img_name[i], images[i]);
//           
//           if (val_Value >= mid_val -(mid_val*20/100))
//               imwrite(Inrangefolder + img_name[i], images[i]);
//           else
//               imwrite(out_of_rangefolder + img_name[i], images[i]);       
//       }
//       else 
//           imwrite(unwantedfolder + img_name[i], images[i]);          
//   }
// 
//}
//
//
//
//
//
//
