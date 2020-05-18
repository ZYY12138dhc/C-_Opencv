#include<iostream>
class A //长度x,y
{ 
	public:
		double x,y;
		A(double px=1,double py=1):x(px),y(py){ }
		virtual ~A( ){ }
		void show( ){std::cout<<"[A ]=>"<<x<<","<<y<<std::endl;}
};
class B1: virtual public A //矩形面积
{ 
	public:
		B1(double px=2, double py=2):A(px,py){ }
		void show(){std::cout<<"[B1]=>"<<x*y<<std::endl;}
};
class B2: virtual public A //梯形面积
{ 
	public:
		double z;
		B2(double px=3, double py=3, double pz=3):A(px,py),z(pz){}
		void show(){std::cout<<"[B2]=>"<<0.5*(x+y)*z<<std::endl;}
};
class C: public B1, public B2 //体积
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
对于这个问题来来说，类B1和B2都继承于类A，因此在B1和B2中都有A的数据成员及成员函数，
而类C又继承于类B1和B2，若自没有virtual关键字，类C中将有两份A的数据成员zhidao及成
员函数，这就产生了二义性，加上virtual关键字即可解决这个问题 。

C当然继承了A， B1, B2。如果不用virtual，在类C的show函数中，在输出x,y的时候就不知
道输出A类中的x,y还是B类中的x,y，因此引起歧义。继承关系是不变的。 
*/
