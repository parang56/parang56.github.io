#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char *name;
	int age;
public:
	MyFriendInfo(char *myname, int myage) : age(myage)
	{
		name=new char[strlen(myname)+1];
		strcpy(name, myname);
	}
	
	void ShowMyFriendInfo()
	{
		cout<<"이름: "<<name<<endl;
		cout<<"나이: "<<age<<endl;
	}
	
	~MyFriendInfo()
	{
		delete []name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(char *myname, int myage, char *myaddr, char *myphone)
		: MyFriendInfo(myname, myage)
	{
		addr=new char[strlen(myaddr)+1];
		strcpy(addr,myaddr);
		phone=new char[strlen(myphone)+1];
		strcpy(phone,myphone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout<<"주소: "<<addr<<endl;
		cout<<"전화: "<<phone<<endl<<endl;
	}
	~MyFriendDetailInfo()
	{
		delete []addr;
		delete []phone;
	}
};

int main(void)
{
	MyFriendDetailInfo fr1("ParkGun",22,"Gundae","01033334444");
	fr1.ShowMyFriendDetailInfo();
	MyFriendDetailInfo fr2("Hyunsung",22,"Gundae","01055556666");
	fr2.ShowMyFriendDetailInfo();
	return 0;
}