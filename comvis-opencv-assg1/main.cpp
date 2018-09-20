#include "opencv2/opencv.hpp"

int main(int, char **)
{
	cv::VideoCapture cap(0); // open the default camera
	
	if (!cap.isOpened()) {
		return -1; // check if we succeeded
	} 

	cv::Mat edges;
	int R, G, B;
	cv::namedWindow("Color", cv::WINDOW_AUTOSIZE);
	for (;;)
	{
		cv::Mat frame;
		cap >> frame; // get a new frame from camera
		double centerFrameX = (frame.cols / 2);
		double centerFrameY = (frame.rows / 2);
		R = frame.at<cv::Vec3b>(centerFrameX, centerFrameY)[2];
		G = frame.at<cv::Vec3b>(centerFrameX, centerFrameY)[1];
		B = frame.at<cv::Vec3b>(centerFrameX, centerFrameY)[0];

		// std::cout << "frame.cols=" << frame.cols << " " << "centerFrameX=" << centerFrameX << std::endl << std::endl;
		// std::cout << "frame.rows=" << frame.rows << " " << "centerFrameY=" << centerFrameY << std::endl;
		std::cout << "R=" << R << " " << "G=" << G << " " << "B=" << " " << B << std::endl;

		cv::rectangle(frame, cv::Rect(centerFrameX - 100, centerFrameY - 100, 200, 200), CV_RGB(R, G, B), 2);
		cv::imshow("Color", frame);
		if (cv::waitKey(30) >= 0)
			break;
	}

	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}