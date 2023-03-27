class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;

	Dog* p1 = &d;	// ok
	
//	int* p2 = &d;	// error
	
	// 핵심 1. 기반 클래스 포인터(참조)로 파생 클래스 객체의 주소를 
	//         담을수 있다
	Animal* p3 = &d; // ok. 


	// 핵심 2. 하지만 Animal* 로는 Animal 로 부터 상속된 멤버만 사용가능
	//         Dog 고유 멤버는 접근 안됨
	// 이유 : 컴파일 시간에 컴파일러는 포인터 타입으로 
	//        해당 멤버가 있는지 확인하므로
	//       "static type check"
	p3->age = 10;   // ok
	p3->color = 10; // error


	// 핵심 3. p3로 Dog 고유 멤버에 접근하려면 캐스팅해야 합니다.
	// 단, 이경우 p3가 가리키는 곳이 Dog 라는 확신이 있어야 합니다.
	// 만약 Dog가 아니면 잘못된 메모리 접근으로 runtime error 가능성있음
	static_cast<Dog*>(p3)->color = 10;
	
	// 참고 : p3가 가리키는 곳이 어떤 타입의 객체인지 조사할수 없나요 ?
	// => dynamic_cast로 조사 가능한데..
	// => 조사하는 코드가 나오면 나쁜 디자인 입니다.
}











