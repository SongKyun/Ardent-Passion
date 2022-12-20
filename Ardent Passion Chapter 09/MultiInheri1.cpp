#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFuncOne() {	cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:
	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo // 콤마(쉼표)를 이용해서 상속의 대상이 되는 클래스를 구분해서 명시할 수 있다. 기초 클래스를 상속하는 형태는 각각 별도로 지정이 가능하다.
{
public:
	void ComplexFunc()
	{
		//BaseOne 클래스의 멤버함수와 BaseTwo 클래스의 멤버함수를 각각 호출하고 있다 다중상속을 했기 때문에 가능한 일이다.
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main()
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}