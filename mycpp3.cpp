#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat im = imread("../test.jpg",1);
    namedWindow("test",WINDOW_NORMAL);
    imshow("test",im);
    waitKey(0);
    return 0;
}