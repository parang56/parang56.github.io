/*
	Banking Project/ AccountHandler.h Ver.07
	업데이트(2021,12,25)
	By: 둠치킨
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

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

#endif