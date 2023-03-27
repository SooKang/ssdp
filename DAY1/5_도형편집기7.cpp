#include <iostream>
#include <vector>

// 핵심 9. template method 패턴
// => 기반 클래스가 변하지 않은 공통의 흐름을 담은 함수제공(public, final)
// => 변해야 하는 것만 가상함수로 분리해서(private)
// => 파생 클래스가 변하는 것을 바꿀수 있는 기회 제공



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void setColor(int c) { color = c; }
	virtual int getArea() { return -1; }

	// 핵심 : 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 숨은 변해야 하는 코드는 분리되어야한다.
	// => 변하는 것을 가상함수로!!
protected:
	virtual void drawImp()
	{
		std::cout << "draw shape" << std::endl; 
	}

public:
	virtual void draw() final  // final : 재정의하면 error
	{
		std::cout << "mutex lock" << std::endl;		
		drawImp();
		std::cout << "mutex unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		Shape* p = new Shape;
		p->color = color; 
		return p;
	}
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



