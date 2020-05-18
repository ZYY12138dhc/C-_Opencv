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

	//------------------------------------------��׼��һ������----------------------

	//��ɵ�ͨ��ͼ��,�Ҷ�ͼ��
	cvtColor(src, gray_src, CV_BGR2GRAY);
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", gray_src);

	//��ͨ��������
	int height = gray_src.rows;//��
	int width = gray_src.cols;//��
	for (int row = 0; row < height; row++) {//��ѭ��
		for (int col = 0; col < width; col++) {//��ѭ��
			int gray = gray_src.at<uchar>(row, col);
			gray_src.at<uchar>(row, col) = 255 - gray;
			//printf("ֵ:%d",gray);
		}
	}
	imshow("gray_invert", gray_src);//��ʾ����ͼ��

	//��ͨ��
	Mat dst;
	dst.create(src.size(), src.type());
	height = src.rows;//��
	width = src.cols;//��
	int nc = src.channels();//��ȡͨ����Ŀ
	printf("ͼƬ���ȣ�%d", height);
	printf("ͼƬ��ȣ�%d", width);
	
	

	for (int row = 0; row < height; row++) {//��ѭ��
		for (int col = 0; col < width; col++) {//��ѭ��
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
	

	
	//bitwise_not(src, dst);//�����淽��һ����ȡ����

	//imshow("output01",dst);//��ʾ����ͼ��
	imshow("output02", gray_src);//��ʾ����ͼ��
	waitKey(0);
	return 0;
}