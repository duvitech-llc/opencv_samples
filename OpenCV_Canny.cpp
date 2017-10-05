#include "opencv2/opencv.hpp"
using namespace cv;
Mat frame;

int main(int, char**)
{
	VideoCapture cap(-1); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	cap.set(CV_CAP_PROP_FRAME_WIDTH,1920);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
	Mat edges;
	namedWindow("edges",CV_WINDOW_AUTOSIZE);
	for(;;)
	{
		cap >> frame; // get a new frame from camera
		if (frame.empty())
			break;
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if((char)waitKey(10) == 27) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

