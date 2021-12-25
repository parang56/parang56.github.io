#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
		{
			//empty
		}
	
	/*	: num1(-1*n1), num2(n2)
		{
			//장난질: num1 받을 때 음수로 받기
		}	*/
	
	/*	: num1(n2), num2(n1)
		{
			//장난질: num1과 num2를 바꿔서 받기
		}	*/
	
	/*SoSimple(SoSimple &copy)
		: num1(copy.num1), num2(copy.num2)
	{
		cout<<"Called SoSimple(SoSimple &copy)"<<endl;	// -> 디폴트 복사 생성자 떄문에 SoSimple(SoSimple &copy)가 없어도 자동으로 삽입되서 실행 가능.
	} 
	*/
	
	void ShowSimpleData()
	{
		cout<<num1<<endl;
		cout<<num2<<endl;
	}
};

int main(void)
{
	SoSimple sim1(15,30);
	cout<<"생성 및 초기화 직전"<<endl;
	SoSimple sim2=sim1; // SoSimple sim2(sim1); 으로 변환!
	cout<<"생성 및 초기화 직후"<<endl;
	sim2.ShowSimpleData();
	return 0;
}