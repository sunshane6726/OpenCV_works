// histogram equalization 히스토그램 평활화 작업하기
// int main()을 histogram equalization 으로 바꾸어서 공부하기
// works station에서 작업하기

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int histograme equalization()
{
	Mat src = imread("C:/works/images/images/lena_gray.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; }
	Mat dst;
	equalizeHist(src, dst);
	imshow("Image", src);
	imshow("Equalized", dst);
	waitKey(0);
	return 0;
}