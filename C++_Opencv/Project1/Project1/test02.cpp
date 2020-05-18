#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
#include<math.h>
 

using namespace std;
using namespace cv;
 
Mat src, gray_src, drawImg;
int threshold_v = 170;
int threshold_max = 255;
const char* output_win = "rectangle-demo";
RNG rng(12345);

void Contours_Callback(int,void*);

int main(int argc, char** argv) {
	src = imread("C:/Users/15064/Desktop/拓比/test.png");
	if(!src.data) {
		cout << "could not load image...\n" << endl;
		return -1;
	}
	cvtColor(src, gray_src, CV_BGR2GRAY);
	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1));//均值模糊

	const char* source_win = "input image";
	namedWindow(source_win, CV_WINDOW_AUTOSIZE);
	namedWindow(output_win, CV_WINDOW_AUTOSIZE);
	imshow(source_win, src);

	createTrackbar("Threshold Value:", output_win, &threshold_v, threshold_max, Contours_Callback);//触动一个滑块
	Contours_Callback(0, 0);

	waitKey(0);
	return 0;
}
void Contours_Callback(int,void*) {
	//------------------------找出白色区域-------------------------
	Mat binary_output;
	vector<vector<Point>>contours;
	vector<Vec4i>hierachy;

	threshold(gray_src, binary_output, threshold_v, threshold_max, THRESH_BINARY);
	imshow("binary image", binary_output);
	findContours(binary_output, contours, hierachy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(-1, -1));
	
	//-------------------------------------------------------------------------

	//初始化条件
	vector<vector<Point>>contours_ploy(contours.size());//找出外接多边形
	vector<Rect>ploy_rects(contours.size());//找出最小矩形
	vector<Point2f>ccs(contours.size());
	vector<float>radius(contours.size());//找圆的半径

	vector<RotatedRect>minRects(contours.size());
	vector<RotatedRect>mycllipse(contours.size());


	for (size_t i = 0; i < contours.size(); i++) {
		approxPolyDP(Mat(contours[i]), contours_ploy[i], 3,true);
		ploy_rects[i] = boundingRect(contours_ploy[i]);
		minEnclosingCircle(contours_ploy[i], ccs[i], radius[i]);
		//检测是否五个点
		if (contours_ploy[i].size() > 5) {
		mycllipse[i] = fitEllipse(contours_ploy[i]);
		minRects[i] = minAreaRect(contours_ploy[i]);

		}

	}
	//绘制
	src.copyTo(drawImg);
	Point2f pts[4];
	for (size_t t = 0;t<contours.size();t++ ){
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//rectangle(drawImg, ploy_rects[t], color, 2, 8);
		//circle(drawImg, ccs[t], radius[t], color, 2, 8);
		if (contours_ploy[t].size() > 5) {
			ellipse(drawImg, mycllipse[t], color, 1, 8);
			minRects[t].points(pts);
			for (int r = 0; r < 4; r++) {
				line(drawImg, pts[r], pts[(r + 1) % 4], color, 1, 8);
				}

		}
	}
	imshow(output_win, drawImg);
	imwrite("C:/Users/15064/Desktop/拓比/test02.png", drawImg);
	return;
}