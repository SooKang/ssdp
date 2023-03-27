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




int main()
{
//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)

	People p1("kim", 30);
}




