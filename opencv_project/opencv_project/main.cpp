#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/nonfree/features2d.hpp>

using namespace std;
using namespace cv;

int main() {
	// 이미지 로드
	Mat mat_ori = cv::imread("C:/works/images/images/lena.png", CV_LOAD_IMAGE_GRAYSCALE);
	Mat mat_input = cv::imread("C:/works/images/images/Lenna.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	// 이미지  원본과 특징점이 있는 그림을 추가하기
	if (mat_ori.empty() || mat_input.empty())
	{
		printf("[오류] 이미지 로드 불가! \n");
		exit(-1);

	}
	// 특징점 찾기
	cv::SurfFeatureDetector detector;
	vector<cv::KeyPoint> keypoints1, keypoints2;
	
	detector.detect( mat_ori, keypoints1);
	detector.detect( mat_input, keypoints2);
	printf("원본 이미지 특징점 개수 = [%zd]\n 입력 이미지 특징점 개수 = [%zd]\n", keypoints1.size(), keypoints2.size());

	// unsigned __int64 [%zd] 하고는 관련이 없는 것 같다.
	//기술자 계산
	// 추가 종속성 추가 features2d2413d.lib 문제 라고 보면된다. 
	// 추가 종속성 추가 features2d2413d.lib 문제 라고 보면된다. 
	cv::SurfDescriptorExtractor extractor;
	Mat descriptor1, descriptor2;
	extractor.compute(mat_ori, keypoints1, descriptor1);
	extractor.compute(mat_input, keypoints2, descriptor2);

	// Brute Force 매칭

	cv::BFMatcher matcher(NORM_L2);
	vector<cv::DMatch> matches;
	matcher.match(descriptor1, descriptor2, matches);
	sort(matches.begin(), matches.end());
	matches.erase(matches.begin() + 25, matches.end());

	// 매칭 결과
	Mat result;
	drawMatches(mat_ori, keypoints1, mat_input, keypoints2, matches, result);

	// 결과 출석
	imshow("SURF Matching", result);
	waitKey();

    return 0;
}


