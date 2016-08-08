#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// Read input image
	Mat im = imread("res/test.png", 1);
	if (!im.data)
		return 0;
	im = ~im;
	namedWindow("image");
	imshow("image", im);
	// Diamond shaped 5x5
	Mat se(5, 5, CV_8U, Scalar(0));
	se.at<uchar>(2, 0) = 1;
	se.at<uchar>(2, 1) = 1;
	se.at<uchar>(2, 2) = 1;
	se.at<uchar>(2, 3) = 1;
	se.at<uchar>(2, 4) = 1;
	se.at<uchar>(0, 2) = 1;
	se.at<uchar>(1, 2) = 1;
	se.at<uchar>(3, 2) = 1;
	se.at<uchar>(4, 2) = 1;


	Mat result;
	erode(im, result, se, Point(-1, -1), 1);
	//dilate(im, result, Mat());



	namedWindow("result");
	imshow("result", result);


	waitKey();
}