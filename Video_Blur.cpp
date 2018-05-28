
//#include <opencv2/opencv.hpp>
// <iostream>

/*
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	//open the video file for reading
	VideoCapture cap("chaplin.mp4");

	// if not success, exit program
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}


	//Define names of the windows
	// Create a window with above names
	namedWindow("Original video", WINDOW_AUTOSIZE);
	namedWindow("Blured frames", WINDOW_AUTOSIZE);


	// read a new frame from video

	while (true)
	{
		Mat frame, bluredFrame;
		cap >> frame;

		//Breaking the while loop at the end of the video

		if (frame.empty())
		{
			break;
		}

		//Blur the frame with 5x5 kernel
		blur(frame, bluredFrame, Size(5, 5), Point(-1, 1), BORDER_DEFAULT);

		//show the frames in the created windows
		imshow("Original video", frame);
		imshow("Blured frames ", bluredFrame);

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
*/