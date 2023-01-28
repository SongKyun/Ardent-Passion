#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { } 
	// 정의된 생성자에 설정된 디폴트 값에 의해 객체의 모든 멤버가 0으로 초기화 된다.
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}

class BoundCheckPointArray
{
private:
	Point* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }

public:
	BoundCheckPointArray(int len) :arrlen(len)
	{
		arr = new Point[len]; // Point 객체로 이뤄진 배열 생성
		// 인자를 받지 않는 void 생성자의 호출을 통해서 배열요소를 이루는 객체가 생성되므로
	}

	Point& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	Point operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete[]arr; }
};

int main()
{
	BoundCheckPointArray arr(3);
	// 임시객체를 생성해서 배열요소를 초기화
	// 초기화 과정에서 디폴트 대입 연산자가 호출되어 멤버 대 멤버의 복사가 진행된다.
	// 저장의 대상이 객체라면, 대입 연산자를 통해서 객체에 저장된 값을 복사해야 한다.
	arr[0] = Point(3, 4);
	arr[1] = Point(5, 6);
	arr[2] = Point(7, 8);

	for (int i = 0; i<arr.GetArrLen(); i++)
		cout << arr[i];

	return 0;
}