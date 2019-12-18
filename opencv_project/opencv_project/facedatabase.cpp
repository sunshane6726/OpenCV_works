#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>

using namespace cv;
using namespace std;

static void read_images(vector<Mat>& images, vector<int>& labels, Mat& test_image, int test_label)
{
	char file_path[128];
	int people_cnt;
	int face_cnt;
	int test_people_num;

	Mat test_image2;

	//데이터베이스에 이미지 얼굴 연결하기
	for (people_cnt = 1; people_cnt <= 10; people_cnt++)
	{
		for (face_cnt = 1; face_cnt <= 9; face_cnt++)
		{
			sprintf(file_path, "C://works/OpenCV_works/att_faces/s%d/%d.pgm", people_cnt, face_cnt);
			images.push_back(imread(file_path, CV_LOAD_IMAGE_GRAYSCALE));
			labels.push_back(people_cnt);

		}
	}
	// 인지 테스트 위한 얼굴 이미지 로드하기

	sprintf(file_path, "C://works/OpenCV_works/att_faces/s%d/%d.pgm", 3, 10);
	test_image = imread(file_path, CV_LOAD_IMAGE_GRAYSCALE);
}

int main(void)
{
	Ptr<FaceRecognizer> model;
	vector<Mat> images;
	vector<int> labels;

	Mat test_image;
	Mat predicted_image;
	string result_message;
	int predicted_label;
	//char file_path2[128];
	//Mat test_image2;


	//얼굴 데이터베이스와 인지 테스트를 위한 이미지 얼굴 로드하기
	read_images(images, labels, test_image, 1);


	// 새로운 패턴인식자를 창조한다.
	model = createEigenFaceRecognizer();

	//주어진 데이터와 연관된 라벨을 함께한 체로 얼굴 인식자를 훈련시킨다.
	model->train(images, labels);

	// 주어진 입력 이미지를 통해 라벨은 예측한다.
	predicted_label = model->predict(test_image);
	predicted_image = images[predicted_label * 9 - 9];

	// 인식 결과를 보여준다.
	imshow("Test face", test_image);
	imshow("Predicted face", predicted_image);

	waitKey();

	return 0;
}