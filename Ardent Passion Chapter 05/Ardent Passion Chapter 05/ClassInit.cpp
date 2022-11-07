#include <iostream>
using namespace std;

class SoSImple
{
private:
	int num1;
	int num2;
public:
	SoSImple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		// empty
	}
	SoSImple(SoSImple& copy)
		:num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple &copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSImple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSImple sim2 = sim1; // Sosimple sim2(sim1);으로 변환
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();
	return 0;
}