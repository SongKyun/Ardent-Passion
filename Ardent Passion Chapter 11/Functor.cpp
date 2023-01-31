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
		return Point(xpos + pos.xpos, ypos + pos.ypos); // Point�� �ӽð�ü�� ������ ���ÿ� ��ȯ
		// return�������� �ӽð�ü�� ������ ���ÿ� ��ȯ�ϴ� ���� �����ϴ�.
	}

	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

// �� ���� ���� �Ǵ� Point ��ü�� ���� ��������� ��ȯ�ϵ��� () �����ڰ� �� 3ȸ �����ε���.
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
	cout << adder(1, 3) << endl; // adder ��� �Լ��� ȣ���ϰ� ��ȯ�Ǵ� ���� ���
	cout << adder(1.5, 3.7) << endl; // ��, adder�� ��ü�ӿ��� �ұ��ϰ� �Լ�ó�� �����Ѵ�.
	cout << adder(Point(3, 4), Point(7, 9)); // Point�� �ӽð�ü �� ���� �����ؼ� ���ڷ� �����Ѵ�.
	// �Լ� ȣ�⹮���� �ӽð�ü�� �����ϴ� ���� �����ϴ�.
	return 0;
}