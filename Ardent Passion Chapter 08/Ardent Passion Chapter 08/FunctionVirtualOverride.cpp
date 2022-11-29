#include <iostream>
using namespace std;

class First
{
public:
	// virtual 로 선언되었으니 다른 함수에는 추가 안 해도 가상함수가 된다. 그러나 이렇게 선언을 넣어서 함수가 가상함수임을 알리는 것이 좋다.
	virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main()
{
	// Third 객체를 생성한 다음, Third형, Second형, 그리고 First형 포인터 변수로 이를 참조하고 있다.
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	// 각 포인터 형 변수를 이용해서 MyFunc 함수를 호출하고 있다.
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}

// 총 3개의 클래스가 상속관계로 연결되어 있으며, 이들은 모두 MyFunc 함수를 통해서 오버라이딩 관계를 형성하고 있다.
