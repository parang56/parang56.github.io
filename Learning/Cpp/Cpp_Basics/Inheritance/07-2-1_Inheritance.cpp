#include <iostream>
using namespace std;

class Rectangle
{
private:
	int num1;
	int num2;
public:
	Rectangle(int mynum1, int mynum2) : num1(mynum1), num2(mynum2)
	{ }
	
	void ShowAreaInfo()
	{
		cout<<"면적: "<<num1*num2<<endl;
	}
};

class Square : public Rectangle
{
/*private:
	int num3;*/
//딱히 새로운 수가 필요가 없어서 private num3 선언할 필요가 없다.
public:
	Square(int mynum3)
		: Rectangle(mynum3,mynum3) // num3(mynum3)
	{ }
};

int main(void)
{
	Rectangle rec(4,3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}