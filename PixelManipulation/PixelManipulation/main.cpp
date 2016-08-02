#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace cv;

void salt(Mat &image, int n)
{
	int i, j;
	for (int k = 0; k < n; k++)
	{
		i = rand() % image.cols;
		j = rand() % image.rows;
		if (image.channels() == 1)
		{
			image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3)
		{
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}


//int main()
//{
//	Mat image = imread("res/OSPF 50 server Topology.jpg", CV_LOAD_IMAGE_COLOR);
//	if (image.empty())
//		std::cout << "could not load image!" << std::endl;
//	namedWindow("myimage");
//	imshow("myimage", image);
//	salt(image, 3000);
//	namedWindow("salted image");
//	imshow("salted image", image);
//	waitKey(0);
//	return 0;
//}