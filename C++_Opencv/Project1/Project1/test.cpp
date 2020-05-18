#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

void print_px_value(Mat& im)
{
	int rowNumber = im.rows;  //����
	int colNumber = im.cols * im.channels();  //���� x ͨ����=ÿһ��Ԫ�صĸ���

	//˫��ѭ�����������е�����ֵ
	for (int i = 0; i < rowNumber; i++)  //��ѭ��
	{
		uchar* data = im.ptr<uchar>(i);  //��ȡ��i�е��׵�ַ
		for (int j = 0; j < colNumber; j++)   //��ѭ��
		{
			//data[j] = data[j] / div * div + div / 2;
			cout << (int)data[j] << endl;
		}  //�д������
	}

}


int main(int argc, char** argv) {
	//------------------------------------------��׼��һ��-----------------------
	Mat src;
	src = imread("C:/Users/15064/Desktop/�ر�/test.png");
	if (!src.data) {
		cout << "could not load image...\n" << endl;
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	/*
	Mat dst;

	int cols = dst.cols;//�õ�ȫ�����У�����
	int rows = dst.rows;//�õ�ȫ�����У���
	printf("rows:%d\n cols:%d\n", rows, cols);//����к���

	const uchar *firstRow = dst.ptr<uchar>(0);
	printf("first pixel value:%d\n", *firstRow);//�����һ������

	imshow("output", dst);
	*/
	print_px_value(src);


	waitKey(0);

	return 0;
}
