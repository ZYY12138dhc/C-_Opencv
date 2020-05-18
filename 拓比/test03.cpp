
/*

【简介】

	Virtual是C++ OO机制中很重要的一个关键字。只要是学过C++的人都知道在类Base中加了Virtual关键字的函数

就是虚拟函数（例如函数print），于是在Base的派生类Derived中就可以通过重写虚拟函数来实现对基类虚拟函数的覆盖。

	当基类Base的指针point指向派生类Derived的对象时，

对point的print函数的调用实际上是调用了Derived的print函数而不是Base的print函数。

	这是面向对象中的多态性的体现。

	（关于虚拟机制是如何实现的，参见Inside the C++ Object Model ，Addison Wesley 1996）

*/

#include <iostream>

 

class Base

{

public:

	Base()		{}

 

public:

	virtual void FuncPrint()//加了Virtual关键字的函数就是虚拟函数

	{

		std::cout << "base";

	}

};

 

class Derived:public Base 

{

public:

	Derived()	{}

 

public:

	void print()	

	{

		std::cout << "Derived";

	}

};

 

/* 

 输出：

 Derived

*/

 

/*

这也许会让人联想到函数的重载，但稍加比对就会发现两者是完全不同的：

	1）重载的几个函数必须在一个类中；

	覆盖的函数必须在有继承关系的不同的类中

	2）覆盖的几个函数必须函数名、参数、返回值都相同

	重载的函数必须函数名相同，参数不同。

	参数不同的目的就是为了在函数调用的时候编译通过参数判断出程序在调用哪个函数。

	3）覆盖的函数前必须加关键字Virtual；

	重载和virtual没有任何瓜葛，加不加都不影响重载的运作。



	关于C++的隐藏规则：

	我曾经听说C++的隐藏规则

	*/

 

 

 

// 阿里巴巴笔试题

class ClassA

{

public:

	virtual ~ClassA()

	{

	}

 

	virtual void FunctionA()

	{

	}

};

 

class ClassB

{

public:

	virtual void Function()

	{

	}

};

 

class ClassC: public ClassA, public ClassB

{

public:

};

 

ClassC aObject;

ClassA *pA = &aObject;

ClassB *pB = &aObject;

ClassC *pC = &aObject;

 

假设定义了 ClassA* pA2，下面正确的代码是：

A	pA2 = static_cast<ClassA*>(pB);			// 类型转换无效

B	void* pVoid = static_cast<void*>(pB);	// 正确

	pA2 = static_cast<ClassA*>(pVoid)		

C   pA2 = pB								// 类型转换无效

D   pA2 = static_cast<ClassA*>( static_cast<ClassA*>(pB) );		// 转换有效

