#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

string face_cascade ="c:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
string eye_cascade = "c:/opencv/sources/data/haarcascadees/haarcascade_eye.xml";
CascadeClassifier face;
CascadeClassifier eye;
void faceAndEyeDetect(Mat);

int face_dection()
{
	Mat f = imread("c:/works/images/images/aia-tottenham-2019-011.jpg"); // 토트넘 축구단 사진들
	assert(f.data);
	bool b1 = face.load(face_cascade);
	bool b2 = eye.load(eye_cascade);
	assert(b1);
	faceAndEyeDetect(f);
	waitKey();
	return 0;
}

void faceAndEyeDetect(Mat img)
{
	Mat gray;
	cvtColor(img, gray, CV_BGR2GRAY);
	vector<Rect> face_pos;
	face.detectMultiScale(gray, face_pos, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(10, 10));
	for (int i = 0; i < face_pos.size(); i++)
		rectangle(img, face_pos[i], Scalar(255, 0, 0), 2);
	namedWindow("face detection");
	imshow("face detection", img);
}