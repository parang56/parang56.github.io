#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	/*Person(char *myname, int myage)
	{
		int len=strlen(myname)+1;
		name = new char[len];
		strcpy(name, myname);
		age=myage;
	}*/ //이미 있는 내용을 왜 굳이 또 넣은거지? 똑같이 잘 작동하는데.
	Person() //배열 생성시 필요한 생성자를 추가하였다.
	{
		cout<<"called Person()"<<endl; 
	}
	void SetPersonInfo(char *myname, int myage) //원하는 데이터로의 초기화를 목적으로 정의된 함수.
	{
		name=myname;
		age=myage;
	}
	void ShowPersonInfo() const
	{
		cout<<"이름: "<<name<<", ";
		cout<<"나이: "<<age<<endl;
	}
	~Person()
	{
		delete []name;
		cout<<"Called destructor!"<<endl;
	}
};

int main(void)
{
	Person parr[3];
	char namestr[100];
	char *strptr;
	int age;
	int len;
	
	for(int i=0; i<3; i++) //49~58행은 반복문 안에서 이름,나이 정보를 입력 받아 객체를 초기화하고 있다.
	{
		cout<<"이름: ";
		cin>>namestr;
		cout<<"나이 ";
		cin>>age;
		len=strlen(namestr)+1;
		strptr=new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}
	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
	return 0;
}