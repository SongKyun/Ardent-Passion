#include <iostream>
namespace mystd // cout과 endl을 직접 구현하기 위해서 선언한 이름공간이다.
{
	using namespace std;  // using 선언은 이름공간 mystd 내에서 지역적으로 이뤄졌으니,
	//이 지역 내에서만 유효한 선언이 된다. 그리고 이 선언은 C언어의 표준함수인 printf 함수의 호출을 위해서 삽입되었다.

		class ostream
		{
		public:
			void operator<< (char* str) // cout 은 객체의 이름이며, 객체 내에서는 다양한 기본 자료형 데이터를 대상으로 << 연산자를 오버로딩 하고 있다.
			{
				printf("%s", str);
			}
		
			void operator<< (char str)
			{
				printf("%c", str);
			}
		
			void operator<< (int num)
			{
				printf("%d", num);
			}
		
			void operator<< (double e)
			{
				printf("%g", e);
			}
		
			void operator<< (ostream& (*fp)(ostream& ostm)) // 36행에 정의된 함수를 인자로 전달받을 수 있도록 정의되어 있다.
			{
				fp(*this);
			}
		};

	ostream& endl(ostream& ostm) // endl 은 이렇듯 함수의 형태를 띈다. 그리고 버퍼를 비우는 작업까지 함께 진행한다.
	{
		ostm << '\n';
		fflush(stdout); // 버퍼에 데이터가 남게 되면 정상적인 입출력을 하지 못하기 때문에 fflush()함수를 이용하여 버퍼에 있는 데이터를 비워줘야 합니다.
						//입력 스트림(stdin) 입력 버퍼 안에 존재하는 데이터를 비우는 즉시 삭제합니다.
						//출력 스트림(stdout) 출력 버퍼 안에 존재하는 데이터를 비우는 즉시 출력합니다. 버퍼에 있는 데이터를 꺼내 출력장치로 보낸다고 생각
		return ostm;
	}

		ostream cout;

}

int main()
{
	using mystd::cout; // 이름공간 mystd 내에 선언된 cout과 endl의 사용을 위해서 지역적으로 using 선언을 하였다.
	using mystd::endl;// 따라서 main 함수 내에서의 cout과 endl은 이름공간 mystd 내에 선언된 것을 의미한다.

	cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);

	return 0;
}