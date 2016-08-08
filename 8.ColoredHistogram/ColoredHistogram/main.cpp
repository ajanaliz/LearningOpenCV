#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//calculating a color image histogram
	Mat img = imread("res/f1.jpg");

	if (img.empty())
	{
		cout << "Could not load image!" << endl;
		return -1;
	}
	imshow("Image", img);

	//calculating image histogram
	int narrays = 1;
	int chanels[] = { 0, 1, 2 };
	Mat hist;
	int dims = 3;
	int histSize[] = { 10, 10, 10 };
	float hranges[] = { 0, 255 };
	const float* ranges[] = { hranges, hranges, hranges };

	calcHist(&img, narrays, chanels, Mat(), hist, dims, histSize, ranges);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				cout << "value " << i << "," << j << "," << k << "=" << hist.at<float>(i, j, k) << "\n";

	waitKey(0);
	return 0;
}
