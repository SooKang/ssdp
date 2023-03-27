// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting 활용 1. 동종을 보관하는 컨테이너 만들기
	//					 => 동일 기반 클래스를 사용하는 타입.
	std::vector<Dog*>    v1; // Dog 객체만 보관 가능한 컨테이너
	std::vector<Animal*> v2; // 모든 동물을 보관하는 컨테이너
}
