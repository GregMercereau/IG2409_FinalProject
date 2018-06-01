#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int cannyEdgeDetec_video(string path)
{
	//Ouvre la video choisie (selon le chemin)
	VideoCapture cap(path);

	//En cas d'impossibilit� d'ouvrir la vid�o, il y a un message d'erreur
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}



	int threshold1 = 250; // Valeur ou se trouve le curseur avant la modification de l'utilisateur
	int threshold2 = 50; // Valeur ou se trouve le curseur avant la modification de l'utilisateur

	//Nom de la fenetre dans laquelle s'affichera la vid�o
	//namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Modified frame", WINDOW_AUTOSIZE);

	//Cr�ation de la trackbar
	createTrackbar("Treshold 1", "Modified frame", &threshold1, 500); // Valeur max : 300
	createTrackbar("Treshold 2", "Modified frame", &threshold2, 500); // Valeur max : 300

	while (true)
	{
		Mat frame, newFrame;
		bool bSuccess = cap.read(frame);
		// Lis une nouvelle frame de la vid�o
		//cap >> frame;

		//Stop la boucle while lorque la vid�o est termin�e
		if (!bSuccess)
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}


		//Canny Edge Detection
		Canny(frame, newFrame, threshold1, threshold2, 3);


		//Montre les frames dans la fenetre cr��e
		//imshow("Original image", frame);
		imshow("Modified frame", newFrame);

		//Attends 10 ms jusqu'� ce qu'il y ait une touche appuy�e. Si la touche "Esc" est appuy�, la boucle while est stopp�e, pour toute autre touche la boucle continue 
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}


	}
	return 0; 
}

int main(int argc, char* argv[])
{
	cannyEdgeDetec_video("cup.mp4");
}