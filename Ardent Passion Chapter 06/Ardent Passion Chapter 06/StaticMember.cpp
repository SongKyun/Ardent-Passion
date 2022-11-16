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
		cout << simObjCnt << "¹øÂ° Sosimple °´Ã¼" << endl;
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
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
	}

	soComplex(soComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << endl;
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