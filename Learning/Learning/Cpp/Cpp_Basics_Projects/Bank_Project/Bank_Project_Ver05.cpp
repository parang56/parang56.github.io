/*
	Banking Project Ver.05
	By: 둠치킨
	
	(설정)
	+AccountHandler라는 이름의 컨트롤 클래스 정의하고, 앞서 정의한 전역함수들을 이 클래스의 멤버함수에 포함시킨다.
	+Account 객체의 저장을 위해 선언한 배열과 변수도 이 클래스의 멤버에 포함시킨다.
	+AccountHandler 클래스 기반으로 프로그램이 실행되도록 main함수를 변경한다.
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

//Entity Class: Account 

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
	void Deposit(int money);
	int Withdraw(int money);
	~Account();	
};

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

//Handler Class: AccountHandler

class AccountHandler
{
private: //2)+Account 객체의 저장을 위해 선언한 배열과 변수도 이 클래스의 멤버에 포함시킨다.
	Account * accArray[100]; //객체 포인터 배열
	int accNum; //몇번쨰 ID
public:
	AccountHandler();
	void printmenu() const;
	void makeacc();
	void inputmoney();
	void outputmoney();
	void printcustomer() const;
	~AccountHandler();
};

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

int main(void)
{
	AccountHandler manager;
	while(1)
	{
		manager.printmenu(); //궁금증: Bank_Project_Ver04.cpp에서는 while문을 printmenu() 안에 넣었는데, 여기서도 그게 구현 가능할까?
		int select=0;
		cout<<"선택: ";
		cin>>select;
		cout<<endl;
		switch(select)
		{
			case MAKE:
				manager.makeacc();
				break;
			case DEPOSIT:
				manager.inputmoney();
				break;
			case WITHDRAW:
				manager.outputmoney();
				break;
			case SHOW:
				manager.printcustomer();
				break;
			case EXIT:
				return 0;
			default:
				cout<<"Illegal selection.."<<endl;
		}
	}
	return 0;
}