#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>


using namespace cv;
using namespace std;


int main(void) {

	//printf("%s %d ")

	
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
	imshow("image2", img);
	
	waitKey();
	return 0;
}
