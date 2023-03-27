// 1_생성자2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& name, int age)
		: name(name), age(age) {}
};

// People 부터 상속받은 "Student" 만들어 보세요
// => 학번(int id) 추가해 보세요
// => 생성자로 초기화 해보세요. 
// => main 함수에서 Student 객체 만들어 보세요

class Student : public People
{
	int id;
public:
	// 아래 처럼 하면 안됩니다.
	// Student(int id) : id(id)  // Student(int id) :People(),  id(id) 
	// {}

	// People 에 디폴트 생성자가 없으므로
	// 반드시 명시적으로 호출해야 합니다.
	Student(const std::string& name, int age, int id) 
		: People(name, age), id(id)
	{
	}
};

int main()
{
	Student s("kim", 30, 15);

//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	People p1("kim", 30);
}




