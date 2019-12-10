// histogram equalization ������׷� ��Ȱȭ �۾��ϱ�
// int main()�� histogram equalization ���� �ٲپ �����ϱ�
// works station���� �۾��ϱ�

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