#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>

using namespace cv;
//测试用例--------------------------------------------------------------------------------------------
int main(int argc, char** argv) {
	//读取图片
	Mat src = imread("C:/Users/15064/Desktop/拓比/test.png");
	//[IMREAD_GRAYSCALE表示以灰色图像加载进来]
	//Mat src = imread("C:/Users/15064/Desktop/拓比/test.png",IMREAD_GRAYSCALE);
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	//定义显示窗口
	namedWindow("opencv setup demo", CV_WINDOW_AUTOSIZE);
	//显示图片
	imshow("opencv setup demo", src);
	//定义改变后的图像显示窗口

	namedWindow("output window", CV_WINDOW_AUTOSIZE);
	Mat output_image;
	cvtColor(src, output_image, CV_BGR2HLS);
	//[CV_BGR2GRAY]表示灰色，[CV_BGR2HLS]H表示通道，L表示亮度，S表示饱和度
	imshow("output window", output_image);

	imwrite("C:/Users/15064/Desktop/拓比/test01.png", output_image);

	waitKey(0);
	return 0;
}
