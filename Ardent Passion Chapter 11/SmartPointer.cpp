#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}

	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr
{
private:
	Point* posptr;
public:
	// 생성자에서 동적할당을 하지 않았음에도 소멸자에서 delete 연산을 하는 것은
	// new 연산에 의해서 동적 할당된 객체의 주소 값이라는 가정이 포함되어 있기 때문이다.
	SmartPtr(Point * ptr) : posptr(ptr)  
	{ }

	// Point& operator*() const, Point* operator->() const
	// 스마트 포인터의 가장 기본은 이 두 함수의 정의에 있다.
	// 스마트 포인터는 포인터처럼 동작하는 객체이다.
	// 스마트 포인터가 더 똑똑해 질수록 이 두 함수도 하는 일이 더 많아진다.

	Point& operator*() const 
	{
		return *posptr;
	}

	Point* operator->() const
	{
		return posptr;
	}

	~SmartPtr()
	{
		delete posptr;
	}
};

int main()
{
	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}