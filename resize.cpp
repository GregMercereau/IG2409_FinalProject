#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


int resize(string path)
{
	Mat source, scaledImage; 

	// Read source image
	source = imread(path, IMREAD_COLOR);

	// Scaling factors

	double scaleX, scaleY; 

	//L'utilisateur entre les valeurs des paramètres 
	cout << "Entrer les valeurs de vos parametres :\n" << endl;

	cout << "Facteur horizontal (< 1 pour diminuer la taille, > 1 sinon) :\n" << endl;
	cin >> scaleX;

	cout << "Facteur vertical (< 1 pour diminuer la taille, > 1 sinon) :\n" << endl;
	cin >> scaleY;

	// Diminution de la taille de l'image : Choix des facteurs -> Diminution si inf à 1 et Augmentation si sup à 1
	resize(source, scaledImage, Size(round(scaleX*source.cols), round(scaleY*source.rows)), scaleX, scaleY, INTER_LINEAR);




	//Display windows and show for all four images

	// Showing the original Image
	namedWindow("Original image", WINDOW_AUTOSIZE);
	imshow("Original image", source);
	//waitKey(0);


	//Showing  the new image
	namedWindow("Scaled image", WINDOW_AUTOSIZE);
	imshow("Scaled image", scaledImage);


	waitKey(0);

	return 0;

}

