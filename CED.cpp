#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int cannyEdgeDetec(string path)
{
	
	Mat source, edgeImage;	
	source = imread(path, IMREAD_COLOR);	

	if(source.empty())
	{
		printf("No image data \n");
		return -1;
	}

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("Edge Image", WINDOW_AUTOSIZE);

	imshow("Original Image", source);
	
	//Trackbar
	int threshold1 = 250;	//1er paramètre 
	int threshold2 = 50;	//2e paramètre

	createTrackbar("Threshold 1", "Edge Image", &threshold1, 500);	//Trackbar pour réglage du 1er paramètre
	createTrackbar("Threshold 2", "Edge Image", &threshold2, 500);	//Trackbar pour réglage du 2e paramètre

	while(true)
	{
		
		//Canny Edge Detection avec les 2 paramètres issus des trackbars
		Canny(source, edgeImage, threshold1, threshold2, 3);
	
		//Affichage de l'image résultat
		imshow("Edge Image", edgeImage);

		//Condition pour fermer l'image et l'enregistrer (ou non) quand l'utilisateur appuie sur la touche esc
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			cout << "Do you want to save your modifications ? (Yes : 1 ; No : 2)\n" << endl;

			int savingChoice;
			cin >> savingChoice;

			if (savingChoice == 1)
			{ 
				imwrite("Saved_Image.jpg", edgeImage);
				cout << "Your image has been saved successfully." << endl;
			}

			break;
		}

	}
	
	return 0;
}
