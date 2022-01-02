//EmployeeManager1.cpp는 Inheritance 폴더 안에 있다!
//EmployeeManager2.cpp는 EmployeeManager3.cpp안에 포함되므로 생략하겠다!

//GetPay 함수와 ShowSalaryInfo 함수를 Virtual로 선언하였으므로,
//EmployeeHandler가 호출하는 함수는 Employee 클래스의 멤버함수일지라도
//실제 호출되는 함수는 각 포인터가 가리키는 객체의 마지막 오버라이딩 함수!!
//->마지막 오버라이딩 함수: SalesWorker(PermanentWorker(Employee)), TemporaryWorker(Employee) 
//->PermanentWorker로 호출해도 SalesWorker의 GetPay와 ShowSalaryInfo가 호출.

//이렇듯 상속은 연관된 일련의 클래스들에 대해 공통의 규약을 적용할 수 있게 해준다!!

#include <iostream>
#include <cstring>
using namespace std;

class Employee //하나 이상의 순수 가상함수를 멤버로 두면 객체 생성이 불가능해진다! -> 이런 클래스는 추상 클래스라한다!!
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
	/*
	virtual int GetPay() const //virtual 선언!!
	{
		return 0;
	}
	virtual void ShowSalaryInfo() const //virtual 선언!!
	{ }
	*/
	//위의 두 함수는 실제로 몸체가 필요하지 않다! -> 순수 가상함수로 대체 가능!
	//그리고 모든 함수는 호출(객체생성)에 의미를 두지 않을 수도 있다는 것을 여기서 알 수 있다!
	virtual int GetPay() const = 0; //=0; -> 몸체 생략하겠다는 표현.
	virtual void ShowSalaryInfo() const = 0;
	
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
		for(int i=0;i<empNum;i++)
			empList[i]->ShowSalaryInfo(); //virtual 없으면 컴파일 오류 이유: empList는 Employee의 포인터, 그래서 Employee클래스만 볼 수 있음
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		for(int i=0;i<empNum;i++)
		sum+=empList[i]->GetPay();
		cout<<"salary sum: "<<sum<<endl;
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