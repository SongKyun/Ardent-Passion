#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1 = "I like";
	string str2 = "string class";
	string str3 = str1 + str2; // string ���� �������� operator+ �������� �����ε�

	cout << str1 << endl; // << ������ �����ε�
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� �ʴ� ���ڿ�!" << endl;

	string str4;
	cout << "���ڿ� �Է� : ";
	cin >> str4; // >> ������ �����ε�
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}