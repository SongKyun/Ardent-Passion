#include <iostream>
using namespace std;

class AAA
{
public:
	AAA()
	{
		cout << "emptry object" << endl; // 객체 생성 시 생성자 호출 확인을 위한 삽입문
	}
	void ShowYourName()
	{
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref; // 참조자가 멤버변수로 선언되었다. 따라서 이니셜라이저로 초기화 해야한다.
	const int& num; // const 참조자 선언 따라서 이니셜라이저로 정수형 상수로 초기화 가능.

public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n)
	{ // empty constructor body
	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;
	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}