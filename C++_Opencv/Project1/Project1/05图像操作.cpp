#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	//------------------------------------------标准第一步-----------------------
	Mat src, gray_src;
	src = imread("C:/Users/15064/Desktop/拓比/test.png");
	if (!src.data) {
		cout << "could not load image...\n" << endl;
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	//------------------------------------------标准第一步结束----------------------

	//变成单通道图像,灰度图像
	cvtColor(src, gray_src, CV_BGR2GRAY);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", gray_src);

	//单通道的像素
	int height = gray_src.rows;//长
	int width = gray_src.cols;//宽
	for (int row = 0; row < height; row++) {//行循环
		for (int col = 0; col < width; col++) {//列循环
			int gray = gray_src.at<uchar>(row, col);
			gray_src.at<uchar>(row, col) = 255 - gray;
			//printf("值:%d",gray);
		}
	}
	imshow("gray_invert", gray_src);//显示反差图像

	//三通道
	Mat dst;
	dst.create(src.size(), src.type());
	height = src.rows;//长
	width = src.cols;//宽
	int nc = src.channels();//获取通道数目
	printf("图片长度：%d", height);
	printf("图片宽度：%d", width);
	
	

	for (int row = 0; row < height; row++) {//行循环
		for (int col = 0; col < width; col++) {//列循环
			if (nc == 1) {
				int gray = gray_src.at<uchar>(row, col);
				gray_src.at<uchar>(row, col) = 255 - gray;
			}
			else if(nc == 3){
				int b = dst.at<Vec3b>(row, col)[0];
				int g = dst.at<Vec3b>(row, col)[1];
				int r = dst.at<Vec3b>(row, col)[2];
				//dst.at<Vec3b>(row, col)[0] = 255 - b;
				//dst.at<Vec3b>(row, col)[1] = 255 - g;
				//dst.at<Vec3b>(row, col)[2] = 255 - r;
				dst.at<Vec3b>(row, col)[0] = b;
				dst.at<Vec3b>(row, col)[1] = g;
				dst.at<Vec3b>(row, col)[2] = 0;

				gray_src.at<uchar>(row, col) = max(r, max(b, g));

				
			}
			
		}
	}
	

	
	//bitwise_not(src, dst);//和上面方法一样获取像素

	//imshow("output01",dst);//显示反差图像
	imshow("output02", gray_src);//显示反差图像
	waitKey(0);
	return 0;
}