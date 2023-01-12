#include <iostream>
namespace mystd // cout�� endl�� ���� �����ϱ� ���ؼ� ������ �̸������̴�.
{
	using namespace std;  // using ������ �̸����� mystd ������ ���������� �̷�������,
	//�� ���� �������� ��ȿ�� ������ �ȴ�. �׸��� �� ������ C����� ǥ���Լ��� printf �Լ��� ȣ���� ���ؼ� ���ԵǾ���.

	class ostream
	{
	public:
		ostream& operator<< (char* str) // cout �� ��ü�� �̸��̸�, ��ü �������� �پ��� �⺻ �ڷ��� �����͸� ������� << �����ڸ� �����ε� �ϰ� �ִ�.
			// ��ü�� ���� ���� ��ȯ�ϴ� ���·� Ȯ���Ͽ���.
		{
			printf("%s", str);
			return *this;
		}

		ostream& operator<< (char str)
		{
			printf("%c", str);
			return *this;
		}

		ostream& operator<< (int num)
		{
			printf("%d", num);
			return *this;
		}

		ostream& operator<< (double e)
		{
			printf("%g", e);
			return *this;
		}

		ostream& operator<< (ostream& (*fp)(ostream& ostm)) // 36�࿡ ���ǵ� �Լ��� ���ڷ� ���޹��� �� �ֵ��� ���ǵǾ� �ִ�.
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm) // endl �� �̷��� �Լ��� ���¸� ���. �׸��� ���۸� ���� �۾����� �Բ� �����Ѵ�.
	{
		ostm << '\n';
		fflush(stdout); // ���ۿ� �����Ͱ� ���� �Ǹ� �������� ������� ���� ���ϱ� ������ fflush()�Լ��� �̿��Ͽ� ���ۿ� �ִ� �����͸� ������ �մϴ�.
		//�Է� ��Ʈ��(stdin) �Է� ���� �ȿ� �����ϴ� �����͸� ���� ��� �����մϴ�.
		//��� ��Ʈ��(stdout) ��� ���� �ȿ� �����ϴ� �����͸� ���� ��� ����մϴ�. ���ۿ� �ִ� �����͸� ���� �����ġ�� �����ٰ� ����
		return ostm; // endl �Լ��� ���ڷ� ���޵� ��ü�� �������� ��ȯ�ϹǷ�, ��ȯ�� ���� �� ��ȯ�ϴ� ���·� �����ڸ� �����ε� �Ͽ���.
	}

	ostream cout;

}

int main()
{
	using mystd::cout; // �̸����� mystd ���� ����� cout�� endl�� ����� ���ؼ� ���������� using ������ �Ͽ���.
	using mystd::endl;// ���� main �Լ� �������� cout�� endl�� �̸����� mystd ���� ����� ���� �ǹ��Ѵ�.

	/*cout << "Simple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout); */

	cout << 3.14 << endl << 123 << endl;
	return 0;
}