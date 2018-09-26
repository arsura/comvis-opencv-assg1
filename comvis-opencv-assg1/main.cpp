#include "HSV.hpp"

void foo(cv::Mat &frame, 
		 cv::Mat &frame_HSV, 
		 cv::Mat &frame_threshold, 
		 std::string colorName,
		 cv::Scalar lowHSV,
		 cv::Scalar highHSV,
		 cv::Scalar BGR)
{
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
	int nonZero;

	cv::inRange(frame_HSV, lowHSV, highHSV, frame_threshold);
	cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_OPEN, kernel);
	cv::morphologyEx(frame_threshold, frame_threshold, cv::MORPH_CLOSE, kernel);

	nonZero = cv::countNonZero(frame_threshold);
	// std::cout << nonZero << std::endl;
	if (nonZero > 10000) {
		cv::Moments m = cv::moments(frame_threshold, false);
		cv::Point p(m.m10 / m.m00, m.m01 / m.m00);
		cv::putText(frame, colorName, p, 1, 2.0, BGR, 2);
		cv::imshow(colorName, frame_threshold);
	}
	else {
		cv::destroyWindow(colorName);
	}
}


int main(int argc, char* argv[])
{
	cv::VideoCapture cap(argc > 1 ? atoi(argv[1]) : 0);

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);

	for (auto& m : HSV) {
		std::cout << m.first << " lowHSV=" << m.second[0] << " highHSV=" << m.second[1] << " BGR=" << m.second[2] << std::endl;
		cv::namedWindow(m.first, cv::WINDOW_AUTOSIZE);
	}
	
	cv::Mat frame, frame_HSV, frame_threshold;

	while (true) {

		cap >> frame;
		if (frame.empty()) {
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