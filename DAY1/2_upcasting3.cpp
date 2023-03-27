// github.com/codenuri/ssdp
#include <iostream>
// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};
// upcasting 활용 2. 동종을 처리하는 함수 만들기
//void NewYear(Dog* pDog)  // Dog 만 전달 가능한 함수
void NewYear(Animal* p) // 모든 동물을 인자로 받을수있는함수
{
	++(p->age);

	// 세월이 지나서 요구사항이 추가 되었다.
	// p가 Dog를 가리키면 color 도 변경
	// p->color = 10; // error

	// static_cast : 컴파일 시간 캐스팅
	//				 p가 가리키는 곳이 Dog 인지 조사할수 없다
	//				 p가 어떤 객체를 가리키는지는 컴파일 시간에 모른다
	// Dog* pDog = static_cast<Dog*>(p);

	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p가 가리키는 곳이 Dog인지 조사후 캐스팅
	//				  Dog가 아니면 0 반환
	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}


int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











