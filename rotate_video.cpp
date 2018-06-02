#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int rotate_video(string path)
{

	VideoCapture cap(path);

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	namedWindow("Rotated video", WINDOW_AUTOSIZE);

	//Trackbar
	int iAngle = 180;

	createTrackbar("Rotate", "Rotated video", &iAngle, 360);	//Valeurs entre 0 et 360


	while (true)
	{

		Mat frame, r_video, M;
		bool bSuccess = cap.read(frame);
		Point2f center(frame.cols / 2, frame.rows / 2);

		if (!bSuccess)
		{
			cout << "Reached the end of the video" << endl;
			break;
		}

		//Obtention de la matrice 2D de transformation affine
		M = getRotationMatrix2D(center, iAngle, 1); 

		//Rotation de la vidéo grâce à warpAffine
		warpAffine(frame, r_video, M, r_video.size());

		//Affichage de la vidéo modifiée
		imshow("Rotated video", r_video);

		//Condition pour fermer la vidéo quand l'utilisateur appuie sur la touche esc
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}

	}

	return 0;
}
