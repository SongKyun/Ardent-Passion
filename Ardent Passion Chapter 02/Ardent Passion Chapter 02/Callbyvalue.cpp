#include <iostream>
using namespace std;

void SwapByValue(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
} // Call by value

int main()
{
	int val1 = 10;
	int val2 = 20;
	SwapByValue(val1, val2); // val1과 val2에 저장된 값이 바뀌기를 기대함.
	cout << "val1: " << val1 << endl; // 10출력
	cout << "val2: " << val2 << endl; // 20출력
	return 0;
}