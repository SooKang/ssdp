#include <iostream>
#include <vector>

// 핵심 1. 모든 도형을 타입으로 설계하면 편리하다.

// 핵심 2. 모든 도형의 공통의 기반 클래스가 있다면 
//         모든 도형을 하나의 컨테이너에 묶어서 관리할수 있다.

class Shape
{
};
class Rect : public Shape
{
	// x, y, w, h, 생성자 등은 생략
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};
int main()
{
	std::vector<Shape*> v;
//	std::vector<Circle*> v1;
}



