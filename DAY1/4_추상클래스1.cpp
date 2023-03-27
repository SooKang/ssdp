// 1_추상클래스1.cpp - 10page

// 추상클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체 생성이 안됨
// 의도 : 특정 이름의 함수를 반드시 만들라고 지시 하는 것
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)
							 // 구현이 없고, "=0" 으로 표기							 
};
class Rect : public Shape
{
	// 핵심 : Draw()의 구현부를 제공하지 않으면 Rect 도 추상이다.
	// Rect를 사용할수 있게 하려면 반드시 "Draw()"를 만들어야 한다!
public:
	void Draw() override {}
};
int main()
{
	Shape  s; // error
	Shape* p; // ok. 
	Rect  r;
}
