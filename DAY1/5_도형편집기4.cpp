#include <iostream>
#include <vector>

// 5. 다형성(가상함수 기반의 코드)는 OCP를 만족하는 좋은 코딩 스타일 입니다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void setColor(int c) { color = c; }
	virtual int getArea() { return -1; }


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

class Triangle : public Shape
{
public:
	void draw()  override { std::cout << "draw triangle" << std::endl; }
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
				p->draw();	// 다형성(polymorphism)
							// => 동일한 표현식이 상황(객체)에 따라
							//	  다르게 동작하는 것

			// 객체지향의 3대 특징 : 캡슐화, 상속, 다형성
		}
	}
}



