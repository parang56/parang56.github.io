/*
	Banking Project Ver.01 (C style)
	By: 둠치킨
	
	(설정)
	계좌번호 중복검사 X
	입금,출금>0 
	계좌번호, 고객이름, 고객의 잔액만 저장
	둘 이상의 고객 정보 저장을 위해 배열 사용
	계좌번호 정수 형태
*/

#include <iostream>
#define NAME_LEN 20

using namespace std;

typedef struct{
	int ID;
	int balance;
	char name[NAME_LEN];
} Account;

Account accArray[100];
int accNum=0;

void printmenu();
void makeacc();
void inputmoney();
void outputmoney();
void printcustomer();

int main(void)
{
	printmenu();
	return 0;
}

//내가 생각하진 않았지만 책에서 쓴 것
enum{MAKE=1,DEPOSIT,WITHDRAW,SHOW,EXIT};

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
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>accArray[accNum].ID;
	cout<<"이 름: ";
	cin>>accArray[accNum].name;
	cout<<"입금액: ";
	cin>>accArray[accNum].balance;
	accNum++;
}

void inputmoney()
{
	//존재하지 않는 id면 오류 떠야함
	int id, input;
	cout<<"[입  금]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"입금액: ";
	cin>>input;
	for(int i=0; i<accNum; i++){
		if(accArray[i].ID==id){
			accArray[i].balance += input;
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
		if(accArray[i].ID==id){
			if(accArray[i].balance < output)
			{
				cout<<"오류! 출금하려는 돈이 보유 돈보다 적음!"<<endl;
				return;
			}
			
				accArray[i].balance -= output;
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
		cout<<"계좌ID: "<<accArray[i].ID<<endl;
		cout<<"이 름: "<<accArray[i].name<<endl;
		cout<<"잔 액: "<<accArray[i].balance<<endl<<endl;
	}
}