#include <iostream>

int main()
{
	char name[100];
	char num[200];

	std::cout << "이름 : ";
	std::cin >> name;

	std::cout << "번호 : ";
	std::cin >> num;

	std::cout << "입력하신 이름은" << name << "입니다" << std::endl;
	std::cout << name << "이 입력하신 번호는" << num << "입니다" << std::endl;

}