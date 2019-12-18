#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>


using namespace cv;
using namespace std;

static void line_detect(Mat image) {

	Mat filtered_image;
	vector<Vec4i> lines;

	// Detect lines

	cvtColor(image, filtered_image, CV_BGR2GRAY);
	GaussianBlur(filtered_image, filtered_image, Size(4, 4), 1.5, 1.5);
	Sobel(filtered_image, filtered_image, filtered_image.type(), 1, 1, 3);
	Laplacian(filtered_image, filtered_image, filtered_image.type(), 3);
	threshold(filtered_image, filtered_image, 130, 255, CV_THRESH_OTSU);
	HoughLinesP(filtered_image, lines, 1, CV_PI / 180, 100, 50, 5);


	// 검출된 라인 그리기
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(image, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, CV_AA);

	}
}

int main() {
	VideoCapture video;
	Mat image;
	Mat roi_left_image;
	Mat roi_right_image;

	// video 파일 열기
	
	video.open("C://works/images/images/challenge.mp4");
	//video.open("C://works/images/images/challenge.mp4");

	//프레임을 읽기
	while (.read(image))
	{
		// left ROI 안에서 라인탐지
		roi_left_image = image(Rect(image.cols / 4, image.cols / 3, image.cols / 4, image.cols / 4));
		line_detect(roi_left_image);

		// right ROI안에서 라인탐지
		roi_right_image = image(Rect(image.cols / 2, image.cols / 3, image.cols / 4, image.cols/4));
		line_detect(roi_left_image);

		//Show line detect result
		imshow("Line detected image", image);
		// Wait 10ms
		waitKey(10);
	}
	return 0;
}
