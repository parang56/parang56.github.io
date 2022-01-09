/*
	Banking Project/ AccountHandler.cpp Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "SpecialAccount.h"

AccountHandler::AccountHandler(): accNum(0)
{ }

void AccountHandler::printmenu() const
{
		cout<<"-----Menu-----"<<endl<<endl;
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입 금"<<endl;
		cout<<"3. 출 금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl<<endl;
}

void AccountHandler::makeacc()
{
	int sel;
	cout<<"[계좌종류선택]"<<endl;
	cout<<"1.보통예금계좌 "<<endl;
	cout<<"2.신용신뢰계좌 "<<endl;
	cout<<"선택: ";
	cin>>sel;
	
	if(sel==NORMAL)
		makeNormalacc();
	else
		makeSpecialacc();
}

void AccountHandler::makeNormalacc()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int InterestRate;
		
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이 름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>balance;
	cout<<"이자율: ";
	cin>>InterestRate;
	cout<<endl;
	
	accArray[accNum++]=new NormalAccount(id,balance,name,InterestRate);
}

void AccountHandler::makeSpecialacc()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int SpecialRate;
	int creditLevel;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이 름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>balance;
	cout<<"이자율: ";
	cin>>SpecialRate;
	cout<<"신용등급(1->A,2->B,3->C): ";
	cin>>creditLevel;
	cout<<endl;
	
	switch(creditLevel)
	{
		case 1:
			accArray[accNum++]=new SpecialAccount(id,balance,name,SpecialRate,LEVEL_A);
			break;
		case 2:
			accArray[accNum++]=new SpecialAccount(id,balance,name,SpecialRate,LEVEL_B);
			break;
		case 3:
			accArray[accNum++]=new SpecialAccount(id,balance,name,SpecialRate,LEVEL_C);
			break;
	}
}

void AccountHandler::inputmoney()
{
	int id, input;
	cout<<"[입  금]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"입금액: ";
	cin>>input;
	for(int i=0; i<accNum; i++)
	{
		if(accArray[i]->GetAccID()==id)
		{
			accArray[i]->Deposit(input);
			cout<<"입금완료"<<endl;
			return;
		}	
	}
	cout<<"오류! 유효하지 않는 ID!"<<endl<<endl;
}

void AccountHandler::outputmoney()
{
	int id, output;
	cout<<"[출  금]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"출금액: ";
	cin>>output;
	for(int i=0; i<accNum; i++){
		if(accArray[i]->GetAccID()==id){
			if(accArray[i]->Withdraw(output) == 0)
			{
				cout<<"오류! 출금하려는 돈이 보유 돈보다 적음!"<<endl;
				return;
			}
			
			accArray[i]->Withdraw(output);
			cout<<"출금완료"<<endl;
			return;
		}
	}
    cout<<"오류! 유효하지 않는 ID!"<<endl;
}

void AccountHandler::printcustomer() const
{
	for(int i=0;i<accNum;i++)
	{
		accArray[i]->ShowAllAcc();
		cout<<endl;
	}
}

AccountHandler::~AccountHandler()
{
	for(int i=0;i<accNum;i++)
		delete accArray[i];
}