//eg.1
//��������������Ͷ�����һ�� vector������ 6 ��Ԫ�أ�Ȼ���ӡ����Ԫ�أ�
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
		cout << vecTemp[i] <<" "; // �����0 1 2 3 4 5

	return 0;
}


//eg.2
//��������������һ���������͵� deque����������β������ 6 ��Ԫ�أ�����ӡ������Ԫ�ء�

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char* argv[])
{
	deque<float> dequeTemp;

	for (int i = 0; i<6; i++)
		dequeTemp.push_back(i);

	for (int i = 0; i<dequeTemp.size(); i++)
		cout << dequeTemp[i] << " "; // �����0 1 2 3 4 5

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

//�����κ�ת�����ж�ȡ

cv::Mat matUnchanged = cv::imread("./test01.png", cv::IMREAD_UNCHANGED);	cv::imshow("UNCHANGED", matUnchanged);

 

//��ɫģʽ���ж�ȡ	

cv::Mat matColor = cv::imread("./test01.png", cv::IMREAD_COLOR);	cv::imshow("COLOR", matColor);

 

//�Ҷ�ģʽ���ж�ȡ

cv::Mat matGrayScale = cv::imread("./test01.png", cv::IMREAD_GRAYSCALE);

cv::imshow("GRAYSCALE", matGrayScale);
*/
