#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}

	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}

	operator int() // 형 변환 연산자의 오버로딩
		// 반환형이 없음에도 불구하고 반환을 하고 있다는 사실.
	{
		return num;
	}

	void ShowNumber() { cout << num << endl; }
};

int main()
{
	Number num1;
	num1 = 30;
	Number num2 = num1 + 20;
	// num1+20이 먼저 진행되어야 하는데 operator+ 함수가 정의되어 있지 않으니
	// 덧셈이 가능하려면 num1이 int형으로 변환이 되어야 한다.
	// 이 때 호출되는 것이 형 변환 연산자이다.
	num2.ShowNumber();
	return 0;
}