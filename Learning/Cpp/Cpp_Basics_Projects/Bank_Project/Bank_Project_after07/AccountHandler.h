/*
	Banking Project/ AccountHandler.h Ver.08
	업데이트(2022,01,04)
	By: 둠치킨
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArray; //변경된 문장
	int accNum; //몇번쨰 ID
public:
	AccountHandler();
	void printmenu() const;
	void makeacc();
	void inputmoney();
	void outputmoney();
	void printcustomer() const;
	~AccountHandler();
	
protected:
	void makeNormalacc();
	void makeSpecialacc();
};

#endif