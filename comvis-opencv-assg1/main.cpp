#include "opencv2/opencv.hpp"

int main(int, char **)
{
	cv::VideoCapture cap(0); // open the default camera
	
	if (!cap.isOpened()) {
		return -1; // check if we succeeded
	} 

	cv::Mat edges;
	cv::namedWindow("edges", 1);
	for (;;)
	{
		cv::Mat frame;
		cap >> frame; // get a new frame from camera
		cv::imshow("edges", frame);
		if (cv::waitKey(30) >= 0)
			break;
	}

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}