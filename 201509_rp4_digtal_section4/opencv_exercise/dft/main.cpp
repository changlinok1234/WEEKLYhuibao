#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
int main()
{
    Mat srcImage=imread("dftor.png",0);
    if(!srcImage.data)
    {printf("wrong reading,be sure if there are any image refered to imread \n" ); return false;}
     imshow("orgin",srcImage);
     imwrite("orgn.png",srcImage);
  // ShowHelpText();

    int m=getOptimalDFTSize(srcImage.rows);
    int n=getOptimalDFTSize(srcImage.cols);
    Mat padded;
    copyMakeBorder(srcImage,padded,0,m-srcImage.rows,0,n-srcImage.cols,BORDER_CONSTANT,Scalar::all(0));
    Mat planes[]={Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F)};
    Mat complexI;
    merge (planes,2,complexI);
    dft(complexI,complexI);
    split(complexI,planes);
    magnitude(planes[0],planes[1],planes[0]);
    Mat magnitudeImage=planes[0];
    magnitudeImage+=Scalar::all(1);
    log(magnitudeImage,magnitudeImage);
    //裁剪和重新分布幅度图象限
    magnitudeImage= magnitudeImage(Rect(0,0,magnitudeImage.cols& -2,magnitudeImage.rows & -2));
    //重新排列傅里叶图像中的象限，使得原点位于图像中心
  int cx=magnitudeImage.cols/2;
  int cy=magnitudeImage.rows/2;
  Mat q0(magnitudeImage,Rect(0,0,cx,cy));
  Mat q1(magnitudeImage,Rect(cx,0,cx,cy));
  Mat q2(magnitudeImage,Rect(0,cy,cx,cy));
  Mat q3(magnitudeImage,Rect(cx,cy,cx,cy));
  //交换象限
  Mat tmp;
  q0.copyTo(tmp);
  q3.copyTo(q0);
  tmp.copyTo(q3);
  q1.copyTo(tmp);
  q2.copyTo(q1);
  tmp.copyTo(q2);
  //归一化
  normalize(magnitudeImage,magnitudeImage,0,1,NORM_MINMAX);
  imshow("magnitude",magnitudeImage);
  imwrite("magnitude.png",magnitudeImage);

waitKey();
return 0;

}
