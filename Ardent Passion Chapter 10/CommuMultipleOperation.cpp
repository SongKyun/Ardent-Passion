#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}

	friend Point operator*(int times, Point& ref);
};

// 교환법칙의 성립을 목적으로 함수가 추가로 정의되었다.
Point operator*(int times, Point& ref)
{
	return ref * times;
}

int main()
{
	Point pos(1, 2); 
	Point cpy;

	cpy = 3 * pos; // 교환법칙이 성립됨을 보이고 있다.
	cpy.ShowPosition();

	cpy = 2 * pos * 3; // 교환법칙이 성립되면, 이렇듯 자연스러운 연산문의 구성이 가능하다.
	cpy.ShowPosition();
	return 0;
}