#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum{CLERK, SENIOR,ASSIST,MANAGER};
	
	void ShowPositionInfo(int pos)
	{
		switch(pos)
		{
			case CLERK:
				cout<<"사원"<<endl;
				break;
			case SENIOR:
				cout<<"주임"<<endl;
				break;
			case ASSIST:
				cout<<"대리"<<endl;
				break;
			case MANAGER:
				cout<<"과장"<<endl;
				break;	
		}
	}
}

class NameCard
{
private:
	char *name;
	char *com_name;
	char *phone_num;
	int job;
	
public:
	NameCard(char *myname, char *my_com_name, char *my_phone_num, int my_job)
		: job(my_job)
	{
		this->name = new char[strlen(myname)+1];
		this->com_name = new char[strlen(my_com_name)+1];
		this->phone_num = new char[strlen(my_phone_num)+1];
		strcpy(this->name, myname);
		strcpy(this->com_name, my_com_name);
		strcpy(this->phone_num, my_phone_num);
		//this-> = (*this). = 자기 자신의 값 자체를 가리키는. 없어도 상관없긴 하지만 쓸데가 있긴함.
		/*
		TwoNumber(int num1,int num2) //여기에 있는 num1(매개변수)은
		{
			this->num1=num1; //this->num1(멤버변수)의 num1과 일치하지 않는다. 위의 num1은 '=num1'과 일치.
			this->num2=num2; //따라서 매개변수 num1,num2을 통해 전달된 값이 멤버변수 num1,num2에 저장된다.
		} //원래라면 헷갈리지 않게 매개변수의 num1 혹은 멤버변수의 this->num1 중 num1 하나를 다른 이름으로 함.
		*/
		
	}
	
	NameCard(const NameCard& copy)
		: job(copy.job)
	{
		name = new char[strlen(copy.name)+1];
		strcpy(name, copy.name);
		com_name = new char[strlen(copy.com_name)+1];
		strcpy(com_name, copy.com_name);
		phone_num = new char[strlen(copy.phone_num)+1];
		strcpy(phone_num, copy.phone_num);
	}
	
	void ShowNameCardInfo();
	
	~NameCard()
	{
		delete []name;
		delete []com_name;
		delete []phone_num;
		cout<<"called destructor!"<<endl;
	}
};

void NameCard::ShowNameCardInfo()
{
	cout<<"이름: "<<name<<endl;
	cout<<"회사: "<<com_name<<endl;
	cout<<"전화번호: "<<phone_num<<endl;
	cout<<"직급: "; 
	COMP_POS::ShowPositionInfo(job);
	cout<<endl;
}

int main(void)
{
	NameCard manClerk("Lee", "ABCeng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1=manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2=manSENIOR;
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	return 0;
}