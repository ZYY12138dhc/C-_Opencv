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
	waitKey(2);
	
	//------------------------------------------标准第一步结束----------------------

	//三通道
	Mat dst;
	dst.create(src.size(), src.type());
	int height = src.rows;//长
	int width = src.cols;//宽
	int nc = src.channels();//获取通道数目
	printf("图片长度：%d\n", height);
	printf("图片宽度：%d", width);

	for (int row = 0; row < height; row++) { //行循环
		for (int col = 0; col < width; col++) { //列循环
			if (nc == 1) {
				int gray = gray_src.at<uchar>(row, col);
				gray_src.at<uchar>(row, col) = 255 - gray;
			}
			else if (nc == 3) {
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				cout << src.at<Vec3b>(row, col) << endl;
				dst.at<Vec3b>(row, col)[0] = b;
				dst.at<Vec3b>(row, col)[1] = g;
				dst.at<Vec3b>(row, col)[2] = r;
			}

		}
	}
	namedWindow("show1", 0);
	imshow("show1", dst);
	waitKey(0);
	return 0;
}