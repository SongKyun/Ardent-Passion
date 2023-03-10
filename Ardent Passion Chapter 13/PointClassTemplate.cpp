#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
};

int main()
{
	Point<int> pos1(3, 4); // Point<int> ��ü ���� ���
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.5);
	pos2.ShowPosition();

	Point<char> pos3('p', 'f'); // ��ǥ������ ���ڷ� ǥ���ϴ� ��Ȳ�� ǥ��
	pos3.ShowPosition();
	return 0;
}