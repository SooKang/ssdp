#include <iostream>


// 카메라를 먼저 만들지 말고
// 카메라와 사용자 사이에 지켜야 하는 규칙을 먼저 설계 한다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};


// 진짜 카메라는 없지만 규칙이 있으므로
// 사용자는 규칙대로만 사용하면 됩니다.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

// 모든 카메라는 규칙을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc); // ??

}





