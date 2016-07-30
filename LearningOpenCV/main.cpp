#include <opencv2\highgui\highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	Mat image = imread("res/OSPF 50 server Topology.jpg", 0);
	if (image.empty())
		std::cout << "could not load image!" << std::endl;
	
	imshow("myimage", image);
	waitKey(0);
	return 0;
}