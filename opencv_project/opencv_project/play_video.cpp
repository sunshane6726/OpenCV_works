#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
using namespace std;
using namespace cv;

int play_video()
{
	VideoCapture v(0);
	assert(v.isOpened());
	namedWindow("video play");
	Mat frame;
	printf("video is played \n");
	while (true)
	{
		v.read(frame);
		if (frame.empty()) { break; }
		imshow("video play", frame);
		char c = waitKey(30);
		if (c == 27) break; // [ESC] key value is 27
	}
}