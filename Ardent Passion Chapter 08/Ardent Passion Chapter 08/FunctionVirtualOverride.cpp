#include <iostream>
using namespace std;

class First
{
public:
	// virtual �� ����Ǿ����� �ٸ� �Լ����� �߰� �� �ص� �����Լ��� �ȴ�. �׷��� �̷��� ������ �־ �Լ��� �����Լ����� �˸��� ���� ����.
	virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
	virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
	virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main()
{
	// Third ��ü�� ������ ����, Third��, Second��, �׸��� First�� ������ ������ �̸� �����ϰ� �ִ�.
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	// �� ������ �� ������ �̿��ؼ� MyFunc �Լ��� ȣ���ϰ� �ִ�.
	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();
	delete tptr;
	return 0;
}

// �� 3���� Ŭ������ ��Ӱ���� ����Ǿ� ������, �̵��� ��� MyFunc �Լ��� ���ؼ� �������̵� ���踦 �����ϰ� �ִ�.
