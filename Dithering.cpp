// Dithering.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//误差扩散抖动算法
//对二值化图像加以抖动可以使其有更多级的假象
//目标细节体现
#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
void EightToFour(void);
Mat img_src, img_gray, img_dst;
int main()
{
	img_src = imread("C:/images/1.jpg");
	imshow("原图", img_src);
	cvtColor(img_src, img_gray, COLOR_RGB2GRAY);
	//threshold(img_gray, img_dob, 127, 255, 0);
	imshow("8级灰度", img_gray);
	EightToFour();
	//imshow("4级灰度1", img_gray);
	int height = img_gray.rows;
	int width = img_gray.cols;
	int oldpixel, newpixel;
	int err;
	for (int i = 1; i < height-1; ++i)
		for (int j = 1; j < width-1; ++j)
		{
			oldpixel = img_gray.at<uchar>(i, j);
			//newpixel = static_cast<int>(oldpixel / 16) * 16;
			if (oldpixel > 127)
				newpixel = 255;
			else
				newpixel = 0;
			err = oldpixel - newpixel;
			img_gray.at<uchar>(i, j) = newpixel;
			img_gray.at<uchar>(i + 1, j) += err * 7 / 16;
			img_gray.at<uchar>(i - 1, j+1) += err * 3 / 16;
			img_gray.at<uchar>(i, j+ 1) += err * 5 / 16;
			img_gray.at<uchar>(i + 1, j+1) += err * 1 / 16;
		}
	imshow("1级灰度", img_gray);
	
	waitKey(0);
	return 0;
}
void EightToFour(void)
{
	Mat gray_test = img_gray.clone();
	int height = gray_test.rows;
	int width = gray_test.cols;
	int pixel;
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
		{
			pixel = gray_test.at<uchar>(i, j);
			//img_gray.at<uchar>(i, j) = static_cast<int>(pixel / 16) * 16;
			if (pixel > 127)
				gray_test.at<uchar>(i, j) = 255;
			else
				gray_test.at<uchar>(i, j) = 0;
		}
	imshow("二值化", gray_test);
}
