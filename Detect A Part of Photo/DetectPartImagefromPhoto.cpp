#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

float w = 250, h = 350;
Mat matrix, imgWarp;

int main() {

	string path = "C:/Users/ASUS/Desktop/card.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {434,116}, {630,148}, {326,317}, {551,371} };
	Point2f dst[4] = { {0.0f,0.0f}, {w,0.0f}, {0.0f,h}, {w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w,h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);

	waitKey(0);



}