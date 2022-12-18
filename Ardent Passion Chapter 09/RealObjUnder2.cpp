#include <iostream>
using namespace std;

// 클래스 Data를 흉내 낸 영역
typedef struct Data
{
	int data;
	// 함수 포인터 변수가 구조체의 멤버로 등장 
	void (*ShowData)(Data*); // 13행의 함수의 주소 값을 저장
	void (*Add)(Data*, int); // 14행의 함수의 주소 값을 저장
}Data;

void ShowData(Data* THIS) { cout << "Data: " << THIS->data << endl; }
void Add(Data* THIS, int num) { THIS->data += num; }

// 적절히 변경된 main 함수
int main()
{
	Data obj1 = { 15, ShowData, Add };
	Data obj2 = { 7, ShowData, Add };

	obj1.Add(&obj1, 17);
	obj2.Add(&obj2, 9);
	obj1.ShowData(&obj1);
	obj2.ShowData(&obj2);
	return 0;
};