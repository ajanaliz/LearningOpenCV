#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat image = imread("res/car.jpg");
	imshow("originalimage", image);

	Rect rectangle2(5, 90, 280, 80);
	Mat result;
	Mat bkgModel, fgrModel;

	grabCut(image, result, rectangle2, bkgModel, fgrModel, 5, GC_INIT_WITH_RECT);
	compare(result, GC_PR_FGD, result, CMP_EQ);
	Mat foreground(image.size(), CV_8UC3, Scalar(255, 255, 255));
	image.copyTo(foreground, result);

	rectangle(image, rectangle2, Scalar(255, 255, 255));
	imshow("image2", image);
	imshow("foreground", foreground);


	waitKey(0);
}