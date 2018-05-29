#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int cannyEdgeDetec(string path);
int brightness(string path);
int resize(string path);
int pano();
int brightness_video(string path);
int blur_video(string path);
int gaussian_video(string path);
int rotate_video(string path);
int erosiondilatation(string path);
int panorama(string path1, string path2);
