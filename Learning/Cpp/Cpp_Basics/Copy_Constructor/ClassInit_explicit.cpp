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
	
	explicit SoSimple(SoSimple &copy) // explicit을 사용하므로 디폴트 복사 생성자가 없어져서 실행이 불가능해짐.
		: num1(copy.num1), num2(copy.num2)
	{
		cout<<"Called SoSimple(SoSimple &copy)"<<endl;	// -> 디폴트 복사 생성자 떄문에 SoSimple(SoSimple &copy)가 없어도 자동으로 삽입되서 실행 가능.
	} 
	
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