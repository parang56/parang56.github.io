/*
	Banking Project/ Account.cpp Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#include "BankingCommonDec1.h"
#include "Account.h"

Account::Account(int myID, int mybalance, char *myname) : ID(myID), balance(mybalance)
{
	name = new char[strlen(myname)+1];
	strcpy(name,myname);
}
	
Account::Account(const Account& ref) : ID(ref.ID), balance(ref.balance) //깊은 복사
{
	name = new char[strlen(ref.name)+1];
	strcpy(name,ref.name);
}
	
int Account::GetAccID() const
{
	return ID;
}
	
void Account::ShowAllAcc() const
{
	cout<<"계좌ID: "<<ID<<endl;
	cout<<"이 름: "<<name<<endl;
	cout<<"잔 액: "<<balance<<endl;
}
	
void Account::Deposit(int money)
{
	balance+=money;
}
	
int Account::Withdraw(int money)
{
	if(balance<money)
		return 0;
	
	balance-=money;
	return money;
}
	
Account::~Account()
{
	delete []name;
}