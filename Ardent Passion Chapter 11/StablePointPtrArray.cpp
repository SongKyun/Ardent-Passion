#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '['<<pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}

// Point 포인터 형을 의미하는 POINT_PTR을 정의 저장의 대상, 또는 연산의 주 대상이 포인터인 경우
// 별도의 자료형을 정의하는 것이 좋다.
typedef Point* POINT_PTR;

class BoundCheckPointPtrArray
{
private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len) :arrlen(len)
	{
		// 저장의 대상이 Point 객체의 주소 값이여서 배열을 생성하였다.
		arr = new POINT_PTR[len];
	}

	POINT_PTR& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const { return arrlen; }
	~BoundCheckPointPtrArray() { delete[]arr; }
};

int main()
{
	BoundCheckPointPtrArray arr(3);
	// Point 객체의 주소 값을 저장 중. 객체의 주소 값을 저장할 경우 깊은,얕은 복사를 신경 안 써도 됨.
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *(arr[i]);
	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}