#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace cv;

void sharpen(const Mat& image, Mat &result)
{
	for (int j = 1; j < image.rows - 1; j++)//for all rows except the first and last row
	{
		const uchar* previous = image.ptr<const uchar>(j - 1);
		const uchar* current = image.ptr<const uchar>(j);
		const uchar* next = image.ptr<const uchar>(j + 1);

		uchar* output = result.ptr<uchar>(j);
		for (int i = 1; i < image.cols - 1; i++) // for all cols except first and last col
		{
			*output++ = cv::saturate_cast<uchar>(4 * current[i] - current[i - 1] - current[i + 1] - previous[i] - next[i]);//the cast is so our pixel value stays between 0 and 255
			//*output++ = cv::saturate_cast<uchar>(5 * current[i] - current[i - 1] - current[i + 1] - previous[i] - next[i]);
		}
	}
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows - 1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols - 1).setTo(cv::Scalar(0));
}

int main()
{
	Mat image = imread("res/dog.jpg", 0);
	if (!image.data)
	{
		return 0;
	}

	Mat result;
	result.create(image.size(), image.type());

	sharpen(image, result);

	namedWindow("Image");
	imshow("Image", result);

	waitKey();
	return 0;
}