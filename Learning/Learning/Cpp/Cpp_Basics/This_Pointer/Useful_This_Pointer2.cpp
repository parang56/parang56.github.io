#include <iostream>
using namespace std;

//this 포인터

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	/*TwoNumber(int num1,int num2)
	{
		this->num1=num1;
		this->num2=num2;
	}*/
	TwoNumber(int num1,int num2)
		: num1(num1), num2(num2)
	{
		//empty     -> 멤버 이니셜라이저에서는  this 포인터 사용할 수 없다.
		//대신에 저장하는 변수는 멤버변수로, 저장되는 값(소괄호 안의 변수 및 상수는)
		//매개변수로 인식하기 때문에 이러한 표현도 가능하다.
	}
	
	void ShowTwoNumber()
	{
		cout<<this->num1<<endl; //this포인터를 사용하면 멤버변수에 접근함을 명확히할 수 있지만
		cout<<num2<<endl; //일반적으로는 이런 경우에 this 포인터 생략해서 표현하므로 생략함.
	}
};

int main(void)
{
	TwoNumber two(2,4);
	two.ShowTwoNumber();
	return 0;
}