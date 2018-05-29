#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;



vector<Mat> images;
//string result_name = "result.jpg"; // Création d'une nouvelle image enregistrée résultat




int main(int argc, char* argv[])
{
	// Lis une image 
	Mat img, img2;
	img = imread("van_gogh.jpg", IMREAD_COLOR);
	img2 = imread("van_gogh.jpg", IMREAD_COLOR);

	namedWindow("test", WINDOW_AUTOSIZE);
	imshow("test", img);

	// Wait for any key stroke
	waitKey(0);

	//destroy all open windows
	destroyAllWindows();

	images.push_back(img); // Ajoute les images lues dans un tableau "images"
	images.push_back(img2);

	Mat pano; // Image résultat

	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA , true);
	Stitcher::Status status = stitcher->stitch(images, pano);

	// Message d'erreur si impossibilité de coller les images
	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		return -1;
	}


	namedWindow("Original image", WINDOW_AUTOSIZE);
	imshow("Original image", pano);
	//imwrite(result_name, pano);

	// Wait for any key stroke
	waitKey(0);

	//destroy all open windows
	destroyAllWindows();

	//cout << "stitching completed successfully\n" << result_name << " saved!";
	return 0;
}