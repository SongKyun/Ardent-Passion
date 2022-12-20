#include <iostream>
using namespace std;

class BaseOne
{
public:
	void SimpleFuncOne() {	cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:
	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo // �޸�(��ǥ)�� �̿��ؼ� ����� ����� �Ǵ� Ŭ������ �����ؼ� ����� �� �ִ�. ���� Ŭ������ ����ϴ� ���´� ���� ������ ������ �����ϴ�.
{
public:
	void ComplexFunc()
	{
		//BaseOne Ŭ������ ����Լ��� BaseTwo Ŭ������ ����Լ��� ���� ȣ���ϰ� �ִ� ���߻���� �߱� ������ ������ ���̴�.
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main()
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}