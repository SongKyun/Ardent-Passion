#include <iostream>
using namespace std;

int main()
{
	const int num = 12;
	//������ ������ �����ؼ� �� ������ ����Ű�� �غ���,
	const int* ptr = &num;
	//�׸��� �� ������ ������ �����ϴ� �����ڸ� �ϳ� ��������.
	const int* (&ref) = ptr;

	//���������� �̷��� ����� ������ ������ �����ڸ� �̿��ؼ�
	//num�� ����� ���� ����ϴ� ������ ������.
	cout << *ptr << endl;
	cout << *ref << endl;
	return 0;
}