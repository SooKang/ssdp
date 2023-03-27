#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void setColor(int c) { color = c; }
	virtual int getArea() { return -1; }

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	// 자신의 복사본 객체를 만드는 가상함수는 아주 유용하고
	// 널리 사용됩니다.
	virtual Shape* clone()
	{
		Shape* p = new Shape;
		p->color = color; // 자신의 모든 멤버를 복사 합니다.
		return p;
	}
};





class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		return new Rect(*this);
	}
};



class Circle : public Shape
{
public:
	void draw()  override { std::cout << "draw circle" << std::endl; }

	Shape* clone() override
	{
		return new Circle(*this);
	}
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

		else if (cmd == 8)
		{
			std::cout << "몇번째 만들었던 도형을 복사할까요 ?? ";
			int k;
			std::cin >> k;

			// k번째 도형의 타입을 조사할필요 없습니다.
			v.push_back( v[k]->clone() ); // 다형성!!
									// 새로운 도형이 추가되어도
									// 코드 수정 안됨.
		}
	}
}



