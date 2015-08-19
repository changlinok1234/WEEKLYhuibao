#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
 #include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  sharpen
 *
 * @Param image
 * @Param result
 */
/* ----------------------------------------------------------------------------*/
void sharpen(const cv::Mat image, cv::Mat &result)
{
	result.create(image.size(), image.type());
	for(int j = 1; j < image.rows-1; j++)
	{
		const uchar* previous = image.ptr<const uchar>(j-1);
		const uchar* current  = image.ptr<const uchar>(j);
		const uchar* next     = image.ptr<const uchar>(j+1);

		uchar* output = result.ptr<uchar>(j);
		for(int i = 1; i < image.cols-1; i++)
		{
			//sharpened_pixel = 5*current-left-right-up-down;
			//cv::saturate_cast用以对计算结果进行截断（0-255）
			*output++ = cv::saturate_cast<uchar>(
					5*current[i]-current[i-1]
					-current[i+1]-previous[i]-next[i]);
		}
	}
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));
}

int main(int argc,char** argv)
{
	cv::Mat img = cv::imread(argv[1] : "lap.png");
	cv::cvtColor(img,img,CV_BGR2GRAY);
	cv::Mat result;
	result.create(img.size(), img.type());
	sharpen(img, result);
	cv::namedWindow("sharpen");
	cv::namedWindow("img");
	cv::imshow("img",img);
	cv::imshow("sharpen", result);
	cv::waitKey(0);
}
