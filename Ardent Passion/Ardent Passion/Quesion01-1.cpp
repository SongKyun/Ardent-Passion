/// <summary>
/// 1번째 정수 입력: 1
/// 2번째 정수 입력: 2
/// 3번째 정수 입력: 3
/// 4번째 정수 입력: 4
/// 5번째 정수 입력: 5
/// 합계: 15
/// </summary>

// 입력문 5개, 출력문 5개 = 반복문
// 5개의 정수를 저장할 공간 = 배열
// 합계 계산 - 반복문

#include <iostream>

int main()
{
	int arr[5] = {};
	int total = 0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i + 1 << "번째 정수 입력: ";
		std::cin >> arr[i];
		total += arr[i];
	}
	
	std::cout << "합계: " << total;

}