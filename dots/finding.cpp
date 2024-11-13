#include<opencv2/opencv.hpp>
#include<iostream>
#include<dirent.h>
#include<vector>


static void find_dots()
{
			
			cv::Mat image = cv::imread("braille_images\\Image_20241111103159364.bmp");
			cv::Mat image1 = cv::imread("braille_images\\image_400.jpg");
			cv::imshow("og image", image);
			cv::imshow("og image1", image1);
			cv::Mat cont = image * 2;
			cv::Mat cont1 = image1 * 2;
			cv::Mat img_gray,img_gray1;
			cv::cvtColor(cont, img_gray, cv::COLOR_BGR2GRAY);
			cv::cvtColor(cont1, img_gray1, cv::COLOR_BGR2GRAY);
			cv::Mat blur,blur1;
			cv::GaussianBlur(img_gray, blur, cv::Size(9,9), 0);
			cv::GaussianBlur(img_gray1, blur1, cv::Size(9,9), 0);
			cv::Mat edges,edges1;
			cv::Laplacian(blur, edges, CV_8U, 9);
			cv::Laplacian(blur1, edges1, CV_8U, 9);
			imshow("Laplacian edge detection", edges);
			imshow("Laplacian edge detection 1", edges1);
			cv::imwrite("C:\\Users\\User\\MVS\\Data\\light_on_image\\Image_20241111103159364_cont2.bmp",edges);
			cv::imwrite("C:\\Users\\User\\MVS\\Data\\light_on_image\\image_400_cont2.bmp",edges1);
			cv::waitKey(0);

			

			

		}
	
