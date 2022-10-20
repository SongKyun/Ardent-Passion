#include <iostream>

//인라인 함수의 정의 방법 키워드 inline의 선언을 통해서 
inline int SQUARE(int x)
{
	return x * x;
}

int main(void)
{
	// SQUARE 함수를 호출하고 있다. 그런데 이 함수는 인라인 함수이니
	// 몸체 부분이 호출문을 대체하게 된다.
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(12) << std::endl;
	return 0;
}