#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char* str1 = "ABC 123";
	char* str2 = "DEF 456";
	char str3[50];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	strcpy(str3, str1);
	strcat(str3, str2); // string char attach �� ���̱�
	cout << str3 << endl;

	if (strcmp(str1, str2) == 0) // string compare ���� ��
		cout << "���ڿ��� ����" << endl;
	else
		cout << "���ڿ��� ���� �ʴ�" << endl;
	return 0;
}
