#pragma once

#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__

#include "Account.h"
#include "AccountArray.h" // 08  추가 문장.

class AccountHandler
{
private:
	// Account* accArr[100]; // 07까지 사용한 문장.
	BoundCheckAccountPtrArray accArr; // 08 변경된 문장.
	int accNum;

public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

#endif