#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° Sosimple ��ü" << endl;
	}
};

class soComplex
{
public:
	soComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}

	soComplex(soComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};

int main()
{
	SoSimple sim1;
	SoSimple sim2;

	soComplex com1;
	soComplex com2 = com1;
	soComplex();
	return 0;
}