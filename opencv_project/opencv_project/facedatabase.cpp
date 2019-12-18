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

	//�����ͺ��̽��� �̹��� �� �����ϱ�
	for (people_cnt = 1; people_cnt <= 10; people_cnt++)
	{
		for (face_cnt = 1; face_cnt <= 9; face_cnt++)
		{
			sprintf(file_path, "C://works/OpenCV_works/att_faces/s%d/%d.pgm", people_cnt, face_cnt);
			images.push_back(imread(file_path, CV_LOAD_IMAGE_GRAYSCALE));
			labels.push_back(people_cnt);

		}
	}
	// ���� �׽�Ʈ ���� �� �̹��� �ε��ϱ�

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


	//�� �����ͺ��̽��� ���� �׽�Ʈ�� ���� �̹��� �� �ε��ϱ�
	read_images(images, labels, test_image, 1);


	// ���ο� �����ν��ڸ� â���Ѵ�.
	model = createEigenFaceRecognizer();

	//�־��� �����Ϳ� ������ ���� �Բ��� ü�� �� �ν��ڸ� �Ʒý�Ų��.
	model->train(images, labels);

	// �־��� �Է� �̹����� ���� ���� �����Ѵ�.
	predicted_label = model->predict(test_image);
	predicted_image = images[predicted_label * 9 - 9];

	// �ν� ����� �����ش�.
	imshow("Test face", test_image);
	imshow("Predicted face", predicted_image);

	waitKey();

	return 0;
}