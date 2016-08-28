
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main()
{

	Mat image = imread("res/test.jpg");
	imshow("originalimage", image);

	Mat binary;
	cvtColor(image, binary, CV_BGR2GRAY);
	threshold(binary, binary, 100, 255, THRESH_BINARY);
	imshow("originalbinary", binary);

	//eliminate noise and smaller objects
	Mat fg;
	erode(binary, fg, Mat(), Point(-1, -1), 2);
	imshow("fg", fg);

	//Identify background pixels
	Mat bg;
	dilate(binary, bg, Mat(), Point(-1, -1), 3);
	threshold(bg, bg, 1, 128, THRESH_BINARY_INV);
	imshow("bg", bg);

	Mat markers(binary.size(), CV_8U, Scalar(0));
	markers = fg + bg;

	markers.convertTo(markers, CV_32S);
	watershed(image, markers);
	markers.convertTo(markers, CV_8U);
	imshow("markers", markers);



	waitKey(0);
}