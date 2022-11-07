#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void); // 메뉴 출력
void MakeAccount(void); // 계좌개설을 위한 함수
void DepositMoney(void); // 입 금
void WithdrawMoney(void); // 출 금
void ShowAllAccInfo(void); // 잔액조회

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; // enum 열거체이름 { 상수1이름, 상수2이름, ... }

//typedef struct // C언어의 typedef 키워드는 이미 존재하는 타입에
////새로운 이름을 붙일 때 사용합니다.
//{
//	int accID; // 계좌번호
//	int balance; // 잔액
//	char cusName[NAME_LEN]; // 고객이름
//
//} Account; // 구조체변수이름;

class Account
{
private:
	int accID;  //계좌번호
	int balance; // 잔액
	char *cusName; // 고객이름

public:
	Account(int ID, int money, char* name)
		: accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	int GetAccID() { return accID; }

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money) // 출금액 반환, 부족 시 0 반환
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo()
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액: " << balance << endl;
	}

	~Account()
	{
		delete[]cusName;
	}
};

Account* accArr[100]; // Account 저장을 위한 배열
int accNum = 0; // 저장된 Account 수

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) // switch (변수) 스위치문은 ( ) 안에 들어가는 변수의 값에
			// 따라서 각 case별로 실행하는 문법입니다
		{
		case MAKE:
			MakeAccount();
			break;  // 해당되는 case만 실행되어야 하기 때문에 무조건 break; 를 써줍니다
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void)
{
	cout << "----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입  금" << endl;
	cout << "3. 출  금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID"; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);

	//accArr[accNum].accID = id; // 문자형 계좌는 불가능함.
	//accArr[accNum].balance = balance;
	//strcpy_s(accArr[accNum].cusName, name); // 목적지 , 소스
	//accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출  금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money)==0)
			{
				cout << "잔액 부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	/*	cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이  름: " << accArr[i].cusName << endl;
		cout << "잔  액: " << accArr[i].balance << endl << endl;*/
	}
}
