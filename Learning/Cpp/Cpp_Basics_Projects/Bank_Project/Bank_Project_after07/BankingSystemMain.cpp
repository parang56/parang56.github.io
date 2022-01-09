/*
	Banking Project/ BankingSystemMain.cpp Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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