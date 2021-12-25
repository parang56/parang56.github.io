#include <iostream>
using namespace std;

class Calculator
{
private:
	int Addcount;
	int Mincount;
	int Divcount;
	int Mulcount;
public:
	void Init();
	double Add(double num1, double num2);
	double Min(double num1, double num2);
	double Div(double num1, double num2);
	double Mul(double num1, double num2);
	void ShowOpCount() const;
};

void Calculator::Init()
{
	Addcount=0;
	Mincount=0;
	Divcount=0;
	Mulcount=0;
}

double Calculator::Add(double num1, double num2)
{
	Addcount++;
	return num1+num2;
}

double Calculator::Min(double num1, double num2)
{
	Mincount++;
	return num1-num2;
}

double Calculator::Div(double num1, double num2)
{
	if(num2==0)
	{
		cout<<"오류! 분모는 0이 될 수 없음!"<<endl;
		exit(0);
	}
	Divcount++;
	return num1/num2;
}

double Calculator::Mul(double num1, double num2)
{
	Mulcount++;
	return num1*num2;
}

void Calculator::ShowOpCount() const
{
	cout<<"더하기 횟수: "<<Addcount<<' ';
	cout<<"뺴기 횟수: "<<Mincount<<' ';
	cout<<"나누기 횟수: "<<Divcount<<' ';
	cout<<"곱하기 횟수: "<<Mulcount<<endl;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount();
	return 0;
}