#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}

	// 반환형이 참조형이다. 때문에 배열요소의 참조값이 반환되고 이 값으로
	// 배열요소에 저장 된 값의 참조뿐만 아니라 변경도 가능하다.
	int& operator[] (int idx)
	{
		if (idx<0 || idx>arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		// 인자로 전달된 인덱스에 해당하는 배열요소를 반환
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main()
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)

		//배열에 직접 접근하는 느낌을 줌
		arr[i] = (i + 1) * 11;

	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;
	return 0;
}