#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}

	// ��ȯ���� �������̴�. ������ �迭����� �������� ��ȯ�ǰ� �� ������
	// �迭��ҿ� ���� �� ���� �����Ӹ� �ƴ϶� ���浵 �����ϴ�.
	int& operator[] (int idx)
	{
		if (idx<0 || idx>arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		// ���ڷ� ���޵� �ε����� �ش��ϴ� �迭��Ҹ� ��ȯ
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main()
{
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)

		//�迭�� ���� �����ϴ� ������ ��
		arr[i] = (i + 1) * 11;

	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;
	return 0;
}