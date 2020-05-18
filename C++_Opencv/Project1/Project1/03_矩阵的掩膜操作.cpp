//03_�������Ĥ����

#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("C:/Users/15064/Desktop/�ر�/test.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	/*
	//��ȡͼ��Ŀ��
	int cols = src.cols * src.channels();//channels()ͼ��ͨ����
	int offsetx = src.channels();
	//��ȡͼ��ĸ߶�
	int rows = src.rows;
	//��ͼ���ʼ�����Ͷ�ȡ��ͼ���С������һ�£��ڱ����հ�ͼ��
	dst = Mat::zeros(src.size(),src.type());
	for (int row = 1; row < (rows - 1); row++) {
		//��ȡ��ǰ������ֵ
		const uchar* previous = src.ptr<uchar>(row - 1);//����
		const uchar* current = src.ptr<uchar>(row);//����
		const uchar* next = src.ptr<uchar>(row + 1);//����
		uchar *output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[col]));
		}
	}
	*/

	//opencv�к��������һ�µļ�෽��,ͨ��filter2D[API]��ʵ��
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernel);//src.depth()�ɸĳ�-1�������ܲ���


	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	waitKey(0);
	return 0;
}