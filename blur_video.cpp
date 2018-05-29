#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int blur_video(string path)
{
	VideoCapture cap(path);

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	namedWindow("Blurred video", WINDOW_AUTOSIZE);
	
	//Trackbar
	int iSize = 0;
	createTrackbar("Blur", "Blurred video", &iSize, 50);

	// read a new frame from video

	while (true)
	{
		Mat frame, blurredFrame;

		bool bSuccess = cap.read(frame);

		//Fin du while a la fin de la video
		if (!bSuccess)
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		blur(frame, blurredFrame, Size(iSize+2,iSize+2), Point(-1, 1), BORDER_DEFAULT);	//iSize+2 pour eviter un bug

		imshow("Blurred video", blurredFrame);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

		return 0;

}
