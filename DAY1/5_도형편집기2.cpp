#include <iostream>
#include <vector>

class Shape
{
};
class Rect : public Shape
{
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

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)		// p 는 Shape* 인데
				p->draw(); // error, Shape 에는 draw()가 없다
		}
	}
}
// 위 코드는 왜?? 에러일까요 ?
// 해결책은 뭘까요??
// 1. p 를 Shape* 가 아닌 Rect 나 Circle로 캐스팅하자.
// 2. Shape에도 draw 를 만들자


