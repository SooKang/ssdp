// github.com / codenuri / ssdp 에서 "DAY1.zip" 받아두세요

//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	Derived()		{ std::cout << "Derived()" << std::endl; }
	Derived(int a)	{ std::cout << "Derived(int)" << std::endl; }
	~Derived()		{ std::cout << "~Derived()" << std::endl; }
};
int main()
{
//	Derived d1;
	Derived d2(5);

}

// 1. DAY1.zip 압축 풀러 보세요
// 
// 2. DAY1.sln 파일 더블클릭해서 VS 에서 열어 보세요

// 3. 버전 변경 
//    => 프로젝트 메뉴 선택후
//    => DAY1 속성 메뉴 선택
//       ( 플랫폼 도구집합 버전과 Windows SDK 버전 변경)

// 4. 확인 : Control + F5 키 로 빌드

// 5. 소스를 빌드에 포함/제거하는 방법
