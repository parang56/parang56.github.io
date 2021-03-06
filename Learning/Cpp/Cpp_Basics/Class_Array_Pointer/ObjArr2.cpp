#include <iostream>
using namespace std;

class Student
{
private:
	char name[10];
	int age;
	int studentID;
public:
	Student() { cout << "생성자 호출!" << endl; }
	
	void SetInfo(char * _name, int _age, int _studentID)
	{
		strcpy(name, _name);
		age = _age;
		studentID = _studentID;
	}
	
	void GetInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
		cout << "학번: " << studentID << endl;
	}
	~Student() { cout << "소멸자 호출!" << endl; }
};

int main()
{
	Student student[5];
	char name[10];
	int age, studentID;
	
	for(int i=0; i<5; i++)
	{
		cin >> name >> age >> studentID;
		student[i].SetInfo(name, age, studentID);
	}
	
	for(int i=0; i<5; i++)
		student[i].GetInfo();
}