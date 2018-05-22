#include <opencv2/opencv.hpp>
#include <iostream>

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

	//Canny Edge Detection
	Canny(source, edgeImage, 250, 50, 3);

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("Edge Image", WINDOW_AUTOSIZE);

	imshow("Original Image", source);
	imshow("Edge Image", edgeImage);

	waitKey(0);
	destroyAllWindows();
}
