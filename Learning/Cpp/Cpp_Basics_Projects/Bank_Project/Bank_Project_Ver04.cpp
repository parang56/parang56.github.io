/*
	Banking Project Ver.04
	By: 둠치킨
	
	(설정)
	Account 클래스의 멤버함수 중 일부를 const로 선언->const로 선언이 가능한 모든 멤버함수를 const로 선언하자.
*/

#include <iostream>
#include <cstring>
#define NAME_LEN 20
using namespace std;

enum{MAKE=1,DEPOSIT,WITHDRAW,SHOW,EXIT};

void printmenu(void);
void makeacc(void);
void inputmoney(void);
void outputmoney(void);
void printcustomer(void);

class Account
{
private:
	int ID;
	int balance;
	char *name;
	
public:
	Account(int myID, int mybalance, char *myname) : ID(myID), balance(mybalance)
	{
		name = new char[strlen(myname)+1];
		strcpy(name,myname);
	}
	
	Account(const Account& ref) : ID(ref.ID), balance(ref.balance)
	{
		name = new char[strlen(ref.name)+1];
		strcpy(name,ref.name);
	}
	
	int GetAccID() const
	{
		return ID;
	}
	
	void Deposit(int money)
	{
		balance+=money;
	}
	
	int Withdraw(int money)
	{
		if(balance<money)
			return 0;
		
		balance-=money;
		return money;
	}
	
	void ShowAllAcc() const
	{
		cout<<"계좌ID: "<<ID<<endl;
		cout<<"이 름: "<<name<<endl;
		cout<<"잔 액: "<<balance<<endl;
	}
	
	~Account()
	{
		delete []name;
	}
};

Account * accArray[100]; //객체 포인터 배열
int accNum=0; //몇번쨰 ID

int main(void)
{
	printmenu();
	return 0;
}

void printmenu()
{
	while(1){
		int select=0;
		cout<<"-----Menu-----"<<endl<<endl;
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입 금"<<endl;
		cout<<"3. 출 금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl<<endl;
		cout<<"선택: ";
		cin>>select;
		cout<<endl;
		switch(select)
		{
			case MAKE:
				makeacc();
				break;
			case DEPOSIT:
				inputmoney();
				break;
			case WITHDRAW:
				outputmoney();
				break;
			case SHOW:
				printcustomer();
				break;
			case EXIT:
				return;
		}
	}

}

void makeacc()
{
	int id;
	char name[NAME_LEN];
	int balance;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이 름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>balance;
	cout<<endl;
	
	accArray[accNum++]=new Account(id,balance,name);
	
}

void inputmoney()
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

void outputmoney()
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

void printcustomer()
{
	for(int i=0;i<accNum;i++)
	{
		accArray[i]->ShowAllAcc();
		cout<<endl;
	}
}