#include <iostream>
using namespace std;

// Ŭ���� Data�� �䳻 �� ����
typedef struct Data
{
	int data;
	// �Լ� ������ ������ ����ü�� ����� ���� 
	void (*ShowData)(Data*); // 13���� �Լ��� �ּ� ���� ����
	void (*Add)(Data*, int); // 14���� �Լ��� �ּ� ���� ����
}Data;

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

// ������ ����� main �Լ�
int main()
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
};