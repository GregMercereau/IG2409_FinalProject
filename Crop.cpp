/*
#include <opencv2/opencv.hpp>
#include <string>


using namespace std;
using namespace cv;


int main(void)
{
	Mat source, scaledImage;

	// Read source image
	source = imread("van_gogh.jpg", IMREAD_COLOR);

	// Scaling factors

	double scaleX, scaleY;// 

						  //L'utilisateur entre les valeurs des paramètres 
	cout << "Entrer les valeurs de vos paramètres :\n" << endl;
	//cout << "Number 1 :\n" << endl;
	cin >> scaleX;
	//cout << "Number 2 :\n" << endl;
	cin >> scaleY;


	
	//Rognage de l'image
	Mat crop = source(Range(50, 90), Range(50, 90));

	
	//Display windows and show for all four images

	// Showing the original Image
	namedWindow("Original image", WINDOW_AUTOSIZE);
	imshow("Original image", source); 


	//Showing  the cropped image
	namedWindow("Cropped image", WINDOW_AUTOSIZE);
	imshow("Cropped image", crop);



	waitKey(0);

	return 0;

}
*/