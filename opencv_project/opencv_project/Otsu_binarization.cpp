#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int Otsu_binarization()
{
	Mat src = imread("C:/works/openCV/images/lena_gray.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; }
	Mat dst;
	equalizeHist(src, dst);
	imshow("Image", src);
	imshow("Equalized", dst);
	Mat thresholdImg, thresholdOtsu; threshold(src, thresholdImg, 100, 255, THRESH_BINARY);
	threshold(src, thresholdOtsu, 100, 255, THRESH_BINARY | CV_THRESH_OTSU);
	imshow("Thresholder", thresholdImg);
	imshow("Otsu Thresholder", thresholdOtsu);
	waitKey(0);
	return 0;
}