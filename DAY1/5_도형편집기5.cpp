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
				p->draw();	
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 만들었던 도형을 복사할까요 ?? ";
			int k;
			std::cin >> k;

			// k번째 만들었던 도형의 복사본을 만들어서
			// v끝에 추가합니다.
			// 어떻게 해야 할까요 ? k번째 도형이 뭘까요 ?

			// 아래 처럼 만들면.. 새로운 도형 추가시
			// => 제어문이 한줄 추가됩니다.
			// => OCP를 만족하지 못하는 좋지 않은 디자인 입니다.
			if (k번째 도형의 타입 == Rect)
				v.push_back(new Rect);

			else if (k번째 도형의 타입 == Circle )
				v.push_back(new Circle );
		}
	}
}



