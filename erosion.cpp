#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int erosiondilatation(string path)
{
	Mat image,dst;
	image = imread(path, CV_LOAD_IMAGE_COLOR);  

	//L'utilisateur entre un facteur de dilatation/d'érosion de son choix
	int size;
	cout<<"Entrez un facteur de dilatation/erosion"<<endl;
	cin>>size;
	
	//Création d'un élément structurant

	Mat element = getStructuringElement(cv::MORPH_CROSS, Point(size, size));

	namedWindow( "Result window", CV_WINDOW_AUTOSIZE );  
	
	//Choix de l'érosion ou de la dilatation
	int choice;
	cout<<"Entrez 1 pour érosion ou 2 pour dilatation"<<endl;
	cin>>choice;

	while(true)
	{
		switch (choice)
		{      
			case 1 :
			erode(image,dst,element);	//Cas de l'érosion

			break;
			case 2 :
			dilate(image,dst,element);	//Cas de la dilatation

			break;
			default: cout <<"entrer 1 ou 2"<<endl; 
			break;
		}

		imshow( "Result window", dst );
		
		//Condition pour fermer l'image et l'enregistrer (ou non) quand l'utilisateur appuie sur la touche esc
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			cout << "Do you want to save your modifications ? (Yes : 1 ; No : 2)\n" << endl;

			int savingChoice;
			cin >> savingChoice;

			if (savingChoice == 1)
			{ 
				imwrite("Saved_Image.jpg", dst);
				cout << "Your image has been saved successfully." << endl;
			}

			break;
		}

	}  
	return 0;                                      
}
