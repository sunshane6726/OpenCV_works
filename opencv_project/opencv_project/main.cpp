#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/nonfree/features2d.hpp>

using namespace std;
using namespace cv;

int main() {
	// �̹��� �ε�
	Mat mat_ori = cv::imread("C:/works/OpenCV_works/images/images/original.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat mat_input = cv::imread("C:/works/OpenCV_works/images/images/input.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	if (mat_ori.empty() || mat_input.empty())
	{
		printf("[����] �̹��� �ε� �Ұ�! \n");
		exit(-1);

	}
	// Ư¡�� ã��
	cv::SurfFeatureDetector detector;
	vector<cv::KeyPoint> keypoints1;
	vector<cv::KeyPoint> keypoints2;
	detector.detect( mat_ori, keypoints1);
	detector.detect( mat_input, keypoints2);
	

	printf("���� �̹��� Ư¡�� ���� = [%d]/n �Է� �̹��� Ư¡�� ���� = [%d]/n", keypoints1.size(), keypoints2.size());

	//����� ���

	cv::SurfDescriptorExtractor extractor;
	Mat descriptor1, descriptor2;
	extractor.compute(mat_ori, keypoints1, descriptor1);
	extractor.compute(mat_input, keypoints2, descriptor2);

	// Brute Force ��Ī

	cv::BFMatcher matcher(NORM_L2);
	vector<cv::DMatch> matches;
	matcher.match(descriptor1, descriptor2, matches);
	sort(matches.begin(), matches.end());
	matches.erase(matches.begin() + 25, matches.end());

	// ��Ī ���
	Mat result;
	drawMatches(mat_ori, keypoints1, mat_input, keypoints2, matches, result);

	// ��� �⼮
	imshow("SURF Matching", result);
	waitKey();

    return 0;
}


