#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main()
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj; // obj는 Second를 상속하는 Third 객체이므로, Second형 참조자로 참조가 가능하다.
	sref.FirstFunc(); // 컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단하기 때문에
	sref.SecondFunc(); // First 클래스에 정의된 FirstFunc 함수와 Second 클래스에 정의된 SecondFunc 함수는 호출이 가능하지만, Third 클래스에 정의된 ThirdFunc 함수는 호출이 불가능하다.
	sref.SimpleFunc(); //  SimpleFunc 함수는 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수가 호출된다.

	First& fref = obj; // obj 는 First를 간접 상속하는 Third 객체이므로, First 형 참조자로 참조가 가능하다.
	fref.FirstFunc(); //  컴파일러는 참조자의 자료형을 가지고 함수의 호출 가능성을 판단하기 때문에 First 클래스에 정의된 함수만 호출 가능하다.
	fref.SimpleFunc(); // 그런데 이 중에서 SimpleFunc는 가상함수이므로, Third 클래스에 정의된 SimpleFunc 함수가 호출된다.
	return 0;
}