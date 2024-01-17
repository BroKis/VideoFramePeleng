// VideoFrame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main()
{
	VideoCapture video("Test.mp4");

	if (!video.isOpened()) {
		cerr << "Не удалось открыть видео файл." << endl;
		return 1;
	}

	VideoWriter outputVideo;
	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
	double fps = video.get(CAP_PROP_FPS);
	Size frameSize(static_cast<int>(video.get(CAP_PROP_FRAME_WIDTH)), 
		static_cast<int>(video.get(CAP_PROP_FRAME_HEIGHT)));

	outputVideo.open("test_output.avi", codec, fps, frameSize);

	if (!outputVideo.isOpened()) {
		cerr << "Не удалось создать выходной видео файл." <<endl;
		return 1;
	}

	int frameNumber = 0;
	Mat frame;

	while (video.read(frame)) {
		int frameWidth = frame.cols;
		int frameHeight = frame.rows;

		string codecName = video.getBackendName();

		putText(frame, "Snapshot: " + to_string(frameNumber), Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
		putText(frame, "Screen resolution: " + to_string(frameWidth) + "x" + to_string(frameHeight),Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
		putText(frame, "Codec: " + codecName, Point(10, 90),
			FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);
		outputVideo.write(frame);
		frameNumber++;
	}

	video.release();
	outputVideo.release();

	return 0;
	
}

