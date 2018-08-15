#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int, char**)
{
    int counter = 0; // count the frame
    VideoCapture cap(0); // open the default camera , when you declare number 0 , it means you are using the you webcam
    if(!cap.isOpened())  // check if we succeeded , that mean you don't have webcam
        return 0;
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame,frame,COLOR_BGR2GRAY); // this function will convert you image which is RGB color to gray color
         String name = "./"+ std::to_string(counter++) + ".png"; // warning : you should replace the './'
                                                                 //become the absolute path of folder which you want to save
                                                                // or you can use the fstream lib of c++ to handle it
         imwrite(name, frame); // take it easy , you will save image into yor folder
        imshow("res", frame); // show the current image

        if(waitKey(30) >= 0) break;
    }

    return 0;
}
