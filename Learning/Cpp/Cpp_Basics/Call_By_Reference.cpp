#include <iostream>
using namespace std;

void add_one(int &num);
void switch_pm(int &num);

int main(void)
{
	int num;
	cout<<"숫자를 입력하세요: ";
	cin>>num;
	add_one(num);
	cout<<"숫자에 1을 더합니다: "<<num<<endl;
	switch_pm(num);
	cout<<"숫자의 부호를 바꿉니다: "<<num<<endl;
	
	return 0;
}

void add_one(int &num)
{
	num += 1;
}

void switch_pm(int &num)
{
	num *= -1;
}