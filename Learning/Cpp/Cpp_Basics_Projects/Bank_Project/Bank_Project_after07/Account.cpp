/*
	Banking Project/ Account.cpp Ver.08
	업데이트(2022,01,04)
	By: 둠치킨
*/

#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int myID, int mybalance, char *myname) : accID(myID), balance(mybalance)
{
	name = new char[strlen(myname)+1];
	strcpy(name,myname);
}
	
Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance) //깊은 복사
{
	name = new char[strlen(ref.name)+1];
	strcpy(name,ref.name);
}

Account& Account::operator=(const Account& ref) //추가된 정의
{
	accID=ref.accID;
	balance=ref.balance;
	
	delete []name;
	name=new char[strlen(ref.name)+1];
	strcpy(name, ref.name);
	return *this;
}

int Account::GetAccID() const
{
	return accID;
}
	
void Account::ShowAllAcc() const
{
	cout<<"계좌ID: "<<accID<<endl;
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