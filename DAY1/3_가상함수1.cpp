#include <iostream>

class Animal
{
public:
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 
};

int main()
{
	Animal a;
	Dog d;

	Animal* p = &d; 

	if (사용자 입력 == 1) p = &a;

	// 아래 코드를 컴파일 할때 컴파일러는 p가 어떤 객체를 가리키는지
	// 알수 있을까 ?
	p->cry1();
}


// p->cry1() 를 어느 함수로 연결할것인가 ? 함수 바인딩 개념

// 1. static binding : 컴파일러가 결정

// 2. dynamic binding : 실행할때 메모리 조사해서 결정


