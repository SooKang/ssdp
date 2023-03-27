#include <iostream>

class Animal
{
public:
	// static binding 
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// 가상함수 : dynamic binding 해달라는 의미
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};



class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};


int main()
{
	Animal a;
	Dog d;

	Animal* p = &d; 

//	if (사용자 입력 == 1) p = &a;

	// 아래 코드를 컴파일 할때 컴파일러는 p가 어떤 객체를 가리키는지
	// 알수 있을까 ?
	p->cry1(); // static binding    Animal cry1
	p->cry2(); // dynamic binding   Dog cry2
}







// p->cry1() 를 어느 함수로 연결할것인가 ? 함수 바인딩 개념

// 1. static binding : 컴파일러가 결정
//					   컴파일러는 p가 가리키는 곳을 조사할수 없다.
//					   컴파일러가 아는 것은 p가  "Animal*" 라는 것만!!
//					   그래서 컴파일러가 결정하면 Animal Cry() 호출
// 비논리적이지만 빠르다.
// C++/C#의 기본 정책

// 2. dynamic binding : 컴파일 할때 p가 가리키는 메모리를 조사하는
//						기계어 코드 생성
//						실행할때 메모리 조사해서 결정
//						p가 Dog를 가리키면 Dog Cry()호출
// 논리적이지만 느리다.
// java, python, kotlin 등의 언어가 채택
// C++/C#의 virtual function

