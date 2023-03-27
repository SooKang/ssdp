#include <iostream>
#include <vector>

struct NotImplemented {};


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void setColor(int c) { color = c; }





public:
	virtual void draw() final  // final : 재정의하면 error
	{
		std::cout << "mutex lock" << std::endl;
		drawImp();
		std::cout << "mutex unlock" << std::endl;
	}
	// 가상함수     : 파생 클래스가 override 안하면 기본 구현 제공하겠다는 것
	// 순수가상함수 : 파생 클래스가 반드시 구현해야 한다고 지시하는 것
protected:
	virtual void drawImp() = 0;

public:
	// clone() 
	// 1. 순수가상함수도 좋습니다.
	// 2. 아래 처럼 하는 경우도 있습니다.
	// => clone()을 override 하지 않고, 사용도 안하면 ok
	// => clone()을 override 하지 않고, 사용하면 예외 발생
	// => clone()을 override 했으면 사용가능
	virtual Shape* clone() 
	{
		throw NotImplemented();
	}

	// 아래 처럼하는 의도는
	// => 혹시 getArea() 호출해서 -1 나오면 
	//    "면적을 구할수 없다" 라고 생각하라는 것!!
	virtual int getArea() { return -1; }
};





class Rect : public Shape
{
public:
	void drawImp() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		return new Rect(*this);
	}
};



class Circle : public Shape
{
public:
	void drawImp()  override { std::cout << "draw circle" << std::endl; }

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

			v.push_back(v[k]->clone());

		}
	}
}



