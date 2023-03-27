//생성자1.cpp - 3page
#include <iostream>

// 핵심 : 상속에서의 생성자 호출의 원리!
// => 컴파일러가 아래 처럼 코드를 추가해 주는것 

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
