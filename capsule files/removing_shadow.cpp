//#include<opencv2/opencv.hpp>
//
//using namespace std;
//using namespace cv;
//
//
//int main()
//{
//	Mat image = imread("capsule files\\image\\img.jpg");
//	Mat hsv;
//	cvtColor(image, hsv, COLOR_BGR2HSV);
//	imshow(" hsv image", hsv);
//
//	for (int i = 0; i <image.rows; i++)
//	{
//		for (int j = 0; j < image.cols; j++)
//		{
//			
//			int s = hsv.at<cv::Vec3b>(i,j)[1];
//			int v= image.at<cv::Vec3b>(i,j)[2];
//			if (s < 45 && v>50)
//			{
//				
//				hsv.at<cv::Vec3b>(i, j)[1] = 0;
//				hsv.at<cv::Vec3b>(i, j)[2] =255 ;
//
//			}
//		}
//	}
//	Mat result;
//	namedWindow("result image", WINDOW_AUTOSIZE);
//	namedWindow("result hsv image", WINDOW_AUTOSIZE);
//	namedWindow("og image", WINDOW_AUTOSIZE);
//	cvtColor(hsv, result, COLOR_HSV2BGR);
//	imshow("result hsv image", hsv);
//	imshow("result image", result);
//	imshow("og image", image);
//	//imwrite("C:\\Users\\User\\source\\repos\\capsule\\capsule files\\image\\output image_final.jpg", result);
//
//	waitKey(0);
//}