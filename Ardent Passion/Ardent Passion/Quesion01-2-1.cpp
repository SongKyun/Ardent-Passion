// ���� main �Լ����� �ʿ�� �ϴ� swap �Լ��� �����ε� �ؼ� �����غ���.
// 30 20
// Z A
// 5.555 1.111

#include <iostream>

void swap(int* num1, int* num2)
{

}

void swap(char* ch1, char* ch2)
{

}

void swap(double* a, double* b)
{

}

int main(void)
{
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << ' ' << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;
	return 0;
}