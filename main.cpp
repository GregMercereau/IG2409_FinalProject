#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <cstddef>
#include "functions.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{		
	int select;	
	string path, path1, path2;
	size_t length = path.size();
	
	printf("Quel est le chemin vers votre fichier ?\n");
	cin >> path;

	size_t found = path.find_last_of('4');
	
	if(found==path.size()-1)
	{
		printf("Que voulez vous faire avec votre vidéo ? \n(Brightness = 1, \nContrast = 2, \nBlur = 3, \nGaussian = 4, \nRotation = 5)\n");

		cin >> select;

		if(select == 1)
		{	
		brightness_video(path);
		printf("The video has been brightened.\n");
		}

		if(select == 2)
		{		
		contrast_video(path);
		printf("The video has been contrasted.\n");
		}

		if(select == 3)
		{	
		blur_video(path);
		printf("The video has been blurred.\n");
		}

		if(select == 4)
		{		
		gaussian_video(path);
		printf("The video has been Gaussian blurred.\n");
		}

		if(select == 5)
		{		
		rotate_video(path);
		printf("The video has been rotated.\n");
		}
	}
	
	else
	{
		
		printf("Que voulez-vous faire avec votre image ? \n(Dilatation/Erosion = 1, \nResizing = 2, \nBrightness = 3, \nPanorama = 4, \nCanny Edge Detection = 5)\n");
		cin >> select;
		
		if(select == 1)
		{		
			erosiondilatation(path);
			printf("The image has been dilatated/erosed.\n");
		}

		if(select == 2)
		{		
			resize(path);
			printf("The image has been resized.\n");
		}

		if(select == 3)
		{		
			brightness(path);
			printf("The image has been ligthened/darkened.\n");
		}
		
		if(select == 4)
		{		
			path1 = path;			
			printf("Quel est le chemin de votre 2e image ?\n");
			cin >> path2;
			panorama(path1, path2);
			printf("Panorama done.\n");
		}

		if(select == 5)
		{		
			cannyEdgeDetec(path);
			printf("Canny Edge Detection done.\n");
		}
	}
}
