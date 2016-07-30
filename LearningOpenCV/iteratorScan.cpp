#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	//reading and showing an image
	Mat im = imread("res/OSPF 50 server Topology.jpg");

	namedWindow("image");
	imshow("image", im);



	Mat_<Vec3b>::iterator it = im.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = im.end<Vec3b>();

	while (it != itend){
		// process each pixel ---------------------

		(*it)[0] = ((*it)[0] + 100) % 255;
		(*it)[1] = ((*it)[1] + 100) % 255;
		(*it)[2] = ((*it)[2] + 100) % 255;
		++it;
		// end of pixel processing ----------------

	} // end of line                   

	namedWindow("result");
	imshow("result", im);
	waitKey(0);

}
