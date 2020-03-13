#include "opencv2/opencv.hpp"
#include <iostream>


int main(void) {


	std::cout << "Hello OpenCV" << CV_VERSION << std::endl;

	cv::Mat img;
	img = cv::imread("lenna.bmp");

	if (img.empty())
	{
		std::cout << "Image load fail!" << std::endl;
		return -1;
	}

	cv::namedWindow("image");
	cv::imshow("image", img);
	
	cv::waitKey();
	return 0;
}
