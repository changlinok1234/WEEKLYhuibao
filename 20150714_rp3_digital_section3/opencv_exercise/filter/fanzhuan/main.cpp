

# include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cv.h"
#include "highgui.h"
main()
{
 int length,width,step,channel;
 uchar * data;
 int i,j,k;
 IplImage* img;
 img=cvLoadImage("fanzhuan.png",0);
 if(!img)
  printf("could not find the image\n");

length=img->height;
width=img->width;
step=img->widthStep;
channel=img->nChannels;
data=(uchar*)img->imageData;

for(i=0;i<=length-1;i++)
{
 for(j=0;j<=width-1;j++)
 {
  for(k=0;k<=channel-1;k++)
  {
   data[i*step+j*channel+k]=255-data[i*step+j*channel+k];
  }
 }
}
cvNamedWindow("convert",0);
cvShowImage("convert",img);
cvSaveImage("fanzhuanout.png",img );
cvWaitKey(0);
cvReleaseImage(&img);
return 0;
}
