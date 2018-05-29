#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int contrast_video(string path)
{
	//open the video file for reading
	VideoCapture cap(path);


	// if not success, exit program
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	//Defining window names for above images
	namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Frames increased by 2", WINDOW_AUTOSIZE);
	namedWindow("Frames increased by 4", WINDOW_AUTOSIZE);
	namedWindow("Frames decreased by 0.5", WINDOW_AUTOSIZE);
	namedWindow("Frames decreased by 0.25", WINDOW_AUTOSIZE);



	//Create and open windows for above images


	while (true)
	{
		// read a new frame from video
		Mat frame, frameI2, frameI4, frameD05, frameD025;
		bool bSuccess = cap.read(frame); 


		// read a new frame from video
		cap >> frame;

		//Breaking the while loop at the end of the video
		if (bSuccess == false)
		{
			cout << "Found the end of the video" << endl;
			break;
		}

		//increase the contrast by 2
		frame.convertTo(frameI2, frame.type(), 2, 1);

		//increase the contrast by 4
		frame.convertTo(frameI4, frame.type(), 4, 1);

		//decrease the contrast by 0.5
		frame.convertTo(frameD05, frame.type(), 0.5, 1);

		//decrease the contrast by 0.25
		frame.convertTo(frameD025, frame.type(), 0.25, 1);

		//Show above images inside the created windows.
		imshow("Original video frame", frame);
		imshow("Frames increased by 50", frameI2);
		imshow("Frames increased by 100", frameI4);
		imshow("Frames decreased by 50", frameD025);
		imshow("Frames decreased by 100", frameD05);



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
