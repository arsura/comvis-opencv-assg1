#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <map>
#include <vector>

std::map< std::string, std::vector<cv::Scalar> > HSV{
	// lowHSV, highHSV, RGB
	{
		"Red", { cv::Scalar(125, 105, 110), cv::Scalar(180, 255, 255), cv::Scalar(0, 0, 255) }
	},
	{
		"Brown", { cv::Scalar(0, 45, 0), cv::Scalar(15, 255, 125), cv::Scalar(19, 69, 139) }
	},
	{
		"Orange", { cv::Scalar(0, 125, 205), cv::Scalar(15, 255, 255), cv::Scalar(0, 165, 255) }
	},
	{
		"Yellow", { cv::Scalar(20, 130, 130), cv::Scalar(50, 255, 255), cv::Scalar(0, 255, 255) }
	},
	{
		"Green", { cv::Scalar(50, 190, 40), cv::Scalar(90, 255, 255), cv::Scalar(0, 255, 0) }
	},
	{
		"Blue", { cv::Scalar(90, 80, 90), cv::Scalar(120, 255, 255), cv::Scalar(255, 0, 0) }
	},
	{
		"Purple", { cv::Scalar(120, 5, 0), cv::Scalar(130, 255, 255), cv::Scalar(204, 50, 153) }
	},
	{
		"Pink", { cv::Scalar(160, 65, 120), cv::Scalar(172, 255, 255), cv::Scalar(180, 105, 255) }
	},
	{
		"Grey", { cv::Scalar(0, 0, 50), cv::Scalar(180, 50, 100), cv::Scalar(128, 128, 128) }
	},
	{
		"Black", { cv::Scalar(0, 0, 0), cv::Scalar(180, 255, 40), cv::Scalar(0, 0, 0) }
	},
	{
		"White", { cv::Scalar(0, 0, 200), cv::Scalar(180, 40, 255), cv::Scalar(255, 255, 255) }
	},
};