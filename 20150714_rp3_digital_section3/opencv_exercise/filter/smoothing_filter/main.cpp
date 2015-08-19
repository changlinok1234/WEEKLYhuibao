
#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include <stdio.h>

using namespace cv;
int main(int argc, char* argv[])
{
        Mat src = imread("medium.png");
        Mat dst;
        blur(src,dst,Size(3,3),Point(-1,-1));
        imwrite("aveout.jpg",dst);
        medianBlur(src,dst,3);
        imwrite("medout.jpg",dst);

waitKey();

        return 0;
}
