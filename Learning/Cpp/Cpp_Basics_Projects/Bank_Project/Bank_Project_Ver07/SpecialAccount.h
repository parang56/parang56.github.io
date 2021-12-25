/*
	Banking Project/ SpecialAccount.h Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#ifndef __SPECIAL_ACCOUNT_H__
#define __SPECIAL_ACCOUNT_H__

#include "NormalAccount.h"

class SpecialAccount : public NormalAccount
{
private:
	int SpecialRate; //특 이자율
public:
	SpecialAccount(int ID, int money, char *name, int rate,int special)
		: NormalAccount(ID,money,name,rate), SpecialRate(special)
	{ }
	
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); //원금추가
		Account::Deposit(money*(SpecialRate/100.0)); //특 이자추가
	}
};

#endif

