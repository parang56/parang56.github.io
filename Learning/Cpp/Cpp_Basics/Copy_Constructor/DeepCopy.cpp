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
	Person(const Person& copy) //const -> 기존의 객체의 멤버 변수 값을 건드리지 않겠다
		: age(copy.age)
	{
		name=new char[strlen(copy.name)+1];
		strcpy(name, copy.name);
	}                              //17~22행, '깊은 복사'를 위한 복사 생성자의 정의
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
	man2.ShowPersonInfo();
	return 0;
}