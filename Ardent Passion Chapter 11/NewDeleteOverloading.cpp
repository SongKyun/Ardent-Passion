#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new(size_t size)
	{
		cout << "operator new : " << size << endl;
		void* adr = new char[size]; 
		// 바이트 단위로 필요한 메모리 공간 할당 할당 사용 크기 정보는 컴파일러가 계산
		return adr;
	}

	void operator delete (void* adr)
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
		// 배열의 삭제를 위한 delete문 구성 / char형 할당 메모리 공간을 해제
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main()
{
	Point* ptr = new Point(3, 4);
	cout << *ptr;
	delete ptr;
	return 0;
}