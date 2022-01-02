/*
	Banking Project/ NormalAccount.h Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
	int InterestRate; //이자율
public:
	NormalAccount(int ID, int money, char *name, int rate)
		: Account(ID,money,name), InterestRate(rate)
	{ }
	
	virtual void Deposit(int money)
	{
		Account::Deposit(money); //원금추가
		Account::Deposit(money*(InterestRate/100.0)); //이자추가
	}
};

#endif