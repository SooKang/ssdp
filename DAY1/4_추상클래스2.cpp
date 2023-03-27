//1_추상클래스2.cpp
#include <iostream>

// OCP
// 기능확장에 열려있고(Open, 나중에 클래스가 추가되어도)
// 코드수정에 닫혀있어야(Close, 기존 코드는 수정되지 않도록)
// 만들라는 이론(Principle)

// 개방 폐쇄의 법칙(Open Close Principle)

// 객체지향 설계의 5개 원칙 : SRP, OCP, LSP, ISP, DIP
//							SOLID



class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void useCamera(Camera* p)   { p->Take(); }
	void useCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc); // ??

}





