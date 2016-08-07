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
	Laplacian(image, laplace, CV_8U, 3, 1, 0);
	// threshold(laplace, laplace, 100, 255,THRESH_BINARY);
	namedWindow("laplace Image");
	imshow("laplace Image", laplace);


	// Compute Sobel X derivative
	Mat sobelX;
	Sobel(image, sobelX, CV_8U, 1, 0, 3, 0.4, 0);

	// Display the image
	namedWindow("Sobel X Image");
	imshow("Sobel X Image", sobelX);

	// Compute Sobel Y derivative
	Mat sobelY;
	Sobel(image, sobelY, CV_8U, 0, 1, 3, 0.4, 0);

	// Display the image
	namedWindow("Sobel Y Image");
	imshow("Sobel Y Image", sobelY);

	// Compute norm of Sobel
	Mat sobel;
	//compute the L1 norm
	sobel = abs(sobelX) + abs(sobelY);

	// Display the image
	namedWindow("Sobel Image");
	imshow("Sobel Image", sobel);

	Mat scharrX;
	Scharr(image, scharrX, CV_16S, 1, 0, 3);

	namedWindow("scharr x Image");
	imshow("scharr x Image", scharrX);
	 

	Mat scharrY;
	Scharr(image, scharrY, CV_16S, 0, 1, 3);

	namedWindow("scharr y Image");
	imshow("scharr y Image", scharrY);

	Mat scharr;
	//compute the L1 norm
	scharr = abs(scharrX) + abs(scharrY);

	// Display the image
	namedWindow("Scharr Image");
	imshow("Scharr Image", scharr);

	waitKey();
	return 0;
}
