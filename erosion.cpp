#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int erosiondilatation(string path)
{
	Mat image,dst;
	image = imread(path, CV_LOAD_IMAGE_COLOR);  

	// Create a structuring element
	int size;
	cout<<"Entrez un facteur de dilatation/erosion\n"<<endl;
	cin>>size;
	
	Mat element = getStructuringElement(cv::MORPH_CROSS, Point(size, size));

	namedWindow( "Result window", CV_WINDOW_AUTOSIZE );  
	
	int choice;
	cout<<"Entrez 1 pour érosion ou 2 pour dilatation"<<endl;
	cin>>choice;

	//Apply erosion or dilation on the image

	while(true)
	{
		switch (choice)
		{      
			case 1 :
			erode(image,dst,element); 

			break;
			case 2 :
			dilate(image,dst,element);

			break;
			default: cout <<"entrer 1 ou 2"<<endl; 
			break;
		}

		imshow( "Result window", dst );
		
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			break;
		}

	}  
	return 0;                                      
}
