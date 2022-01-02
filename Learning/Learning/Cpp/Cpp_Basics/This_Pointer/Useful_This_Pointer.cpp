#include <iostream>
using namespace std;

//this의 특성을 활용해 매개변수의 이름을 멤버변수의 이름과 달리할 필요가 없음을 보여주는 예제.

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1,int num2) //여기에 있는 num1(매개변수)은
	{
		this->num1=num1; //this->num1(멤버변수)의 num1과 일치하지 않는다. 위의 num1은 '=num1'과 일치.
		this->num2=num2; //따라서 매개변수 num1,num2을 통해 전달된 값이 멤버변수 num1,num2에 저장된다.
	} //원래라면 헷갈리지 않게 매개변수의 num1 혹은 멤버변수의 this->num1 중 num1 하나를 다른 이름으로 함.
	/*
	TwoNumber(int num1,int num2)
		: num1(num1), num2(num2)
	{
		//empty     -> 멤버 이니셜라이저에서는  this 포인터 사용할 수 없다.
						//대신에 저장하는 변수는 멤버변수로, 저장되는 값(소괄호 안의 변수 및 상수는)
						//매개변수로 인식하기 때문에 18~25행의 형태도 가능하다. 즉 18행은 12행 대신 가능.
	}
	*/
	
	void ShowTwoNumber()
	{
		cout<<this->num1<<endl; //this포인터를 사용함으로써, 멤버변수에 접근함을 명확히함.(굳이?)
		cout<<this->num2<<endl; //그러나, 일반적으로는 이런 경우에 this 포인터 생략해서 표현한다.
	}
};

int main(void)
{
	TwoNumber two(2,4);
	two.ShowTwoNumber();
	return 0;
}