#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int brightness_video(string path)
{
	//Ouvre la video choisie (selon le chemin)
	VideoCapture cap(path);

	//En cas d'impossibilit� d'ouvrir la vid�o, il y a un message d'erreur
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	//Nom de la fenetre dans laquelle s'affichera la vid�o modifi�e
	namedWindow("Modified frame", WINDOW_AUTOSIZE);


	//Trackbar

	int iBright_video = 150; // Valeur ou se trouve le curseur avant la modification de l'utilisateur

	//Cr�ation de la trackbar
	createTrackbar("Brightness", "Modified frame", &iBright_video, 300); // Valeur max : 300

	while (true)
	{
		Mat frame, newFrame;
		bool bSuccess = cap.read(frame);

		//Stop la boucle while lorque la vid�o est termin�e
		if (!bSuccess)
		{
			cout << "Reached the end of the video" << endl;
			break;
		}


		//AUgmentation/Diminution de la luminosit� de la vid�o 
		frame.convertTo(newFrame, frame.type(), 1, iBright_video - 150);

		imshow("Modified frame", newFrame);

		//Condition pour fermer la vid�o quand l'utilisateur appuie sur la touche esc
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}

	return 0;

}
