#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int cannyEdgeDetec_video(string path)
{
	//Ouvre la video choisie (selon le chemin)
	VideoCapture cap(path);

	//En cas d'impossibilité d'ouvrir la vidéo, il y a un message d'erreur
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}



	int threshold1 = 250; // Valeur ou se trouve le curseur avant la modification de l'utilisateur
	int threshold2 = 50; // Valeur ou se trouve le curseur avant la modification de l'utilisateur

	//Nom de la fenetre dans laquelle s'affichera la vidéo modifiée
	namedWindow("Modified frame", WINDOW_AUTOSIZE);

	//Création de la trackbar
	createTrackbar("Treshold 1", "Modified frame", &threshold1, 500); // Valeur max : 300
	createTrackbar("Treshold 2", "Modified frame", &threshold2, 500); // Valeur max : 300

	while (true)
	{
		Mat frame, newFrame;
		bool bSuccess = cap.read(frame);

		//Stop la boucle while lorque la vidéo est terminée
		if (!bSuccess)
		{
			cout << "Reached the end of the video" << endl;
			break;
		}


		//Canny Edge Detection
		Canny(frame, newFrame, threshold1, threshold2, 3);


		//Affichage des frames dans la fenetre créée
		imshow("Modified frame", newFrame);

		//Condition pour fermer la vidéo quand l'utilisateur appuie sur la touche esc 
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}


	}
	return 0; 
}
