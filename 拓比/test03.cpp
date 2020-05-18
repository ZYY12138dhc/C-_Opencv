
/*

����顿

	Virtual��C++ OO�����к���Ҫ��һ���ؼ��֡�ֻҪ��ѧ��C++���˶�֪������Base�м���Virtual�ؼ��ֵĺ���

�������⺯�������纯��print����������Base��������Derived�оͿ���ͨ����д���⺯����ʵ�ֶԻ������⺯���ĸ��ǡ�

	������Base��ָ��pointָ��������Derived�Ķ���ʱ��

��point��print�����ĵ���ʵ�����ǵ�����Derived��print����������Base��print������

	������������еĶ�̬�Ե����֡�

	������������������ʵ�ֵģ��μ�Inside the C++ Object Model ��Addison Wesley 1996��

*/

#include <iostream>

 

class Base

{

public:

	Base()		{}

 

public:

	virtual void FuncPrint()//����Virtual�ؼ��ֵĺ����������⺯��

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

 �����

 Derived

*/

 

/*

��Ҳ����������뵽���������أ����ԼӱȶԾͻᷢ����������ȫ��ͬ�ģ�

	1�����صļ�������������һ�����У�

	���ǵĺ����������м̳й�ϵ�Ĳ�ͬ������

	2�����ǵļ����������뺯����������������ֵ����ͬ

	���صĺ������뺯������ͬ��������ͬ��

	������ͬ��Ŀ�ľ���Ϊ���ں������õ�ʱ�����ͨ�������жϳ������ڵ����ĸ�������

	3�����ǵĺ���ǰ����ӹؼ���Virtual��

	���غ�virtualû���κιϸ𣬼Ӳ��Ӷ���Ӱ�����ص�������



	����C++�����ع���

	��������˵C++�����ع���

	*/

 

 

 

// ����Ͱͱ�����

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

 

���趨���� ClassA* pA2��������ȷ�Ĵ����ǣ�

A	pA2 = static_cast<ClassA*>(pB);			// ����ת����Ч

B	void* pVoid = static_cast<void*>(pB);	// ��ȷ

	pA2 = static_cast<ClassA*>(pVoid)		

C   pA2 = pB								// ����ת����Ч

D   pA2 = static_cast<ClassA*>( static_cast<ClassA*>(pB) );		// ת����Ч

