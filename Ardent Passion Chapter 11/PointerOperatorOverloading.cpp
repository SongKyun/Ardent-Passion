#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) { }
	void ShowData() { cout << num << endl; }

	// ��ü�ڽ� �ּ� ���� ��ȯ�ϵ��� -> �����ڸ� �����ε� �ϰ� �ִ�.
	// �ּ� ���� ��ȯ�� �����̱� ������ �̷� ���·� �����ε� �ߴ�.
	Number* operator->()
	{
		return this;
	}

	// ��ü�ڽ��� ������ ���·� ��ȯ�ϵ��� *�����ڸ� �����ε� �ϰ� �ִ�.
	Number& operator*()
	{
		return *this;
	}
};

int main()
{
	Number num(20);
	num.ShowData();

	(*num) = 30; //  ��ü num�� ������ ����ó�� ���Ǿ���. �̴� * �������� �����ε� ����̴�.
	num->ShowData();
	(*num).ShowData(); // �����ϴ�
	return 0;
}