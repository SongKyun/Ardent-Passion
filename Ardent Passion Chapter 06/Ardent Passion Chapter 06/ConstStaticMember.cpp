#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

int main()
{
	cout << "���þ� ����: " << CountryArea::RUSSIA << "KM" << endl;
	cout << "ĳ���� ����: " << CountryArea::CANADA<< "KM" << endl;
	cout << "�߱� ����: " << CountryArea::CHINA<< "KM" << endl;
	cout << "�ѱ� ����: " << CountryArea::SOUTH_KOREA<< "KM" << endl;
	return 0;
}