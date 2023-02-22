#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, String name) // char* name) 09
	: accID(ID), balance(money)
{
	//cusName = new char[strlen(name) + 1]; 09
	//strcpy(cusName, name); 09
	cusName = name; // 09
}

 // 09 
//Account::Account(const Account& ref)
//	: accID(ref.accID), balance(ref.balance)
//{
//	cusName = new char[strlen(ref.cusName) + 1];
//	strcpy(cusName, ref.cusName);
//}

//Account& Account::operator=(const Account& ref) // 08 Ãß°¡ Á¤ÀÇ
//{
//	accID = ref.accID;
//	balance = ref.balance;
//
//	delete[]cusName;
//	cusName = new char[strlen(ref.cusName) + 1];
//	strcpy(cusName, ref.cusName);
//	return *this;
//}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << accID << endl;
	cout << "ÀÌ  ¸§: " << cusName << endl;
	cout << "ÀÜ  ¾×: " << balance << endl;
}

//09
//Account::~Account()
//{
//	delete []cusName;
//}