#include  <opencv2/opencv.hpp>
//#include <opencv.hpp>
//#include <imgproc.hpp>
#include  <opencv2/imgproc/imgproc.hpp>
using namespace   cv;
int main ()
{

//载入原始图
Mat srcImage= imread("zoomandshrinkor.png");
Mat tmpImage,dstImage1,dstImage2,dstImage3,dstImage4;
tmpImage=srcImage;
//显示原始图
imshow("original",srcImage);

//尺寸调整
resize (tmpImage,dstImage1,Size(tmpImage.cols/2,tmpImage.rows/2),(0,0),(0,0),3);
resize (tmpImage,dstImage2,Size(tmpImage.cols*2,tmpImage.rows*2),(0,0),(0,0),3);
resize (dstImage1,dstImage3,Size(dstImage1.cols*2,dstImage1.rows*2),(0,0),(0,0),3);
resize (dstImage2,dstImage4,Size(dstImage2.cols/2,dstImage2.rows/2),(0,0),(0,0),3);

//显示并保存

imshow("suoxiao",dstImage3);
imshow("fangda",dstImage4);

imwrite("suoxao.png",dstImage3);
imwrite("fangda.png",dstImage4);

waitKey(0);
return  0;
}
