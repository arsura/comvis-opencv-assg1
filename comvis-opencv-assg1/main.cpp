#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <map>

std::map< std::string, std::vector<cv::Scalar> > HSV {
	// lowHSV, highHSV, RGB
	{
		"Blue", { cv::Scalar(90, 80, 90), cv::Scalar(110, 240, 255), cv::Scalar(255, 0, 0) }
	},
	{
		"Yellow", { cv::Scalar(20, 130, 130), cv::Scalar(50, 255, 255), cv::Scalar(0, 255, 255) }
	},
	{
		"Orange", { cv::Scalar(5, 130, 180), cv::Scalar(15, 255, 255), cv::Scalar(0, 165, 255) }
	}
};

void foo(cv::Mat frame, 
		 cv::Mat frame_HSV, 
		 cv::Mat frame_threshold, 
		 std::string colorName,
		 cv::Scalar lowHSV,
		 cv::Scalar highHSV,
		 cv::Scalar BGR)
{
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(4, 4));
	int nonZero;

	cv::inRange(frame_HSV, lowHSV, highHSV, frame_threshold);
	cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_OPEN, kernel);
	cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_CLOSE, kernel);

	nonZero = cv::countNonZero(frame_threshold);
	// std::cout << nonZero << std::endl;
	if (nonZero > 1000) {
		cv::Moments m = cv::moments(frame_threshold, false);
		cv::Point p(m.m10 / m.m00, m.m01 / m.m00);
		cv::putText(frame, colorName, p, 1, 2.0, BGR, 2);
	}
}


int main(int argc, char* argv[])
{
	cv::VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	// cv::namedWindow("BlueHSV", cv::WINDOW_AUTOSIZE);

	for (auto& m : HSV) {
		std::cout << m.first << " lowHSV=" << m.second[0] << " highHSV=" << m.second[1] << " BGR=" << m.second[2] << std::endl;
	}
	
	cv::Mat frame, frame_HSV, frame_threshold;

	while (true) {

		cap >> frame;
		if (frame.empty()){
			break;
		}
		// Convert from BGR to HSV colorspace
		cv::cvtColor(frame, frame_HSV, cv::COLOR_BGR2HSV);
		
		for (auto& m : HSV) {
			foo(frame, frame_HSV, frame_threshold, m.first, m.second[0], m.second[1], m.second[2]);
		}

		// Show the frames
		cv::imshow("Original", frame);

		char key = (char)cv::waitKey(30);
		if (key == 'q' || key == 27) {
			break;
		}
	}
	return 0;
}