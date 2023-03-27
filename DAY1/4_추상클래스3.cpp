#include <iostream>

// 강한결합(tightly coupling)
// => 클래스 이름을 직접 사용하는 것
// => 교체 불가능한 경직된 디자인


// 약한결합(loosely coupling)
// => 클래스 이름을 직접 사용하지 않고, 
//    규칙을 담은 인터페이스(추상 클래스)를 통해서 사용하는것
// 
// => 교체 가능한 유연한 디자인



// 인터페이스 : 지켜야하는 규칙만 있는것
// 추상클래스 : 지켜야하는 규칙 + 다른 멤버도 있는 경우

// java, C# 은 "interface"라는 키워드 존재하지만, C++은 없습니다.





// 카메라를 먼저 만들지 말고
// 카메라와 사용자 사이에 지켜야 하는 규칙을 먼저 설계 한다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다. 라고 하지말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다."  라고 표현

// 아주 옛날에는 아래 처럼도 했습니다.
#define interface struct
//interface ICamera

struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}   // 인터페이스는 결국 기반 클래스이므로
							// 가상 소멸자 필요
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

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take 8K Picture" << std::endl; }
};


int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc); 

	UHDCamera uhc;
	p.useCamera(&uhc);

}





