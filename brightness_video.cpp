#include <opencv2/opencv.hpp>
#include <iostream>

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

	//Nom de la fenetre dans laquelle s'affichera la vid�o
	//namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Mofified image", WINDOW_AUTOSIZE);


	int iBright_video = 150; // Valeur ou se trouve le curseur avant la modification de l'utilisateur

							 //Cr�ation de la trackbar
	createTrackbar("Brightness Trackbar", "Image", &iBright_video, 300); // Valeur max : 300


	while (true)
	{
		Mat frame, newFrame;
		// Lis une nouvelle frame de la vid�o
		cap >> frame;

		//Stop la boucle whike lorque la vid�o est termin�e
		if (frame.empty())
		{
			break;
		}


		//increase the brightness by iBright_video 
		frame.convertTo(newFrame, frame.type(), 1, iBright_video - 150); // permet de faire les valeurs <0


																		 //Montre les frames dans la fenetre cr��e
																		 //imshow("Original image", frame);
		imshow("Modified image", newFrame);

		//wait for for 10 ms until any key is pressed. Attends 10 ms jusqu'� ce qu'il y ait une touche appuy�e. Si la touche "Esc" est appuy�, la boucle while ets stopp�e pour tout autre touche la boucle continue 
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

	return 0;

}
