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
	//img�� JPEG ǰ�� 95%�� �����ϱ�
	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(95);
	imwrite("lenna_gray.jpg", img, params);
	//ũ�⸦ 1/2 ���� RGB �̹����� �ٽ� �о����
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

	destroyWindow("image"); // win name �� image �� â �ݱ�
	destroyAllWindows(); // ��� â �ݱ�

	return 0;
}
