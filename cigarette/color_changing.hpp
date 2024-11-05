#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>
#include <vector>
#include<dirent.h>
#include<direct.h>
#include<opencv2/opencv.hpp>
#include<iterator>
#include<Windows.h>
using namespace std;
using namespace cv;

class cigarettes {
public:
	vector<Mat> directory(const char* input_path);
	void resizing(vector<Mat>);
	vector<Mat>images;
	vector<string>img_name;
};