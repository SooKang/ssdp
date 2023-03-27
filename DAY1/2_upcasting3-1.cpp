#include <iostream>
class Animal
{
public:
	int age;

	virtual ~Animal() {}
};


class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};

void NewYear(Animal* p) 
{
	++(p->age);
}

void NewYear(Dog* p)
{
	// 공통의 작업 수행후
	NewYear(static_cast<Animal*>(p) );

	// dog 전용 작업 수행
	p->color = 10;
}



int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











