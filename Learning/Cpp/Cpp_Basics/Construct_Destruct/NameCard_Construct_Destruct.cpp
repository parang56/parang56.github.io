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
		name = new char[strlen(myname)+1];
		com_name = new char[strlen(my_com_name)+1];
		phone_num = new char[strlen(my_phone_num)+1];
		strcpy(name, myname);
		strcpy(com_name, my_com_name);
		strcpy(phone_num, my_phone_num);
	}
	
	void ShowNameCardInfo();
	
	~NameCard()
	{
		delete []name;
		delete []com_name;
		delete []phone_num;
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
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manASSIST("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manASSIST.ShowNameCardInfo();
	return 0;
}