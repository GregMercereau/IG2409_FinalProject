#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int gaussian_video(string path)
{
	VideoCapture cap(path);

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	namedWindow("Blurred frame - Gaussian", WINDOW_AUTOSIZE);
	
	//Trackbar
	int iSize = 0;
	createTrackbar("Gaussian blur", "Blurred frame - Gaussian", &iSize, 50);	//Valeurs entre 0 et 50

	while (true)
	{
		Mat frame, blurredFrame;

		bool bSuccess = cap.read(frame);

		//Fin du while a la fin de la video
		if (!bSuccess)
		{
			cout << "Reached the end of the video" << endl;
			break;
		}

		if(iSize%2 == 0)	//Les arguments de Size() doivent etre impairs, donc on agit en consequence
		{
			iSize = iSize+1;	//Si iSize pair, on ajoute 1
		}

		GaussianBlur(frame, blurredFrame, Size(iSize,iSize), 0, 0, BORDER_DEFAULT);	//Si iSize impair, pas de changement

		imshow("Blurred frame - Gaussian", blurredFrame);
	
		//Condition pour fermer la vidéo quand l'utilisateur appuie sur la touche esc
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}

	}

	return 0;
}
