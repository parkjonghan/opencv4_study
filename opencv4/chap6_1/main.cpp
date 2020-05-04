
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{

	Mat src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	if (src1.empty() || src2.empty())
	{
		cerr << "Image load fail" << endl;
		return -1;
	}

	imshow("src1",src1);
	imshow("src2", src2);

	Mat dst1, dst2, dst3, dst4, dst5, dst6;

	add(src1, src2, dst1);
	subtract(src1, src2, dst2);
	addWeighted(src1, 0.5, src2, 0.5,0,dst3);
	absdiff(src1, src2, dst4);

	dst1 = src1 + src2;
	dst2 = src1 - src2;
	

	multiply(src1, src2, dst5, 0.5);
	divide(src1, src2, dst6, 0.5);


	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);
	imshow("dst5", dst5);
	imshow("dst6", dst6);

	
	waitKey();

	return 0;

}



