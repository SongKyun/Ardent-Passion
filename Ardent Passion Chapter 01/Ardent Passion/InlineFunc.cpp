#include <iostream>

//�ζ��� �Լ��� ���� ��� Ű���� inline�� ������ ���ؼ� 
inline int SQUARE(int x)
{
	return x * x;
}

int main(void)
{
	// SQUARE �Լ��� ȣ���ϰ� �ִ�. �׷��� �� �Լ��� �ζ��� �Լ��̴�
	// ��ü �κ��� ȣ�⹮�� ��ü�ϰ� �ȴ�.
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(12) << std::endl;
	return 0;
}