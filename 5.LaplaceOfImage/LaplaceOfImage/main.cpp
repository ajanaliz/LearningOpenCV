
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main()
{
	// Read input image
	Mat image = imread("res/dog.jpg", 0);
	if (!image.data)
		return 0;

	// Display the image
	namedWindow("Original Image");
	imshow("Original Image", image);

	Mat laplace;
	Laplacian(image, laplace, CV_8U, 3, 1, 128);
	// threshold(laplace, laplace, 100, 255,THRESH_BINARY);
	namedWindow("laplace Image");
	imshow("laplace Image", laplace);


	waitKey();
	return 0;
}
