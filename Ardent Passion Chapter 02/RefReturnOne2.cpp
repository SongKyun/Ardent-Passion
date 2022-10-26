#include <iostream>
using namespace std;

int RefReturn(int& ref)
{
	ref++;
	return ref;
}

int main()
{
	int num1 = 10;
	int num2 = RefReturn(num1);
	//int& num2 = RefReturn(num1);

	num1++;
	num2+=10;

	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;
	return 0;
}