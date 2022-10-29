#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char str1[] = "Result";
	char str2[30];

	strcpy(str2, str1);
	printf("%s : %f \n", str1, sin(0.14)); // sin 삼각 함수
	printf("%s: %f \n", str2, abs(-1.25)); // abs 절대값 함수
	return 0;
}