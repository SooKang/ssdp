// protected 생성자를 만드는 이유
// => 자신은 객체를 생성할수 없지만( 추상적인 개념 )
// => 파생 클래스의 객체는 생성할수 있게( 구체적인 개념 )

// 디자인 패턴에서 "추상(abstract)"의 반대말은 "구체(concrete)"입니다.

class Animal
{
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
//	Animal a; // error
	Dog    d; // ok
}



