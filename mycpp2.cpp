#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;



int main(){
    Mat im = imread("../test2.png",1);
    Mat im2;
    cvtColor(im,im2,COLOR_BGR2GRAY);
    Mat outim;
    vector<vector<Point>> aContain;
    double area = 80000;
    threshold(im2,outim,60,255,THRESH_TRIANGLE);
    findContours(outim,aContain,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    for(int i=0;i<aContain.size();i++){
        double area_cmp = contourArea(aContain[i]);
        if(area < area_cmp){
            Rect box = boundingRect(aContain[i]);
            rectangle(im,box,Scalar(255,255,0),10);
        }
        
    }
    namedWindow("aTest",WINDOW_NORMAL);
    namedWindow("aTest2",WINDOW_NORMAL);
    resizeWindow("aTest",800,600);
    resizeWindow("aTest2",800,600);
    imshow("aTest",im);
    imshow("aTest2",im2);
    waitKey(0);

    
    return 0;
}