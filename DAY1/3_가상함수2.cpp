#include <iostream>

// 핵심 : 기반 클래스로 사용되는 모든 클래스는
//		  반드시 소멸자를 가상함수로 해야 합니다.
//       

class Base
{
public:
//	~Base() {}
	virtual ~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	//Derived d;

//	Derived* p = new Derived;
//	delete p;

	Base* p = new Derived;
	delete p; // 이순간 소멸자를 호출해야 하는데.. 원리를생각해 봅시다.

	// 1. 소멸자도 함수이므로 static binding 할지 dynamic binding할지
	//    결정해야 합니다.

	// 2. 컴파일러가 Base 클래스를 소멸자를 보고 결정
}	





