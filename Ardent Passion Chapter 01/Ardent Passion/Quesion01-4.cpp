/*
판매 금액을 만원 단위로 입력(-1 to end):100
이번 달 급여: 62만원
판매 금액을 만원 단위로 입력(-1 to end):200
이번 달 급여: 74만원
판매 금액을 만원 단위로 입력(-1 to end):-1
프로그램을 종료합니다.
*/

#include <iostream>

int main()
{
	int sell = 0;

	std::cout << "판매 금액을 만원 단위로 입력(-1 to end):";
	std::cin >>  sell;

	// While - 조건식이 true 인 경우 계속 반복한다 - 무한루프
	while (sell!=-1)
	{
		std::cout << "이번 달 급여: " << 50+(sell*0.12) << std::endl;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end):";
		std::cin >> sell;
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
}