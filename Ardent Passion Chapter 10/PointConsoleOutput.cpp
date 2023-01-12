#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }

	void SHowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}

	friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl; // 인자로 전달된 cout의 참조자를 통한 출력을 구성
	return os;
}

int main()
{
	Point pos1(1, 3);
	cout << pos1; // 20행에서 정의된 함수가 호출된다. 이는 << 연산자의 오른편에 등장한 것이 Point 객체이기 때문이다.
	Point pos2(101, 303);
	cout << pos2;
	return 0;
}