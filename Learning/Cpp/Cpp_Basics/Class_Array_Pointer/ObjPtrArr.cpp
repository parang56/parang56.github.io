#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len=strlen(myname)+1;
		name = new char[len];
		strcpy(name, myname);
		age=myage;
	}
	Person() //배열 생성시 필요한 생성자를 추가하였다. -> 위 Person(char *myname, int myage){~} 함수의 초기화 담당? 
	{
		cout<<"called Person()"<<endl;
	}
	/*void SetPersonInfo(char *myname, int myage) //원하는 데이터로의 초기화를 목적으로 정의된 함수.
	{
		name=myname;
		age=myage;
	}*/
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
	Person * parr[3]; //포인터 배열 선언, 객체의 주소 값 3개 저장할 수 있는 배열.
	char namestr[100];
	int age;
	
	for(int i=0; i<3; i++) //49~58행은 반복문 안에서 이름,나이 정보를 입력 받아 객체를 초기화하고 있다.
	{
		cout<<"이름: ";
		cin>>namestr;
		cout<<"나이 ";
		cin>>age;
		parr[i]=new Person(namestr, age); //객체를 생성해서, 이 객체의 주소 값을 배열에 저장하고 있다.
	}
	
	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();
	delete parr[0]; //28~31, 총 3회에 걸쳐서 new 연산 했으므로 총 3회에 걸쳐 delete 연산을 진행해야 한다.
	delete parr[1];
	delete parr[2];
	return 0;
}