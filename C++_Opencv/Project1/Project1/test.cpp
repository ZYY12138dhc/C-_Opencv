#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

void print_px_value(Mat& im)
{
	int rowNumber = im.rows;  //行数
	int colNumber = im.cols * im.channels();  //列数 x 通道数=每一行元素的个数

	//双重循环，遍历所有的像素值
	for (int i = 0; i < rowNumber; i++)  //行循环
	{
		uchar* data = im.ptr<uchar>(i);  //获取第i行的首地址
		for (int j = 0; j < colNumber; j++)   //列循环
		{
			//data[j] = data[j] / div * div + div / 2;
			cout << (int)data[j] << endl;
		}  //行处理结束
	}

}


int main(int argc, char** argv) {
	//------------------------------------------标准第一步-----------------------
	Mat src;
	src = imread("C:/Users/15064/Desktop/拓比/test.png");
	if (!src.data) {
		cout << "could not load image...\n" << endl;
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	/*
	Mat dst;

	int cols = dst.cols;//得到全部的列（长）
	int rows = dst.rows;//得到全部的行（宽）
	printf("rows:%d\n cols:%d\n", rows, cols);//输出行和列

	const uchar *firstRow = dst.ptr<uchar>(0);
	printf("first pixel value:%d\n", *firstRow);//输出第一行像素

	imshow("output", dst);
	*/
	print_px_value(src);


	waitKey(0);

	return 0;
}
