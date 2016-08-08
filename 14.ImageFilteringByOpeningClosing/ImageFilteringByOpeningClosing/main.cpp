#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// noise removal
	//Mat im = imread("test.png", 1);
	//if (!im.data)
	//	return 0;
	//namedWindow("image");
	//imshow("image", im);

	//Mat result;
	//
	////opening & closing
	//morphologyEx(im, result, MORPH_OPEN,Mat(),Point(-1,-1),3);
	//morphologyEx(result, result, MORPH_CLOSE, Mat(), Point(-1, -1), 3);


	//namedWindow("result");
	//imshow("result", result);

	/*
	//finding circles in an image
	Mat im = imread("res/dog.jpg", 1);
	if (!im.data)
	return 0;
	namedWindow("image");
	imshow("image", im);

	Mat result;
	Mat se(10, 10, CV_8U, Scalar(1));
	se.at<uchar>(0, 0) = 0;
	se.at<uchar>(0, 9) = 0;
	se.at<uchar>(9, 0) = 0;
	se.at<uchar>(9, 9) = 0;

	morphologyEx(im, result, MORPH_OPEN, se, Point(-1, -1));
	namedWindow("result");
	imshow("result", result);
	*/
	
	//edge detection
	Mat im = imread("res/dog.jpg");
	if (!im.data)
		return 0;
	namedWindow("image");
	imshow("image", im);

	Mat result;
	morphologyEx(im, result, MORPH_GRADIENT, Mat());
	namedWindow("result");
	imshow("result", result);

	
	waitKey();
	return 0;
}