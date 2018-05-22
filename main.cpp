#include <opencv2/opencv.hpp>
#include <iostream>
#include "CED.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{		
	int select;	
	string path;
	
	printf("Quel est le chemin vers votre image ?\n");
	cin >> path;

	printf("Que voulez-vous faire avec votre image ? \n(Dilatation/Erosion = 1, \nResizing = 2, \nLighten/Darken = 3, \nPanorama = 4, \nCanny Edge Detection = 5)\n");
	cin >> select;

	if(select == 5)
	{
		printf("Lancement de la Canny Edge Detection...\n");		
		cannyEdgeDetec(path);
		printf("Done\n");
	}
}
