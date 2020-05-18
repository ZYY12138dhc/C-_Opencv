#include<iostream>
class A //����x,y
{ 
	public:
		double x,y;
		A(double px=1,double py=1):x(px),y(py){ }
		virtual ~A( ){ }
		void show( ){std::cout<<"[A ]=>"<<x<<","<<y<<std::endl;}
};
class B1: virtual public A //�������
{ 
	public:
		B1(double px=2, double py=2):A(px,py){ }
		void show(){std::cout<<"[B1]=>"<<x*y<<std::endl;}
};
class B2: virtual public A //�������
{ 
	public:
		double z;
		B2(double px=3, double py=3, double pz=3):A(px,py),z(pz){}
		void show(){std::cout<<"[B2]=>"<<0.5*(x+y)*z<<std::endl;}
};
class C: public B1, public B2 //���
{ 
	public:
		double h;
		C(double px=4,double py=4,double pz=4,double ph=4):B2(px,py,pz),h(ph){}
		void show(){std::cout<<"[C ]=>"<<x<<","<<y<<"/"<<x*y*h<<"/"<<0.5*(x+y)*z*h<<std::endl;}
};
 int main(void)
{ 
	A a; B1 b1; B2 b2; C c;
	A* p=&a; p->show( );
	p=&b1; p->show( );
	p=&b2; p->show( );
	p=&c; p->show( );
	return 0;
}


/*
���������������˵����B1��B2���̳�����A�������B1��B2�ж���A�����ݳ�Ա����Ա������
����C�ּ̳�����B1��B2������û��virtual�ؼ��֣���C�н�������A�����ݳ�Աzhidao����
Ա��������Ͳ����˶����ԣ�����virtual�ؼ��ּ��ɽ��������� ��

C��Ȼ�̳���A�� B1, B2���������virtual������C��show�����У������x,y��ʱ��Ͳ�֪
�����A���е�x,y����B���е�x,y������������塣�̳й�ϵ�ǲ���ġ� 
*/
