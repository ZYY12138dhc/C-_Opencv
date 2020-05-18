//03_矩阵的掩膜操作

#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("C:/Users/15064/Desktop/拓比/test.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	/*
	//获取图像的宽度
	int cols = src.cols * src.channels();//channels()图像通道数
	int offsetx = src.channels();
	//获取图像的高度
	int rows = src.rows;
	//对图像初始化，和读取的图像大小和类型一致，黑背景空白图像
	dst = Mat::zeros(src.size(),src.type());
	for (int row = 1; row < (rows - 1); row++) {
		//获取当前的像素值
		const uchar* previous = src.ptr<uchar>(row - 1);//上行
		const uchar* current = src.ptr<uchar>(row);//中行
		const uchar* next = src.ptr<uchar>(row + 1);//下行
		uchar *output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}
	*/

	//opencv有和上面操作一致的简洁方法,通过filter2D[API]来实现
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernel);//src.depth()可改成-1，即万能参数


	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	waitKey(0);
	return 0;
}