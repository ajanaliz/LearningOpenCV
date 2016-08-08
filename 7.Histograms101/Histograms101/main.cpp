#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//reading and showing an image
	Mat im = imread("res/dog.jpg", 0);

	if (im.empty())
	{
		cout << "Cannot load image!" << endl;
		return -1;
	}
	imshow("Image", im);
	waitKey(10);



	//calculating image histogram
	int numberOfImages = 1;
	int channels[] = { 0 };
	Mat hist;
	int dims = 1;
	int histSize[] = { 256 };
	float hranges[] = { 0.0, 255.0 };
	const float *ranges[] = { hranges };

	calcHist(&im, numberOfImages, channels, Mat(), hist, dims, histSize, ranges);
	float sum = 0;
	for (int i = 0; i < 256; i++)
	{
		cout << "value " << i << " = " << hist.at<float>(i) << endl;
		sum = sum + hist.at<float>(i);
	}


	int reall = (int)im.cols*(int)im.rows;


	// showing histogram in an image
	double maxVal = 0;
	double minVal = 0;
	minMaxLoc(hist, &minVal, &maxVal, 0, 0);
	int highestPoint = static_cast<int>(0.9*histSize[0]);
	cout << "Max value " << maxVal << endl;
	Mat histImg(histSize[0], histSize[0], CV_8U, Scalar(255));
	for (int h = 0; h < histSize[0]; h++)
	{
		float binVal = (hist.at<float>(h)*highestPoint) / maxVal;
		line(histImg, Point(h, histSize[0]), Point(h, histSize[0] - binVal), Scalar::all(0));

	}
	namedWindow("histogram");
	imshow("histogram", histImg);
	waitKey(0);
	return 0;
}
