//참조자를 이용해서 다음 요구사항에 부합하는 함수를 각각 정의하라.
//
//→ 인자로 전달된  int 형 변수의 값을 1씩 증가시키는 함수
//
//→ 인자로 전달된 int 형 변수의 부호를 바꾸는 함수
//
//그리고 위의 각 함수를 호출하여 그 결과를 확인하는 main 함수까지 작성해라.

#include <iostream>
using namespace std;

void IncreOne(int& num)
{
	num++;
}

void InverSign(int& num)
{
	num *= -1; // 변수 또는 속성 값에 식 값을 곱하고 결과를 변수 또는 속성에 할당합니다.
}

int main()
{
	int val = 20;
	IncreOne(val);
	cout << val << endl;
	InverSign(val);
	cout << val << endl;
	return 0;
}

