#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
 
using namespace cv;
using namespace std;
 
void error_factors(Mat source);

int resize(string path)
{
        Mat source, scaledImage;
	int temoin = 0;
 
        source = imread(path, IMREAD_COLOR);
 
        namedWindow("Scaled image", WINDOW_AUTOSIZE);
 
        //Facteurs de redimensionnement
 
        int scaleX = 1;
        int scaleY = 1;
 
        createTrackbar("X", "Scaled image", &scaleX, 5);
        createTrackbar("Y", "Scaled image", &scaleY, 5);
 
        while(true)
        {
		if(scaleX < 1 || scaleY < 1)	//Protection contre le bug qui se produit si le curseur de la trackbar est placé en 0
		{
			cout << "Impossible de placer le curseur en 0. Erreur : facteur(s) nul(s). Veuillez entrer les valeurs au clavier :" << endl;
			scaleX = 1;
			scaleY = 1;
			temoin = 1;		
			error_factors(source);	//Appel d'une fonction secondaire pour que l'utilisateur entre lui-meme les facteurs
			break;
		}
		
		else
		{
			if(temoin == 0)	//Partie du programme accessible uniquement si l'utilisateur agrandit l'image (avec trackbar)
			{
				resize(source, scaledImage, Size(round(scaleX*source.cols), round(scaleY*source.rows)), scaleX, scaleY, INTER_LINEAR);

				//Affichage de l'image modifiee
				imshow("Scaled image", scaledImage);
		 
				//Condition pour fermer l'image et l'enregistrer (ou non) quand l'utilisateur appuie sur la touche esc

				if (waitKey(10) == 27)
				{
					cout << "Esc key is pressed by user. Closing the image" << endl;

					cout << "Souhaitez vous enregistrer votre nouvelle image ? Taper 1 pour Oui et 2 pour Non" << endl;

					int savingChoice;
					cin >> savingChoice;

					if (savingChoice == 1)
					{
						Mat savedImage; 
						imwrite("Saved_Image.jpg", scaledImage);
						cout << "Your image has been saved successfully." << endl;
					}

					break;
				}
			}
		}
        }

        return 0;
}


//Fonction secondaire pour reduire la taille de l'image, chose impossible avec la trackbar, qui ne prend que des fateurs entiers

void error_factors(Mat source)
{	
	Mat downsizedImage;
	double scaleX2 = 1;
	double scaleY2 = 1;

	//L'utilisateur entre lui-meme les facteurs qu'il désire

	cout << "Valeur du facteur horizontal : " << endl;
	cin >> scaleX2;
	cout << "Valeur du facteur vertical : " << endl;
	cin >> scaleY2;

	resize(source, downsizedImage, Size(round(scaleX2*source.cols), round(scaleY2*source.rows)), scaleX2, scaleY2, INTER_LINEAR);

	namedWindow("Downsized image",WINDOW_AUTOSIZE);
	imshow("Downsized image", downsizedImage);


	//Boucle avec condition pour fermer l'image et l'enregistrer (ou non) quand l'utilisateur appuie sur la touche esc

	while(true)
	{
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;

			cout << "Souhaitez vous enregistrer votre nouvelle image ? Taper 1 pour Oui et 2 pour Non" << endl;

			int savingChoice;
			cin >> savingChoice;

			if (savingChoice == 1)
			{ 
				imwrite("Saved_Image.jpg", downsizedImage);
				cout << "Your image has been saved successfully." << endl;
			}
			break;
		}
	}
}
