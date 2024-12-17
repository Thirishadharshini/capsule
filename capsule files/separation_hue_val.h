#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include<Windows.h>
#include"dirent.h"
#include <sys/stat.h>
#include <sys/types.h>
#include<filesystem>
#include<direct.h>
using namespace std;
using namespace cv;

class color_difference
{
public:
	void split_images(const char* inputpath);
	vector<Mat> iterating_dir(const char* filepath);
	double hsv_separation(vector<Mat>);
	double  find_median(vector<double>);
	vector<Mat> images;
	vector<double>hue_vector;
	vector<double>val_vector;
	vector<string>img_name;
	vector<string>img_name_other;

	
};