#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° Sosimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;

class soComplex
{
private:
	static int cmxObjCnt;
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
int soComplex::cmxObjCnt = 0;

int main()
{
	SoSimple sim1;
	SoSimple sim2;

	soComplex com1;
	soComplex com2 = com1;
	soComplex();
	return 0;
}