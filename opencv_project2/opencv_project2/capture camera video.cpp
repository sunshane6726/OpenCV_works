#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;
int cature_camera_video()
{
	// VideoCapture v("C:\works\OpenCV_works\images\images")
	VideoCapture v(0);
	assert(v.isOpened());
	namedWindow("video play");
	printf("captured video is playing \n");
		while (true)
		{
			Mat frame;
			v.read(frame);
			imshow("video play", frame);
			char c = waitKey(30);
			if (c == 27) break; // [ESC] key value is 27
		}
		return 0;
}