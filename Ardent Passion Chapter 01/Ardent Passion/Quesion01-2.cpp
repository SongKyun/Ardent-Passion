#include <iostream>

int main()
{
	char name[100];
	char num[200];

	std::cout << "�̸� : ";
	std::cin >> name;

	std::cout << "��ȣ : ";
	std::cin >> num;

	std::cout << "�Է��Ͻ� �̸���" << name << "�Դϴ�" << std::endl;
	std::cout << name << "�� �Է��Ͻ� ��ȣ��" << num << "�Դϴ�" << std::endl;

}