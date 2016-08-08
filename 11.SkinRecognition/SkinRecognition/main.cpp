#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/tracking.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int main()
{
	// Read input image
	Mat image = imread("res/f1.jpg", 1);
	if (!image.data)
		return 0;

	// define image ROI
	Mat imageROI;
	imageROI = image(Rect(40, 40, 30, 15)); // face region

	// Display reference patch
	namedWindow("image");
	imshow("image", image);

	namedWindow("Reference");
	imshow("Reference", imageROI);


	//calculating image histogram
	int narrays = 1;
	int chanels[] = { 0, 1, 2 };
	Mat hist;
	int dims = 3;
	int histSize[] = { 30, 30, 30 };
	float hranges[] = { 0, 255 };
	const float* ranges[] = { hranges, hranges, hranges };

	calcHist(&imageROI, narrays, chanels, Mat(), hist, dims, histSize, ranges);

	normalize(hist, hist, 1);

	Mat result;
	calcBackProject(&image, 1, chanels, hist, result, ranges, 255);

	threshold(result, result, 2, 255, THRESH_BINARY);
	namedWindow("result");
	imshow("result", result);


	// mean shift
	Rect rect(0, 0, 100, 200);
	TermCriteria criteria(TermCriteria::MAX_ITER, 20, 0.01);
	cout << meanShift(result, rect, criteria);
	rectangle(image, rect, Scalar(0, 255, 0));

	//camShift
	RotatedRect Box = CamShift(result, rect, criteria);
	ellipse(image, Box, Scalar(0, 0, 255), 3, LINE_AA);

	namedWindow("mean & cam shift result");
	imshow("mean & cam shift result", image);

	waitKey();
}