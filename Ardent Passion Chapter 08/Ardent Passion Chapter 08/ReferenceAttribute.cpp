#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main()
{
	Third obj;
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	Second& sref = obj; // obj�� Second�� ����ϴ� Third ��ü�̹Ƿ�, Second�� �����ڷ� ������ �����ϴ�.
	sref.FirstFunc(); // �����Ϸ��� �������� �ڷ����� ������ �Լ��� ȣ�� ���ɼ��� �Ǵ��ϱ� ������
	sref.SecondFunc(); // First Ŭ������ ���ǵ� FirstFunc �Լ��� Second Ŭ������ ���ǵ� SecondFunc �Լ��� ȣ���� ����������, Third Ŭ������ ���ǵ� ThirdFunc �Լ��� ȣ���� �Ұ����ϴ�.
	sref.SimpleFunc(); //  SimpleFunc �Լ��� �����Լ��̹Ƿ�, Third Ŭ������ ���ǵ� SimpleFunc �Լ��� ȣ��ȴ�.

	First& fref = obj; // obj �� First�� ���� ����ϴ� Third ��ü�̹Ƿ�, First �� �����ڷ� ������ �����ϴ�.
	fref.FirstFunc(); //  �����Ϸ��� �������� �ڷ����� ������ �Լ��� ȣ�� ���ɼ��� �Ǵ��ϱ� ������ First Ŭ������ ���ǵ� �Լ��� ȣ�� �����ϴ�.
	fref.SimpleFunc(); // �׷��� �� �߿��� SimpleFunc�� �����Լ��̹Ƿ�, Third Ŭ������ ���ǵ� SimpleFunc �Լ��� ȣ��ȴ�.
	return 0;
}