/*
	Banking Project/ Account.h Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#ifndef __Account_H__
#define __Account_H__

class Account
{
private:
	int ID;
	int balance;
	char *name;
	
public:
	Account(int myID, int mybalance, char *myname);
	Account(const Account& ref);
	int GetAccID() const;
	void ShowAllAcc() const;
	virtual void Deposit(int money); //virtual 선언
	int Withdraw(int money);
	~Account();	
};

#endif