/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
// Read the image file
	Mat source, new_Image; // new_Image is where the new picture is stored
	int value; 


source = imread("van_gogh.jpg", IMREAD_COLOR);


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

//Changement de la luminosité 
source.convertTo(new_Image, source.type(), 1, value);



//Defining window names for above images
//Create and open windows for above images
namedWindow("Original image", WINDOW_AUTOSIZE);
namedWindow("Brightness modified image", WINDOW_AUTOSIZE);


//Show above images inside the created windows.
imshow("Original image", source);
imshow("Brightness modified image", new_Image);



// Wait for any key stroke
waitKey(0);
//destroy all open windows
destroyAllWindows();

return 0;
}
*/