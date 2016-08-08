#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void histShow(Mat hist, String name)
{

	// showing histogram in an image
	double maxVal = 0;
	double minVal = 0;
	minMaxLoc(hist, &minVal, &maxVal, 0, 0);


	int histSize[] = { 256 };
	int hpt = static_cast<int>(0.9*histSize[0]);
	Mat histImg(histSize[0], histSize[0], CV_8U, Scalar(255));

	for (int h = 0; h < histSize[0]; h++)
	{
		float binVal = (hist.at<float>(h)*hpt) / maxVal;
		line(histImg, Point(h, histSize[0]), Point(h, histSize[0] - binVal), Scalar::all(0));

	}
	namedWindow(name);
	imshow(name, histImg);

}
Mat stretch(Mat &hist) {

	int histSize[] = { 256 };

	// find left extremity of the histogram
	int imin = 0;
	for (; imin < histSize[0]; imin++) {
		if (hist.at<float>(imin) > 0)
			break;
	}

	// find right extremity of the histogram
	int imax = histSize[0] - 1;
	for (; imax >= 0; imax--) {

		if (hist.at<float>(imax) > 0)
			break;
	}

	// Create lookup table
	int dims[1] = { 256 };
	MatND lookup(1, dims, CV_8U);

	for (int i = 0; i < 256; i++) {

		if (i < imin) lookup.at<uchar>(i) = 0;
		else if (i > imax) lookup.at<uchar>(i) = 255;
		else lookup.at<uchar>(i) = static_cast<uchar>(255.0*(i - imin) / (imax - imin) + 0.5);
	}
	return lookup;
}


int main()
{
	//reading and showing an image
	Mat im = imread("res/test3.jpg", 0);

	if (im.empty())
	{
		cout << "Cannot load image!" << endl;
		return -1;
	}
	imshow("Image", im);
	waitKey(10);



	//calculating image histogram
	int narrays = 1;
	int channels[] = { 0 };
	Mat hist;
	int dims = 1;
	int histSize[] = { 256 };
	float hranges[] = { 0.0, 255.0 };
	const float *ranges[] = { hranges };

	calcHist(&im, narrays, channels, Mat(), hist, dims, histSize, ranges);
	string name = "image hist";
	histShow(hist, name);




	// Apply lookup table
	Mat lookup = stretch(hist);
	Mat Result;
	LUT(im, lookup, Result);

	namedWindow("Result");
	imshow("Result", Result);

	Mat Resulthist;
	calcHist(&Result, narrays, channels, Mat(), Resulthist, dims, histSize, ranges);

	name = "result hist";
	histShow(Resulthist, name);

	
	waitKey(0);
}
