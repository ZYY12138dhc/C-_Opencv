//04_Mat����

#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	//------------------------------------------��׼��һ��-----------------------
	Mat src;
	src = imread("C:/Users/15064/Desktop/�ر�/test.png");
	if (!src.data) {
		cout<<"could not load image...\n"<<endl;
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	/*
	//eg.1����һ�ŷ�ɫ����ͼ
	Mat dst;
	dst = Mat(src.size(), src.type());
	//��ֵ
	dst = Scalar(127, 0, 255);

	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	*/

	/*
	//eg.2��¡����
	Mat dst = src.clone();//
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	*/

	/*��eg.2����
	Mat dst;
	src.copyTo(dst);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", dst);
	*/

	Mat dst;
	cvtColor(src,dst,CV_BGR2GRAY);//��ɫ
	printf("input image channels:%d\n",src.channels());//����ͨ��
	printf("output image channels:%d\n", dst.channels());//һ��ͨ��
	namedWindow("output", CV_WINDOW_AUTOSIZE);


	int cols = dst.cols;//�õ�ȫ�����У�����
	int rows = dst.rows;//�õ�ȫ�����У���
	printf("rows:%d\n cols:%d\n", rows, cols);//����к���

	const uchar *firstRow = dst.ptr<uchar>(0);
	printf("first pixel value:%d\n", *firstRow);//�����һ������
	
	Mat M(100, 100, CV_8UC3, Scalar(0, 0, 255));//���캯��
	//cout << "M=" << endl << M << endl;


	imshow("output", M);
	//imshow("output", dst);

	Mat m1;
	m1.create(src.size(), src.type());//���캯��
	m1 = Scalar(0, 0, 255);
	imshow("output", m1);

	waitKey(0);
	return 0;
}
