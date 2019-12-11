#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int thresholding_image()
{
	Mat src = imread("C:/works/images/images/lena_gray.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; }
	Mat dst;
	equalizeHist(src, dst);
	imshow("Image", src);
	imshow("Equalized", dst);
	Mat thresholdImg;
	threshold(src, thresholdImg, 100, 255, THRESH_BINARY);
	imshow("Thresholder", thresholdImg);
	waitKey(0);
	return 0;
}