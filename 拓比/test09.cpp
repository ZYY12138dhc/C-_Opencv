#include<iostream>

using namespace std;
//图形类
//如果说一个类，拥有一个纯虚函数
//就称这个类是一个抽象类。抽象类将所有模块都隔离开 
//不管这个类中有没有成员属性，只要这个类有纯虚函数，就是一个抽象类，抽象类不能够实例化 
class Shape
{
public:
	//求图形面积的方法
	//表示图形类声明一个方法getArea(),它是一个纯虚函数，没有函数的实现。
	virtual double getArea()=0;	
	//virtual void print()=0; 
};

//正方形
//如果说一个普通类，继承拥有纯虚函数的类,如果不重写，依然是一个抽象类
//依然不能被实例化，如果想实例化，必须重写这个父类中的纯虚函数 
class  Rect:public Shape
{
public:	
	Rect(int a){
		this->a=a;
	}
	virtual double getArea(){
		cout<<"正方形求面积"<<endl; 
		return a*a;
	}
private:
	int a;//正方形边长 
};

class Circle:public Shape
{
public:
	Circle(int r)
	{
		this->r=r;
	}
	virtual double getArea(){
		cout<<"圆方形求面积"<<endl; 
		return 3.14*r*4;
	}
private:
	int r;//半径 
};
//业务层，面向抽象类编程 
 
int main(void)
{
	//直接通过抽象类定义变量是不可以的，eg: Shape s;
	//main中所有使用的变量类型，都是抽象类Shaped的类型 
	Shape *sp1 = new Rect(10);
	sp1->getArea();
	Shape *sp2 = new Circle(20);
	sp2->getArea();
	return 0;
}
