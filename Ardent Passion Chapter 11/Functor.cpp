#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }

	Point operator+(const Point& pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos); // Point형 임시객체를 생성과 동시에 반환
		// return문에서도 임시객체를 생성과 동시에 반환하는 것이 가능하다.
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

// 두 개의 숫자 또는 Point 객체에 대한 덧셈결과를 반환하도록 () 연산자가 총 3회 오버로딩됨.
class Adder
{
public:
	int operator()(const int& n1, const int& n2)
	{
		return n1 + n2;
	}

	double operator()(const double& e1, const double& e2)
	{
		return e1 + e2;
	}

	Point operator()(const Point& pos1, const Point& pos2)
	{
		return pos1 + pos2;
	}
};

int main()
{
	Adder adder;
	cout << adder(1, 3) << endl; // adder 라는 함수를 호출하고 반환되는 값을 출력
	cout << adder(1.5, 3.7) << endl; // 즉, adder는 객체임에도 불구하고 함수처럼 동작한다.
	cout << adder(Point(3, 4), Point(7, 9)); // Point형 임시객체 두 개를 생성해서 인자로 전달한다.
	// 함수 호출문에도 임시객체를 생성하는 것이 가능하다.
	return 0;
}