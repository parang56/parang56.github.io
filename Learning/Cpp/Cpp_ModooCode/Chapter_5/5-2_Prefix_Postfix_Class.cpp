#include <iostream>

class Test
{
private:
	int x;

public:
	Test(int x) : x(x) { }
	Test(const Test& t) : x(t.x) { }
	
	Test& operator++()
	{
		x++;
		std::cout<<"전위 증감 연산자"<<'\n';
		return *this;
	}
	
	//전위 증감과 후의 증감에 차이를 두기 위해 인자로 int (오버로딩)
	Test operator++(int)
	{
		Test temp(*this);
		x++;
		std::cout<<"후의 증감 연산자"<<'\n';
		return temp;
	}
	
	int get_x() const
	{
		return x;
	}
};

void func(const Test& t)
{
	std::cout<<"x : "<<t.get_x()<<'\n';
}

int main(void)
{
	Test t(3);
	
	func(++t); //4
	func(t++); //4
	std::cout<<"x : "<<t.get_x()<<'\n';
	
	return 0;
}