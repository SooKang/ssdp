#include <iostream>
#include <vector>

// 핵심 3. 모든 파생클래스(도형)의 공통의 특징은 반드시 기반클래스(shape)
//         에도 있어야 한다.
//         문법적인 규칙이 아닌 디자인 적인 면에서!!

// 핵심 4. 기반 클래스 멤버 함수중 파생 클래스가 재정의 하게 되는것은
//		   반드시 가상함수 이어야 한다.

class Shape
{
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw()  override { std::cout << "draw circle" << std::endl; }
};
int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)	
				p->draw(); 
		}
	}
}



