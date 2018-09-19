#include "opencv2/opencv.hpp"

int main(int, char **)
{
	cv::VideoCapture cap(0); // open the default camera
	
	if (!cap.isOpened()) {
		return -1; // check if we succeeded
	} 

	cv::Mat edges;
	cv::namedWindow("Color", 1);
	for (;;)
	{
		cv::Mat frame;
		cap >> frame; // get a new frame from camera
		double centerFrameY = (frame.rows / 2) - 100;
		double centerFrameX = (frame.cols / 2) - 100;
		int R = frame.at<cv::Vec3b>(frame.cols / 2, frame.rows / 2)[2];
		int G = frame.at<cv::Vec3b>(frame.cols / 2, frame.rows / 2)[1];
		int B = frame.at<cv::Vec3b>(frame.cols / 2, frame.rows / 2)[0];

		// std::cout << "frame.cols=" << frame.cols << " " << "centerFrameX=" << centerFrameX << std::endl << std::endl;
		// std::cout << "frame.rows=" << frame.rows << " " << "centerFrameY=" << centerFrameY << std::endl;
		std::cout << "R=" << R << " " << "G=" << G << " " << "B=" << " " << B << std::endl;

		cv::rectangle(frame, cv::Rect(centerFrameX, centerFrameY, 200, 200), CV_RGB(255, 0, 0), 2);
		cv::imshow("Color", frame);
		if (cv::waitKey(30) >= 0)
			break;
	}

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}