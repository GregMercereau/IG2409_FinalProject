#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int brightness(string path)
{

	Mat source, new_Image; 
	//int value; 

	source = imread(path, IMREAD_COLOR);

	if (source.empty())
	{
	printf("No image data \n ");
	return -1;
	}
	
	namedWindow("Image", WINDOW_AUTOSIZE);

	

	//cout << "Entrer la valeur du parametre de luminosité (>0 pour augmenter, <0 pour diminuer)\n" << endl;
	//cout << "Number 1 :\n" << endl;
	//cin >> value;
	
	int iBright = 150;

	createTrackbar("Brightness Trackbar", "Image", &iBright, 300);

	while(true)
	{
		
		//Changement de la luminosité 
		source.convertTo(new_Image, source.type(), 1, iBright-150);

		imshow("Image", new_Image);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			break;
		}

	}
	

	return 0;
}

