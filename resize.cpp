#include <opencv2/opencv.hpp>
#include <string>


using namespace std;
using namespace cv;


int resize(string path)
{
	Mat source, scaledImage; 

	// Read source image
	source = imread(path, IMREAD_COLOR);

	// Scaling factors

	double scaleX, scaleY; 

	//L'utilisateur entre les valeurs des param�tres 
	cout << "Entrer les valeurs de vos param�tres :\n" << endl;
	//cout << "Number 1 :\n" << endl;
	cin >> scaleX;
	//cout << "Number 2 :\n" << endl;
	cin >> scaleY;

	// Diminution de la taille de l'image : Choix des facteurs -> Diminution si inf � 1 et Augmentation si sup � 1
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

