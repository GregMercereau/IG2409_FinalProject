#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int brightness_video(string path)
{
	//Ouvre la video choisie (selon le chemin)
	VideoCapture cap(path);

	//En cas d'impossibilité d'ouvrir la vidéo, il y a un message d'erreur
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	//Nom de la fenetre dans laquelle s'affichera la vidéo
	//namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Modified frame", WINDOW_AUTOSIZE);


	int iBright_video = 150; // Valeur ou se trouve le curseur avant la modification de l'utilisateur

	//Création de la trackbar
	createTrackbar("Brightness", "Modified frame", &iBright_video, 300); // Valeur max : 300

	while (true)
	{
		Mat frame, newFrame;
		bool bSuccess = cap.read(frame);
		// Lis une nouvelle frame de la vidéo
		//cap >> frame;

		//Stop la boucle while lorque la vidéo est terminée
		if (!bSuccess)
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}


		//increase the brightness by iBright_video 
		frame.convertTo(newFrame, frame.type(), 1, iBright_video - 150);
																 
		//Montre les frames dans la fenetre créée
																		 
		//imshow("Original image", frame);
		imshow("Modified frame", newFrame);

		//Attends 10 ms jusqu'à ce qu'il y ait une touche appuyée. Si la touche "Esc" est appuyé, la boucle while est stoppée, pour toute autre touche la boucle continue 
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

	return 0;

}
