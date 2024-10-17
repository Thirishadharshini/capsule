#include"Header.h"


void capsule::seperation_capsule(const char* file_Path,const char* outpath)
{
    string file_in_path = file_Path;
    cout << file_in_path << endl;
    DIR* dir = opendir(file_Path);
    
    struct dirent* ent;

    cout << "seperation loop stars" << endl;
    //1.iterating through dir
    while ((ent = readdir(dir)) != NULL) {


        if (ent->d_type == DT_REG && strcmp(ent->d_name + strlen(ent->d_name) - 4, ".jpg") == 0) {
            string filePath = string(file_Path) + ent->d_name;
            Mat i = cv::imread(filePath);
            
            resize(i, image, Size(110, 110));


            //2.convert color to hsvfull
            Mat hsv;
            cvtColor(image, hsv, COLOR_RGB2HSV_FULL);

            //3.create a rectangle
            int rows = image.rows;
            int cols = image.cols;
           
             //particular area
             Rect rectangle(rows / 2, cols / 2, 10, 10);
             Mat roiImage = hsv(rectangle);

            //4.split those rect and store in a vector
            vector<Mat> hsv_channels;
            split(roiImage, hsv_channels);

            //5.take only hue value
            Mat hue_channel = hsv_channels[0];

            //6.find mean of that hue values 
            Scalar mean_val;
            mean_val = mean(hue_channel);

            //cvt scalar into double
            int avg_val = mean_val[0];
            hue_vector.push_back(avg_val);

            mp[ent->d_name] = avg_val;
            
            //take only sat value
            Mat val_channel = hsv_channels[2];
           

            Scalar mean_val_value;
            mean_val_value = mean(val_channel);
            
            //cvt scalar into double
            int avg_val_value = mean_val_value[0];
            val_vector.push_back(avg_val_value);

            mp_val[ent->d_name] = avg_val_value;
        }
                                                              
    }
    closedir(dir);

    //get the maximum hue value
    int max = max_color(hue_vector);

    //to store the image in folder
    map<string, int>::iterator it = mp.begin();
    map<string, int>::iterator it1 = mp_val.begin();
    while (it != mp.end())
    {
        cout << "iterate method starts" << endl;
        Mat img = imread(file_Path + it->first);
        cout << "max value " << max << "  it second " << it->second<<endl;
        //if ((it->second) == max )
        if((it->second)>=max-10 &&(it->second)<max+10) 
        {   
            cout << "if condition" << endl;
            imwrite(outpath + it->first, img);  
        }                             
        else
            imwrite("C:\\office works\\color_check\\waste\\" + it->first, img);
        it++;
    }
}
//for finding max number of times hue is present
int capsule::max_color(vector<int> hue_vector)       
{
    int maxCount = 0;
    int maxValue = -1;
    unordered_map<int, int> countMap;
    for (auto& elem : hue_vector) {
        countMap[elem]++;
    }
   
    for (auto& pair : countMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxValue = pair.first;
        }
    }
    cout << "maximum hue value:" << maxValue << endl;
    return maxValue;

}
