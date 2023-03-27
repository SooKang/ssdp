#include <iostream>


// 카메라를 먼저 만들지 말고
// 카메라와 사용자 사이에 지켜야 하는 규칙을 먼저 설계 한다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};







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
	void useCamera(Camera* p) { p->Take(); }
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





