//一个完整的示例：
//纯虚函数由派生自Abstract类的类实现。以下是演示相同的简单示例。
#include<iostream> 
using namespace std; 
class Base 
{ 
	int x; 
	public: 
		virtual void fun() = 0; 
		int getX() { return x; } 
}; 
// This class inherits from Base and implements fun() 
class Derived: public Base 
{ 
	int y; 
	public: 
		void fun() { cout << "fun() called"; } 
}; 
int main(void) 
{ 
	Derived d; 
	d.fun(); 
	return 0; 
} 
