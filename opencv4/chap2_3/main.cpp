#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void) {


	cout << "Hello OpenCV" << CV_VERSION << endl;

	Mat img;
	img = imread("lenna.bmp",IMREAD_GRAYSCALE);

	if (img.empty())
	{
		cout << "Image load fail!" << endl;
		return -1;
	}
	//img를 JPEG 품질 95%로 저장하기
	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(95);
	imwrite("lenna_gray.jpg", img, params);
	//크기를 1/2 줄인 RGB 이미지로 다시 읽어오기
	Mat imgGray;
	imgGray = imread("lenna_gray.jpg", IMREAD_REDUCED_COLOR_2);
	if (imgGray.empty())
	{
		cout << "Image load fail!" << endl;
		return -1;
	}
	namedWindow("image");
	namedWindow("imageGray");
	imshow("image", img);
	imshow("imageGray", imgGray);
	waitKey();

	destroyWindow("image"); // win name 이 image 인 창 닫기
	destroyAllWindows(); // 모든 창 닫기

	return 0;
}
