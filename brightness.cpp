#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int brightness(string path)
{

	Mat source, new_Image;  

	source = imread(path, IMREAD_COLOR);

	//Message d'erreur s'il y a un problème avec le fichier source entré 
	if (source.empty())
	{
	printf("No image data \n ");
	return -1;
	}
	
	namedWindow("Image", WINDOW_AUTOSIZE);

	//Trackbar	
	int iBright = 150;

	createTrackbar("Brightness Trackbar", "Image", &iBright, 300);

	while(true)
	{
		
		//Changement de la luminosité 
		source.convertTo(new_Image, source.type(), 1, iBright-150);

		imshow("Image", new_Image);

		//Condition pour fermer l'image et l'enregistrer (ou non) quand l'utilisateur appuie sur la touche esc
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			cout << "Do you want to save your modifications ? (Yes : 1 ; No : 2)\n" << endl;

			int savingChoice;
			cin >> savingChoice;

			if (savingChoice == 1)
			{ 
				imwrite("Saved_Image.jpg", new_Image);
				cout << "Your image has been saved successfully." << endl;
			}

			break;
		}

	}
	

	return 0;
}

