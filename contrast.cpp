#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int contrast(string path)
{
	// Read the image file
	Mat source, new_Image; // new_Image is where the new picture is stored
	source = imread(path, IMREAD_COLOR);
	int value; 

	// Check for failure
	if (source.empty())
	{
		printf(" No image data \n ");
		return -1;
	}

	//L'utilisateur entre les valeurs du paramètre de luminosité : nombre positif pour augmenter, nbre négatif pour diminuer 
	cout << "Entrer les valeurs de vos paramètres :\n" << endl;
	//cout << "Number 1 :\n" << endl;
	cin >> value;


	//Contraste de l'image
	source.convertTo(new_Image, source.type(), value, 1);



	//Defining window names for above images
	//Create and open windows for above images
	namedWindow("Original image", WINDOW_AUTOSIZE);
	namedWindow("Contrasted image", WINDOW_AUTOSIZE);



	//Show above images inside the created windows.
	imshow("Original image", source);
	imshow("Contrasted Image", new_Image);



	// Wait for any key stroke
	waitKey(0);

	//destroy all open windows
	destroyAllWindows();

	return 0;
}
