#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <map>
#include <vector>

std::map< std::string, std::vector<cv::Scalar> > HSV{
	// lowHSV, highHSV, RGB
	{
		"Red", { cv::Scalar(0, 120, 140), cv::Scalar(10, 255, 255), cv::Scalar(0, 0, 0) }
	},
	{
		"Brown", { cv::Scalar(0, 50, 60), cv::Scalar(180, 170, 160), cv::Scalar(19, 69, 139) }
	},
	{
		"Orange", { cv::Scalar(5, 130, 180), cv::Scalar(15, 255, 255), cv::Scalar(0, 165, 255) }
	},
	{
		"Yellow", { cv::Scalar(20, 130, 130), cv::Scalar(50, 255, 255), cv::Scalar(0, 255, 255) }
	},
	{
		"Green", { cv::Scalar(50, 70, 30), cv::Scalar(90, 255, 255), cv::Scalar(0, 255, 0) }
	},
	{
		"Blue", { cv::Scalar(90, 80, 90), cv::Scalar(120, 240, 255), cv::Scalar(255, 0, 0) }
	},
	{
		"Purple", { cv::Scalar(130, 90, 90), cv::Scalar(140, 255, 255), cv::Scalar(204, 50, 153) }
	},
	{
		"Pink", { cv::Scalar(150, 110, 120), cv::Scalar(180, 255, 255), cv::Scalar(180, 105, 255) }
	},
	//{
	//	"Grey", { cv::Scalar(0, 0, 50), cv::Scalar(180, 255, 255), cv::Scalar(128, 128, 128) }
	//},
	//{
	//	"Black", { cv::Scalar(0, 0, 0), cv::Scalar(180, 255, 80), cv::Scalar(255, 255, 255) }
	//},
	//{
	//	"White", { cv::Scalar(0, 0, 80), cv::Scalar(180, 90, 255), cv::Scalar(0, 0, 0) }
	//},
};