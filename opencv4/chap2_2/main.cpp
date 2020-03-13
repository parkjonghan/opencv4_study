#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void) {


	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img;
	img = imread("lenna.bmp");

	if (img.empty())
	{
		cout << "Image load fail!" << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);
	
	waitKey();
	return 0;
}
