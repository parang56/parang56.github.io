#include <iostream>
using namespace std;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout<<"객체생성"<<endl;
	}
	SelfRef& Adder(int n) //반환형과 반환 내용을 함께 살펴야함. 반환 내용은 *this인데, 이는 이 문장을 실행하는 객체 자신의 포인터가 아닌,
		//객체 자신을 반환하겠다는 의미가 된다. 그런데 반환형이 참조형 SelfRef&으로 선언. 따라서, 객체 자신을 참조할 수 있는
		// '참조의 정보(이하 '참조 값'이라 표현하겠다)'가 반환된다.
	{
		num+=n;
		return *this;
	}
	SelfRef& ShowTwoNumber() //13행과 마찬기자로 객체 자신을 참조할 수 있는 참조 값을 반환하도록 정의됨.
	{
		cout<<num<<endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);
	SelfRef &ref=obj.Adder(2); //객체 obj의 Adder함수를 호출. 그런데 이 함수는 객체 자신의 참조 값을 반환. 즉, 객체 obj의 참조 값을 반환.
	//따라서 참조자 ref는 객체 obj를 참조하게 된다.
	
	obj.ShowTwoNumber(); //33~34행은 30행에서 일어나는 일을 확인하기 위해 객체에 저장된 값을 출력하고 있다.
	ref.ShowTwoNumber();
	
	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber(); //먼저 객체 ref의 Adder함수가 호출. 그런데 Adder함수는 참조 값을 반환하므로,
	//반환된 참조 값을 이용해서 다시 ShowTwoNumber 함수를 호출하게 된다. 그리고 마찬가지로 반환되는 참조 값을 이용해서 다시 Adder 함수를 호출하고,
	//또 이어서 ShowTwoNumber함수를 호출한다. 이는 두 함수 Adder와 ShowTwoNumber가 객체의 참조 값을 바환하기 때문에 구성이 가능한 문장이다.
	return 0;
}
//ref.Adder(1).ShowTwoNumber() -> (ref 참조자) 
//(ref 참조자).Adder(2) -> 반환된 참조 값으로 ShowTwoNumber 호출 후 8 출력.