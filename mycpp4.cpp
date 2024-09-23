#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;


int main(){
    Mat im = imread("../test2.png",1);
    Mat im2,mask;

    cvtColor(im,im2,COLOR_BGR2HSV);
    inRange(im2,Scalar(100,50,50),Scalar(140,255,255),mask);
    vector<vector<Point>>Contain;
    findContours(mask,Contain,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    for(int i=0;i<Contain.size();i++){
        Rect box = boundingRect(Contain[i]);
        rectangle(im,box,Scalar(0,255,0),10);
    }
    namedWindow("test",WINDOW_NORMAL);
    namedWindow("test2",WINDOW_NORMAL);
    resizeWindow("test",800,600);
    resizeWindow("test2",800,600);
    imshow("test",im);
    imshow("test2",mask);
    waitKey(0);

    return 0;
}









 





