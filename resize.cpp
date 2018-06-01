#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
 
using namespace cv;
using namespace std;
 
 
int resize(string path)
{
        Mat source, scaledImage;
 
        // Read source image
        source = imread(path, IMREAD_COLOR);
 
 
        //namedWindow("Original image", WINDOW_AUTOSIZE);
        namedWindow("Scaled image", WINDOW_AUTOSIZE);
 
        // Scaling factors
 
        int scaleX = 1;
        int scaleY = 1;
 
 
        //L'utilisateur entre les valeurs des paramètres
        //cout << "Entrer les valeurs de vos paramètres :\n" << endl;
        //cout << "Number 1 :\n" << endl;
        //cin >> scaleX;
        //cout << "Number 2 :\n" << endl;
        //cin >> scaleY;
 
        createTrackbar("X", "Scaled image", &scaleX, 5);
        createTrackbar("Y", "Scaled image", &scaleY, 5);
 
        while (true)
        {
               // Diminution de la taille de l'image : Choix des facteurs -> Diminution si inf à 1 et Augmentation si sup à 1
               resize(source, scaledImage, Size(round(scaleX*source.cols), round(scaleY*source.rows)), scaleX, scaleY, INTER_LINEAR);
 
               //Display windows and show for all four images
 
               // Showing the original Image
               //imshow("Original image", source);
               //waitKey(0);
 
 
               //Showing  the new image
               imshow("Scaled image", scaledImage);
 
               if (waitKey(10) == 27)
               {
                       cout << "Esc key is pressed by user. Closing the image" << endl;
 
                       cout << "Souhaitez vous enregistrer votre nouvelle image ? Taper 1 pour Oui et 2 pour Non" << endl;
 
                       int savingchoice;
                       cin >> savingchoice;
 
			if (savingchoice == 1)
			{
				Mat savedImage; 
				imwrite("Saved_Image.jpg", scaledImage);
				cout << "Your image has been saved successfully." << endl;
			}
 
                       break;
               }
 
        }
 
        return 0;
 
}
