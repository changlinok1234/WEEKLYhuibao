#include  "opencv2/highgui/highgui.hpp"
#include  "opencv2/imgproc/imgproc.hpp"
using namespace cv;
int main()
{
    //loading origin image
    Mat srcImage,dstImage;
    srcImage=imread("bhpf.png",1);
    if(!srcImage.data)
    {
        printf("wrong reading~  \n ");
        return false;
    }
    //turn to gray
    cvtColor(srcImage,srcImage,COLOR_BGR2GRAY);
    imshow("origin",srcImage);
    //equa
    equalizeHist(srcImage,dstImage);
    imshow("after equa",dstImage);
    imwrite("equa.png",dstImage);
    waitKey(0);
    return 0;
}
