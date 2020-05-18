#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>

using namespace cv;
//��������--------------------------------------------------------------------------------------------
int main(int argc, char** argv) {
	//��ȡͼƬ
	Mat src = imread("C:/Users/15064/Desktop/�ر�/test.png");
	//[IMREAD_GRAYSCALE��ʾ�Ի�ɫͼ����ؽ���]
	//Mat src = imread("C:/Users/15064/Desktop/�ر�/test.png",IMREAD_GRAYSCALE);
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	//������ʾ����
	namedWindow("opencv setup demo", CV_WINDOW_AUTOSIZE);
	//��ʾͼƬ
	imshow("opencv setup demo", src);
	//����ı���ͼ����ʾ����

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	Mat output_image;
	cvtColor(src, output_image, CV_BGR2HLS);
	//[CV_BGR2GRAY]��ʾ��ɫ��[CV_BGR2HLS]H��ʾͨ����L��ʾ���ȣ�S��ʾ���Ͷ�
	imshow("output window", output_image);

	imwrite("C:/Users/15064/Desktop/�ر�/test01.png", output_image);

	waitKey(0);
	return 0;
}
