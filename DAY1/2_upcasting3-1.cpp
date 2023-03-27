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

	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}



int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











