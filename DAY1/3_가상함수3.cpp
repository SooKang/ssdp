// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 핵심 1. 가상함수 재정의시는 virtual 이 있어도 되고 없어도 됩니다
	// virtual void foo() {}


	// 핵심 2. 가상함수 재정의시 실수(오타)가 있어도 에러가 아닙니다
	// => 버그의 원인
//	virtual void fooo() {}
//	virtual void goo(double){}


	// 핵심 3. 가상 함수 재정의시 꼭 override 붙이세요 - C++11 문법
	virtual void fooo()      override {}
	virtual void goo(double) override {}

};

int main()
{
}





