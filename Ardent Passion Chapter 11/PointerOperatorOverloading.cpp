#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) { }
	void ShowData() { cout << num << endl; }

	// 객체자신 주소 값을 반환하도록 -> 연산자를 오버로딩 하고 있다.
	// 주소 값의 반환이 목적이기 때문에 이런 형태로 오버로딩 했다.
	Number* operator->()
	{
		return this;
	}

	// 객체자신을 참조의 형태로 반환하도록 *연산자를 오버로딩 하고 있다.
	Number& operator*()
	{
		return *this;
	}
};

int main()
{
	Number num(20);
	num.ShowData();

	(*num) = 30; //  객체 num이 포인터 변수처럼 사용되었다. 이는 * 연산자의 오버로딩 결과이다.
	num->ShowData();
	(*num).ShowData(); // 동일하다
	return 0;
}