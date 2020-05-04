#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;
void camera_in();
void video_in();
void camera_in_video_out();
int main(void) {
	camera_in();
	video_in();
	camera_in_video_out();
	/*
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
	*/
	return 0;
}

void camera_in()
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}
	

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame FPS: " << cvRound(cap.get(CAP_PROP_FPS)) << endl;

	cap.set(CAP_PROP_FRAME_WIDTH, 640/2);
	cap.set(CAP_PROP_FRAME_HEIGHT, 480/2);
	cap.set(CAP_PROP_FPS, 15);

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame FPS: " << cvRound(cap.get(CAP_PROP_FPS)) << endl;


	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27) // ESC key
			break;
	}

	destroyAllWindows();
}

void video_in()
{
	VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened()) {
		cerr << "Video open failed!" << endl;
		return;
	}

	cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count: " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;

	int delay = cvRound(1000 / fps);

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // ESC key
			break;
	}

	destroyAllWindows();
}

void camera_in_video_out()
{
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));

	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return;
	}

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;
		outputVideo << inversed;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}

	destroyAllWindows();
}
