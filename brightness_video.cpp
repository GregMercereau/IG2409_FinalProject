#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int brightness_video(string path)
{
	//open the video file for reading

	VideoCapture cap(path);


	// if not success, exit program
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	//Defining window names

	namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Frames increased by 50", WINDOW_AUTOSIZE);
	namedWindow("Frames increased by 100", WINDOW_AUTOSIZE);
	namedWindow("Frames decreased by 50", WINDOW_AUTOSIZE);
	namedWindow("Frames decreased by 100", WINDOW_AUTOSIZE);

	while (true)
	{
		Mat frame, frameI50, frameI100, frameD50, frameD100;
		// read a new frame from video
		cap >> frame;

		//Breaking the while loop at the end of the video

		if (frame.empty())
		{
			break;
		}

		//increase the brightness by 50
		frame.convertTo(frameI50, frame.type(), 1, 50);

		//increase the brightness by 100
		frame.convertTo(frameI100, frame.type(), 1, 100);

		//decrease the brightness by 50
		frame.convertTo(frameD50, frame.type(), 1, -50);

		//decrease the brightness by 100
		frame.convertTo(frameD100, frame.type(), 1, -100);

		//Show above frames inside the created windows.
		imshow("Original image", frame);
		imshow("Frames increased by 50", frameI50);
		imshow("Frames increased by 100", frameI100);
		imshow("Frames decreased by 50", frameD50);
		imshow("Frames decreased by 100", frameD100);

		//wait for for 10 ms until any key is pressed.
		//If the 'Esc' key is pressed, break the while loop.
		//If the any other key is pressed, continue the loop
		//If any key is not pressed withing 10 ms, continue the loop
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

	return 0;

}
