//�����ڸ� �̿��ؼ� ���� �䱸���׿� �����ϴ� �Լ��� ���� �����϶�.
//
//�� ���ڷ� ���޵�  int �� ������ ���� 1�� ������Ű�� �Լ�
//
//�� ���ڷ� ���޵� int �� ������ ��ȣ�� �ٲٴ� �Լ�
//
//�׸��� ���� �� �Լ��� ȣ���Ͽ� �� ����� Ȯ���ϴ� main �Լ����� �ۼ��ض�.

#include <iostream>
using namespace std;

void IncreOne(int& num)
{
	num++;
}

void InverSign(int& num)
{
	num *= -1; // ���� �Ǵ� �Ӽ� ���� �� ���� ���ϰ� ����� ���� �Ǵ� �Ӽ��� �Ҵ��մϴ�.
}

int main()
{
	int val = 20;
	IncreOne(val);
	cout << val << endl;
	InverSign(val);
	cout << val << endl;
	return 0;
}

