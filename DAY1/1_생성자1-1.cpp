// 1_생성자1-1.cpp
#include <iostream>

class Base
{
public:
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	// 아래 코드에서 에러를 찾아 보세요
	// 핵심 : Base 에 디폴트 생성자가 없습니다
//	Derived()	   { } // Derived() : Base() {}
//	Derived(int a) { } // Derived(int a) : Base() {}
	
	// 핵심 2. 기반 클래스에 디폴트 생성자가 없다면
	//        반드시 파생 클래스에서 기반 클래스의 다른 생성자를
	//		  명시적으로 호출해야 합니다.
	Derived()      : Base(0) { }
	Derived(int n) : Base(n) { }
	
	~Derived()     { }
};

int main()
{
	Derived d2(5);	

}
