/*//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	// open the video file for reading
	VideoCapture cap("chaplin.mp4");
	


	// if not success, exit program
	if (!cap.isOpened()) {
	cout << "Error opening video stream or file" << endl;
	return -1;
	}

	//define original and rotate window name
	namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Rotated video", WINDOW_AUTOSIZE);


	int iAngle = 180;

	//create track bar
	createTrackbar("Rotate", "Rotated video", &iAngle, 360);


	while (true)
	{


		// read a new frame from video
		Mat frame, r_video, M;
		bool bSuccess = cap.read(frame);
		Point2f center(frame.cols / 2, frame.rows / 2);


		//if not success, break loop
		if (!bSuccess)
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}

		//show the two video
		imshow("Original video", frame);
		//imshow("Rotated video", r_video);

		//get the affine transformation matrix 2D
		M = getRotationMatrix2D(center, iAngle, 1); 

			// Rotate the image using warpAffine
			warpAffine(frame, r_video, M, r_video.size());

		//show the rotate frame
		imshow("Rotated video", r_video);



		//wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}

	}

	return 0;
}
*/