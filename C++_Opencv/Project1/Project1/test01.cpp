#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	//------------------------------------------��׼��һ��-----------------------
	Mat src, gray_src;
	src = imread("C:/Users/15064/Desktop/�ر�/test.png");
	if (!src.data) {
		cout << "could not load image...\n" << endl;
		return -1;
	}
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);
	waitKey(2);
	
	//------------------------------------------��׼��һ������----------------------

	//��ͨ��
	Mat dst;
	dst.create(src.size(), src.type());
	int height = src.rows;//��
	int width = src.cols;//��
	int nc = src.channels();//��ȡͨ����Ŀ
	printf("ͼƬ���ȣ�%d\n", height);
	printf("ͼƬ��ȣ�%d", width);

	for (int row = 0; row < height; row++) { //��ѭ��
		for (int col = 0; col < width; col++) { //��ѭ��
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