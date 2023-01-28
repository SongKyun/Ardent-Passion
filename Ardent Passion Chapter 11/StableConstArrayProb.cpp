#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr){ }

public:
	BoundCheckIntArray(int len) :arrlen(len) { arr = new int[len]; }
	int& operator[] (int idx) // 25행과 오버로딩 관계
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int& operator[] (int idx) const  // const 멤버함수가 추가
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckIntArray() { delete []arr; }
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl; // const 참조자를 이용한 연산으로 25행 const 함수가 호출
}

int main()
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11; // const 선언이 아닌 arr 이용한 연산으로 15행 함수 호출

	ShowAllData(arr);
	return 0;
}