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

	int threshold1 = 250;
	int threshold2 = 50;

	createTrackbar("Threshold 1", "Edge Image", &threshold1, 500);
	createTrackbar("Threshold 2", "Edge Image", &threshold2, 500);

	while(true)
	{
		
		//Canny Edge Detection
		Canny(source, edgeImage, threshold1, threshold2, 3);

		imshow("Edge Image", edgeImage);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Closing the image" << endl;
			break;
		}

	}
	
	return 0;
}
