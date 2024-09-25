#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;


int main(){
  //VideoCapture video = VideoCapture("../test.mp4");
    VideoCapture video;
    double area = 1000;
    video.open(0);
    while(1){
        Mat frame;
        video.read(frame);
        Mat im2,mask;
        cvtColor(frame,im2,COLOR_BGR2HSV);
        inRange(im2,Scalar(100,50,50),Scalar(140,255,255),mask);
        vector<vector<Point>>Contain;
        findContours(mask,Contain,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
        for(int i=0;i<Contain.size();i++){
            Rect box = boundingRect(Contain[i]);
            double needarea = box.area();
            if(needarea > area){
                rectangle(frame,box,Scalar(0,255,0),5);
                Point center(box.x + box.width/2,box.y + box.height/2);
                cout << center << endl;
            }
        }
        namedWindow("test2",WINDOW_NORMAL);
        namedWindow("test",WINDOW_NORMAL);
        resizeWindow("test",800,600);
        resizeWindow("test2",800,600);
        imshow("test2",mask);
        imshow("test",frame);
        waitKey(60);
    }
    return 0;
}









 





