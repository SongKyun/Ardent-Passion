#pragma once

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h" // 09

class Account
{
private:
	int accID;
	int balance;
	String cusName; // char* cusName; 09
public:
	Account(int ID, int money, String name);
	// Account(int ID, int money, char* name); 09
	// Account(const Account& ref); 09
	// Account& operator=(const Account& ref); // 08 추가 문장 09

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	// ~Account(); 09
};

#endif