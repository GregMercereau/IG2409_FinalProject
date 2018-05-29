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
       cout<<"Entrez la taille"<<endl;
       cin>>size;
       //int continue = 1;
       Mat element = getStructuringElement(cv::MORPH_CROSS,
              Point(size, size));
 
      //Apply erosion or dilation on the image
    
      	int choice;
      	cout<<"Entrez 1 pour érosion ou 2 pour dilatation"<<endl;
      	cin>>choice;
       	switch (choice){      
       		case 1 :
       		erode(image,dst,element); 
       		
       		break;
       		case 2 :
       		dilate(image,dst,element);
       		
       		break;
       		default: cout <<"entrer 1 ou 2"<<endl; 
       		break;
     }
  
       namedWindow( "Display window", CV_WINDOW_AUTOSIZE );  
       imshow( "Display window", image );                 
 
       namedWindow( "Result window", CV_WINDOW_AUTOSIZE );   
       imshow( "Result window", dst );
 
       waitKey(0);                                        
}
