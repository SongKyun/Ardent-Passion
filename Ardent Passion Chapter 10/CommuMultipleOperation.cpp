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

// ��ȯ��Ģ�� ������ �������� �Լ��� �߰��� ���ǵǾ���.
Point operator*(int times, Point& ref)
{
	return ref * times;
}

int main()
{
	Point pos(1, 2); 
	Point cpy;

	cpy = 3 * pos; // ��ȯ��Ģ�� �������� ���̰� �ִ�.
	cpy.ShowPosition();

	cpy = 2 * pos * 3; // ��ȯ��Ģ�� �����Ǹ�, �̷��� �ڿ������� ���깮�� ������ �����ϴ�.
	cpy.ShowPosition();
	return 0;
}