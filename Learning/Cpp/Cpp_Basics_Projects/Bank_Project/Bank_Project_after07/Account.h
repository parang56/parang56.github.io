/*
	Banking Project/ Account.h Ver.08
	업데이트(2022,01,04)
	By: 둠치킨
*/

#ifndef __Account_H__
#define __Account_H__

class Account
{
private:
	int accID;
	int balance;
	char *name;
	
public:
	Account(int myID, int mybalance, char *myname);
	Account(const Account& ref);
	Account& operator=(const Account& ref); //추가된 문장
	
	int GetAccID() const;
	void ShowAllAcc() const;
	virtual void Deposit(int money); //virtual 선언
	int Withdraw(int money);
	~Account();	
};

#endif