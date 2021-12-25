#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char * name;
	int age;
public:
	Person(char * myname, int myage)
	{
		int len=strlen(myname)+1;
		name=new char[len];
		strcpy(name, myname);
		age=myage;
	}
	void ShowPersonInfo() const
	{
		cout<<"이름: "<<name<<endl;
		cout<<"나이: "<<age<<endl;
	}
	~Person()
	{
		delete []name;
		cout<<"called destructor!"<<endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2=man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo(); //안되는게 일반적(online gcc compiler에선 안됨) -> 운영체제나 프로그램에 따라 되기도 하는데 문제가 있긴한거임.
	return 0;
}