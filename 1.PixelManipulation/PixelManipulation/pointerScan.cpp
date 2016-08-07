#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;

//int main()
//{
//	//reading and showing an image
//	Mat im(256, 256, CV_8UC3);
//	int nl = im.rows;// number of lines
//	int nc = im.cols * im.channels(); // total number of elements per line
//
//	for (int j = 0; j < nl; j++)
//	{
//		uchar* tempLinePtr = im.ptr<uchar>(j);
//		for (int i = 0; i < nc; i+=3)
//		{
//			//process each pixel
//			if (i < 80 && j < 80)
//			{
//				*(tempLinePtr++) = 0;
//				*(tempLinePtr++) = 0;
//				*(tempLinePtr++) = 255;
//			}
//			else if (i < 160 && j < 160)
//			{
//				*(tempLinePtr++) = 0;
//				*(tempLinePtr++) = 255;
//				*(tempLinePtr++) = 0;
//			}
//			else
//			{
//				*(tempLinePtr++) = 255;
//				*(tempLinePtr++) = 0;
//				*(tempLinePtr++) = 0;
//			}
//		}
//	}
//	namedWindow("image");
//	imshow("image", im);
//	waitKey(0);
//	return 0;
//}