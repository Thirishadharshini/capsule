//#include<opencv2/opencv.hpp>
//#include<iostream>
//
//using namespace std;
//using namespace cv;
///*class circle_thick {
//public:
//	static int circle_thickness*/
//////bool findCircleLineIntersections(Point2f center, float radius, Point2f lineStart, Point2f lineEnd, Point2f& intersection1, Point2f& intersection2) {
////Point2f d = lineEnd - lineStart;
////Point2f f = lineStart - center;
////
////
////float a = d.dot(d);
////float b = 2 * f.dot(d);
////float c = f.dot(f) - radius * radius;
////cout << "a" << a << endl << "b" << b << endl << "c" << c << endl;
////
////// Calculate the discriminant
////float discriminant = b * b - 4 * a * c;
////
////// No intersection if discriminant is negative
////if (discriminant < 0) return false;
////
////// Use the quadratic formula to find the two points of intersection
////discriminant = sqrt(discriminant);
////float t1 = (-b + discriminant) / (2 * a);
////float t2 = (-b - discriminant) / (2 * a);
////
////intersection1 = lineStart + t1 * d;
////intersection2 = lineStart + t2 * d;
////
////return true;
//bool findCircleLineIntersections(Point2f center, float radius, Point2f lineStart, Point2f lineEnd, Point2f& intersection1) {
//	// 
//	int slope= lineEnd.y - lineStart.y/ lineEnd.x - lineStart.x;
//	
//	Point2f d = lineEnd - lineStart;
//	Point2f f = lineStart - center;
//
//	
//	float a = ;
//	float b = 2 * f.dot(d);
//	float c = f.dot(f) - radius * radius;
//	cout << "a" << a << endl << "b" << b << endl << "c" << c << endl;
//
//	// Calculate the discriminant
//	float discriminant = b * b - 4 * a * c;
//
//	// No intersection if discriminant is negative
//	if (discriminant < 0) return false;
//
//	// Use the quadratic formula to find the two points of intersection
//	discriminant = sqrt(discriminant);
//	float t1 = (-b + discriminant) / (2 * a);
//	float t2 = (-b - discriminant) / (2 * a);
//
//	intersection1 = lineStart + t1 * d;
//	
//
//	return true;
//}
//
//int main()
//	{
//		Mat image = imread("C:\\Users\\User\\source\\repos\\capsule\\circle\\WhatsApp Image 2024-11-27 at 16.46.48_f89bb199.jpg");
//		Mat gray;
//		
//		cvtColor(image,gray, COLOR_BGR2GRAY);
//		Mat thresh;
//		threshold(gray, thresh, 128, 200, THRESH_BINARY_INV);
//		
//		imshow("binary image", thresh);
//		
//		// detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
//		vector<vector<Point>> contours;
//		vector<Vec4i> hierarchy;
//		findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
//		// draw contours on the original image
//		Mat image_copy = image.clone();
//		/*drawContours(image_copy, contours, -1, Scalar(0, 255, 255), 2);
//		imshow("None approximation", image_copy);
//		     */
//
//		for (int i = 0; i < contours.size(); i++)
//		{
//			cout << "area of contour " << contourArea(contours[i]) << endl;
//			cout << i << endl;
//			drawContours(image_copy, contours, i, Scalar(0, 255, 255), 2);
//			imshow("None approximation", image_copy);
//			
//
//			
//		}
//		vector<Point> outercontour = contours.at(3);
//		
//		/*for (int i = 0; i < outercontour.size(); i++)
//		{
//			Point coordinate_i_ofcontour = outercontour[i];
//			cout << endl << "contour with coordinates: x = " << coordinate_i_ofcontour.x << " y = " << coordinate_i_ofcontour.y;
//		}*/
//	
//		Point2f innerCenter, outerCenter;
//		float innerRadius, outerRadius;
//		
//
//		minEnclosingCircle(contours[3], innerCenter, innerRadius);
//		circle(image, innerCenter,2, 255, 3, 8, 0);
//		imshow(" inner center", image);
//		
//		minEnclosingCircle(contours[2], outerCenter, outerRadius);
//		circle(image, outerCenter, 2, 200, 3, 8, 0);
//		imshow(" outer center", image);
//
//		cout << "Inner center: " << innerCenter << endl;
//		cout << "Outer center: " << outerCenter << endl;
//		cout << "Inner Radius: " << innerRadius << endl;
//		cout << "Outer Radius: " << outerRadius << endl;
//
//		for (int angle = 0; angle < 360;angle+=10)
//		{
//			double s = sin(angle * CV_PI / 180);
//			double c = cos(angle * CV_PI / 180);
//			Point2f out(outerCenter.x +outerRadius* s , outerCenter.y+outerRadius *c);
//		    Point2f in(innerCenter.x + innerRadius * s, innerCenter.y + innerRadius * c);
//
//			line(image, innerCenter,out, Scalar(255, 0, 0), 2);
//			
//
//		
//			Point2f intersection1, intersection2;
//			//if (findCircleLineIntersections(innerCenter, innerRadius, innerCenter, out, intersection1, intersection2)) {
//				if (findCircleLineIntersections(innerCenter, innerRadius, innerCenter, out, intersection1)) {
//
//				circle(image, intersection1, 3, Scalar(0, 255, 0), -1); 
//				
//			}
//			//line(image, innerCenter,in, Scalar(0, 255, 0), 2);
//			imshow(" line image1", image);
//			waitKey(0);
//			float thickness = norm(out - intersection1);
//			cout << "Angle: " << angle << " degrees, Thickness: " << thickness << endl;
//		}
//
//		waitKey(0);
//		return 0;
//}
