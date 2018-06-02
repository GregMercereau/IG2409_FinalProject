#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

vector<Mat> images;

int panorama(string path1, string path2)
{
	// Lecture de deux images 
	Mat img, img2;
	img = imread(path1, IMREAD_COLOR);
	img2 = imread(path2, IMREAD_COLOR);

	images.push_back(img);	//Ajoute les images lues dans un tableau "images"
	images.push_back(img2);

	Mat pano;	//Image résultat

	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA , true);
	Stitcher::Status status = stitcher->stitch(images, pano);

	// Message d'erreur si impossibilité de coller les images
	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		return -1;
	}


	namedWindow("Panorama", WINDOW_AUTOSIZE);
	imshow("Panorama", pano);
	
	//Boucle avec condition pour fermer l'image et l'enregistrer (ou non) quand l'utilisateur appuie sur la touche esc
	while(true)
	{
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			cout << "Do you want to save your modifications ? (Yes : 1 ; No : 2)\n" << endl;

			int savingChoice;
			cin >> savingChoice;

			if (savingChoice == 1)
			{ 
				imwrite("Saved_Image.jpg", pano);
				cout << "Your image has been saved successfully." << endl;
			}

			break;
		}
	}

	destroyAllWindows();

	return 0;
}
