//EmployeeManager1.cpp는 Inheritance 폴더 안에 있다!
//EmployeeManager2.cpp는 EmployeeManager3.cpp안에 포함되므로 생략하겠다!


#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(char *name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name<<endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary; //월 급여
public:
	PermanentWorker(char *name, int money)
		: Employee(name), salary(money)
	{ }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime; //이 달에 일한 시간의 합계
	int payPerHour; //시간당 급여
public:
	TemporaryWorker(char *name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time) //일한 시간 추가
	{
		workTime+=time;
	}
	int GetPay() const //이 달의 급여
	{ 
		return workTime*payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult; //월 판매실적
	double bonusRatio; //상여급 비율
public:
	SalesWorker(char *name, int money, double ratio)
		: PermanentWorker(name, money),salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult+=value;
	}
	int GetPay() const //PermanentWorker 클래스의 ShowSalaryInfo 함수 오버라이딩
	{
		return PermanentWorker::GetPay() //PermanentWorker의 GetPay 함수 호출
					+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const //PermanentWorker 클래스의 ShowSalaryInfo 함수 오버라이딩, ShowSalaryInfo함수를 여기서 정의 안하면 PermanentWorker의 GetPay함수가 호출된다.
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl; //SalesWorker의 GetPay 함수가 호출됨
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		/*
		for(int i=0;i<empNum;i++)
			empList[i]->ShowSalaryInfo(); //virtual 없으면 컴파일 오류 이유: empList는 Employee의 포인터, 그래서 Employee클래스만 볼 수 있음
		*/
	}
	void ShowTotalSalary() const
	{
		/*
		int sum=0;
		for(int i=0;i<empNum;i++)
		sum+=empList[i]->GetPay();
		cout<<"salary sum: "<<sum<<endl;
		*/
	}
	~EmployeeHandler()
	{
		for(int i=0;i<empNum;i++)
			delete empList[i];
	}
};

int main(void)
{
	//직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;
	
	//직원 등록
	handler.AddEmployee(new PermanentWorker("KIM",1000));
	handler.AddEmployee(new PermanentWorker("LEE",1500));
	handler.AddEmployee(new PermanentWorker("JUN",2000));
	
	//이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	
	//이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}