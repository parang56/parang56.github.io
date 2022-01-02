#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout<<"num="<<num<<", ";
		cout<<"address="<<this<<endl;
	}
	void ShowSimpleData()
	{
		cout<<num<<endl;
	}
	SoSimple * GetThisPointer()
	{
		return this; //this 반환. 문장을 실행하는 객체의 포인터를 반환하라는 의미. 그래서 반환형도 SoSimple* 형으로 선언
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple * ptr1=sim1.GetThisPointer(); //객체 sim1에 의해 반환된 this를 ptr1에 저장. 이 때 this는 SoSimple의 
	//포인터이므로 SoSimple형 포인터 변수에 저장해야 한다.
	cout<<ptr1<<", "; //ptr1에 저장된 주소 값을 출력하고 있다.
	ptr1->ShowSimpleData(); //ptr1이 가리키는 객체의 ShowSimpleData 함수를 호출하고 있다.
	
	SoSimple sim2(200);
	SoSimple * ptr2=sim2.GetThisPointer();
	cout<<ptr2<<", ";
	ptr2->ShowSimpleData();	
	return 0;
}