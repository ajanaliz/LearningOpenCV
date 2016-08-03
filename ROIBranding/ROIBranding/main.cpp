#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
	// read images
	cv::Mat image = cv::imread("res/dog.jpg");
	cv::Mat logo = cv::imread("res/logo.png");

	// define image ROI
	cv::Mat imageROI;
	imageROI = image(cv::Rect(385, 270, logo.cols, logo.rows));

	// add logo to image 
	cv::addWeighted(imageROI, 0.3, logo, 1, 0., imageROI);

	// show result
	cv::namedWindow("with logo");
	cv::imshow("with logo", image);


	cv::waitKey();

	return 0;
}
