#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

void drawLine();

int main(void)
{
	drawLine();
	return 0;
}

void drawLine()
{
	Mat img(400, 400, CV_8UC3,Scalar(255, 255, 255));
	
	line(img, Point(50, 50), Point(200, 5), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 0),3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0,0), 10);


	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255),1,LINE_4);
	line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 0), 1, LINE_8);
	line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1,LINE_8,0,0.05);

	drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);
	drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_STAR);

	imshow("img", img);
	waitKey(0);
	destroyAllWindows();

}