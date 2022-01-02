/*
	Banking Project Ver.06
	By: 둠치킨
	
	(설정)
	NormalAccount 클래스
	+ 객체의 생성과정에서(생성자를 통해서) 이율정보를 등록할 수 있도록 정의.
	
	HighCreditAccount 클래스
	+ NormalAccount와 마찬가지로 객체 생성과정에서 기본이율을 등록할 수 있다]
	+ 고객의 신용등급 A,B,C로 나누고 계좌개설 시 이 정보를 등록, 그리고 등급별로 각각 7%,4%,2%의 추가 이율을 제공한다.
	
	모든 계좌에 대해 조건 추가
	+ 계좌개설 과정에서 초기 입금되는 금액에 대해서는 이자를 계산하지 않는다.
	+ 계좌개설 후 별도의 입금과정을 거칠 때에만 이자가 발생하는 것으로 간주.
	+ 이자의 계산과정에서 발생하는 소수점 이하의 금액은 무시한다.
*/

#include <iostream>
#include <cstring>
#define NAME_LEN 20
using namespace std;

enum{MAKE=1,DEPOSIT,WITHDRAW,SHOW,EXIT};

enum{LEVEL_A=7,LEVEL_B=4,LEVEL_C=2};

enum{NORMAL=1,CREDIT=2};

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
	virtual void Deposit(int money); //virtual 선언
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
	
protected: //public이어도 상관없긴한데... 음... 왜 굳이 이걸 쓰신거지? protected -> 상속관계일때만 서로 사용 가능.
	void makeNormalacc();
	void makeSpecialacc();
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