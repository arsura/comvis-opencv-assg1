#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Load BGR image
    Mat3b bgr = imread("resource/img/gray_shade.png");
	Mat3b rgb;

    if (bgr.empty()) 
    {
        cout << "Cannot open the image" << endl;
        return -1;
    }

    // Transform to HSV
    Mat3b hsv;
    cvtColor(bgr, hsv, COLOR_BGR2HSV); 

    // Create a window called "Control"
    namedWindow("Control", cv::WINDOW_AUTOSIZE); 

    // Set starting values for ranges
    int iLowH = 0;
    int iHighH = 10;

    int iLowS = 145;
    int iHighS = 255;

    int iLowV = 100;
    int iHighV = 255;

    //Create trackbars in "Control" window
    createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);

    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);

    createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);

    //Show the original image
    imshow("Original", bgr); 
	

    // Create kernel for morphological operation
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));

    // Infinte loop, until user press "esc"
    while (true)
    {
        Mat mask;

        inRange(hsv, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), mask); //Threshold the image

        //morphological opening (remove small objects from the foreground)
        morphologyEx(mask, mask, MORPH_OPEN, kernel);

        //morphological closing (fill small holes in the foreground)
        morphologyEx(mask, mask, MORPH_CLOSE, kernel);

        //Show the thresholded image
        imshow("Thresholded Image", mask); 

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    return 0;
}

// White
//	- lowHSV	(0, 0, 80)
//	- highHSV	(180, 90, 255)

// Black
//	- lowHSV	(0, 0, 0)
//	- highHSV	(180, 255, 80)

// Gray
//	- lowHSV	(0, 0, 50)
//	- highHSV	(180, 255, 255)

// Yellow
//	- lowHSV	(20, 130, 130)
//	- highHSV	(50, 255, 255)

// Red
//	- lowHSV	(0, 130, 70)
//	- highHSV	(9, 255, 130)

// Blue
//	- lowHSV	(90, 80, 90)
//	- highHSV	(110, 240, 255)

// Green
//	- lowHSV	(50, 70, 30)
//	- highHSV	(90, 255, 255)

// Brown
//	- lowHSV	(0, 50, 60)
//	- highHSV	(180, 170, 160)

// Pink
//	- lowHSV	(130, 70, 180)
//	- highHSV	(170, 225, 255)

// Orange
//	- lowHSV	(5, 130, 180)
//	- highHSV	(15, 255, 255)

// Purple
//	- lowHSV	(90, 90, 90)
//	- highHSV	(150, 255, 255)
