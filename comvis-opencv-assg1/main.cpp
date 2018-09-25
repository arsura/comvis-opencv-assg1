#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	cv::VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("HSV", cv::WINDOW_AUTOSIZE);
	
	cv::Mat frame, frame_HSV, frame_threshold;
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
	int nonZero;

	while (true) {

		cap >> frame;
		if (frame.empty()){
			break;
		}
		// Convert from BGR to HSV colorspace
		cv::cvtColor(frame, frame_HSV, cv::COLOR_BGR2HSV);
		
		cv::Point center(frame_threshold.cols / 2, frame_threshold.rows / 2);

		
		cv::inRange(frame_HSV, cv::Scalar(90, 80, 90), cv::Scalar(110, 240, 255), frame_threshold);
		cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_OPEN, kernel);
		cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_CLOSE, kernel);

		nonZero = cv::countNonZero(frame_threshold);
		std::cout << nonZero << std::endl;
		if (nonZero > 1000) {
			cv::putText(frame, "Blue", center, 1, 2.0, cv::Scalar(255, 0, 0), 1);
		}


		cv::inRange(frame_HSV, cv::Scalar(20, 130, 130), cv::Scalar(50, 255, 255), frame_threshold);
		cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_OPEN, kernel);
		cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_CLOSE, kernel);

		nonZero = cv::countNonZero(frame_threshold);
		std::cout << nonZero << std::endl;
		if (nonZero > 1000) {
			cv::putText(frame, "Yellow", center, 1, 2.0, cv::Scalar(0,255,255), 1);
		}



		// Show the frames
		cv::imshow("Original", frame);
		cv::imshow("HSV", frame_threshold);

		char key = (char)cv::waitKey(30);
		if (key == 'q' || key == 27)
		{
			break;
		}
	}
	return 0;
}