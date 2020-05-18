//eg.1
//以下例子针对整型定义了一个 vector，插入 6 个元素，然后打印所有元素：
/*
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> vecTemp;

	for (int i = 0; i<6; i++)
		vecTemp.push_back(i);

	for (int i = 0; i<vecTemp.size(); i++)
		cout << vecTemp[i] <<" "; // 输出：0 1 2 3 4 5

	return 0;
}


//eg.2
//以下例子声明了一个浮点类型的 deque，并在容器尾部插入 6 个元素，最后打印出所有元素。

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char* argv[])
{
	deque<float> dequeTemp;

	for (int i = 0; i<6; i++)
		dequeTemp.push_back(i);

	for (int i = 0; i<dequeTemp.size(); i++)
		cout << dequeTemp[i] << " "; // 输出：0 1 2 3 4 5

	return 0;
}

*/

//eg.3
#include <iostream>
#include<String>
class A
{
	public:
		A(){};
		virtual ~A(){};
		//virtual void init(const std::string& str,int a,const int& b,int& c)const = 0;
	public:
		virtual void print() const=0;	
};

class B:public A
{
	public:
		B(){};
		virtual ~B(){};
		//void init(const std::string& str,int a,const int& b,int& c)const ;
		virtual void print() const{std::cout<<"B"<<std::endl;}	
};

int main(void)
{
	//A a;
	B b;
	
	A *pA = NULL;
	A *pA1 = new B();
	pA->print();
	pA1->print();
	return 0;
	
}

/*
//eg.4

#include "cv.h"
#include "highgui.h"

//不做任何转化进行读取

cv::Mat matUnchanged = cv::imread("./test01.png", cv::IMREAD_UNCHANGED);	cv::imshow("UNCHANGED", matUnchanged);

 

//彩色模式进行读取	

cv::Mat matColor = cv::imread("./test01.png", cv::IMREAD_COLOR);	cv::imshow("COLOR", matColor);

 

//灰度模式进行读取

cv::Mat matGrayScale = cv::imread("./test01.png", cv::IMREAD_GRAYSCALE);

cv::imshow("GRAYSCALE", matGrayScale);
*/
