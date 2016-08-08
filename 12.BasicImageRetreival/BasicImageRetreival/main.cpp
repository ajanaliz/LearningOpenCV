#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cstdlib>


using namespace std;
using namespace cv;

void colorReduce(cv::Mat &image, int div = 64) {

	int nl = image.rows; // number of lines
	int nc = image.cols * image.channels(); // total number of elements per line

	for (int j = 0; j < nl; j++) {

		uchar* data = image.ptr<uchar>(j);

		for (int i = 0; i < nc; i++) {

			// process each pixel ---------------------

			data[i] = data[i] / div*div + div / 2;

			// end of pixel processing ----------------

		} // end of line                   
	}
}


int main()
{
	// Read input image
	Mat probIm = imread("res/f1.jpg", 1);
	if (!probIm.data)
		return 0;

	//colorReduce(probIm);
	//calculating prob image histogram
	int narrays = 1;
	int chanels[] = { 0, 1, 2 };
	Mat hist1, hist2;
	int dims = 3;
	int histSize[] = { 30, 30, 30 };
	float hranges[] = { 0, 255 };
	const float* ranges[] = { hranges, hranges, hranges };

	calcHist(&probIm, narrays, chanels, Mat(), hist1, dims, histSize, ranges);

	for (int i = 1; i <= 10; i++){


		char add[] = "res/retrieval dataset/";
		char buf[10];

		strcat(add, _itoa(i, buf, 10));
		Mat gallaryIm = imread(strcat(add, ".jpg"), 1);
		if (!gallaryIm.data)
			return 0;
		//colorReduce(gallaryIm);

		calcHist(&gallaryIm, narrays, chanels, Mat(), hist2, dims, histSize, ranges);
		//cout << compareHist(hist1, hist2, CV_COMP_INTERSECT) << endl;
		cout << compareHist(hist1, hist2, CV_COMP_BHATTACHARYYA) << endl;
	}
	namedWindow("result");
	imshow("result", probIm);

	waitKey();
	return 0;
}