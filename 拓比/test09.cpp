#include<iostream>

using namespace std;
//ͼ����
//���˵һ���࣬ӵ��һ�����麯��
//�ͳ��������һ�������ࡣ�����ཫ����ģ�鶼���뿪 
//�������������û�г�Ա���ԣ�ֻҪ������д��麯��������һ�������࣬�����಻�ܹ�ʵ���� 
class Shape
{
public:
	//��ͼ������ķ���
	//��ʾͼ��������һ������getArea(),����һ�����麯����û�к�����ʵ�֡�
	virtual double getArea()=0;	
	//virtual void print()=0; 
};

//������
//���˵һ����ͨ�࣬�̳�ӵ�д��麯������,�������д����Ȼ��һ��������
//��Ȼ���ܱ�ʵ�����������ʵ������������д��������еĴ��麯�� 
class  Rect:public Shape
{
public:	
	Rect(int a){
		this->a=a;
	}
	virtual double getArea(){
		cout<<"�����������"<<endl; 
		return a*a;
	}
private:
	int a;//�����α߳� 
};

class Circle:public Shape
{
public:
	Circle(int r)
	{
		this->r=r;
	}
	virtual double getArea(){
		cout<<"Բ���������"<<endl; 
		return 3.14*r*4;
	}
private:
	int r;//�뾶 
};
//ҵ��㣬����������� 
 
int main(void)
{
	//ֱ��ͨ�������ඨ������ǲ����Եģ�eg: Shape s;
	//main������ʹ�õı������ͣ����ǳ�����Shaped������ 
	Shape *sp1 = new Rect(10);
	sp1->getArea();
	Shape *sp2 = new Circle(20);
	sp2->getArea();
	return 0;
}
