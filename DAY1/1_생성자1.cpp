//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	// 사용자 코드		// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base() 
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base()
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// ~Base();		// 기반 클래스 소멸자 호출하는 코드를 컴파일러가추가
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);	// call Derived::Derived(int)

}
