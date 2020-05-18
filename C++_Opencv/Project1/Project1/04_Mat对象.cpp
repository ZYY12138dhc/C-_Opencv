//04_Mat对象

#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	//------------------------------------------标准第一步-----------------------
	Mat src;
	src = imread("C:/Users/15064/Desktop/拓比/test.png");
	if (!src.data) {
		cout<<"could not load image...\n"<<endl;
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	/*
	//eg.1生成一张粉色背景图
	Mat dst;
	dst = Mat(src.size(), src.type());
	//赋值
	dst = Scalar(127, 0, 255);

	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	*/

	/*
	//eg.2克隆拷贝
	Mat dst = src.clone();//
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	*/

	/*和eg.2类似
	Mat dst;
	src.copyTo(dst);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	*/

	Mat dst;
	cvtColor(src,dst,CV_BGR2GRAY);//灰色
	printf("input image channels:%d\n",src.channels());//三条通道
	printf("output image channels:%d\n", dst.channels());//一条通道
	namedWindow("output", CV_WINDOW_AUTOSIZE);


	int cols = dst.cols;//得到全部的列（长）
	int rows = dst.rows;//得到全部的行（宽）
	printf("rows:%d\n cols:%d\n", rows, cols);//输出行和列

	const uchar *firstRow = dst.ptr<uchar>(0);
	printf("first pixel value:%d\n", *firstRow);//输出第一行像素
	
	Mat M(100, 100, CV_8UC3, Scalar(0, 0, 255));//构造函数
	//cout << "M=" << endl << M << endl;


	imshow("output", M);
	//imshow("output", dst);

	Mat m1;
	m1.create(src.size(), src.type());//构造函数
	m1 = Scalar(0, 0, 255);
	imshow("output", m1);

	waitKey(0);
	return 0;
}
