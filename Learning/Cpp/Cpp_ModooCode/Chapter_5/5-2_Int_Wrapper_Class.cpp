#include <iostream>

class Int
{
private:
	int data;
public:
	Int(int data) : data(data) { }
	Int(const Int& i) : data(i.data) {}
	
	operator int() { return data; }
};

int main(void)
{
	Int x = 3;
	int a = x+ 4;
	
	x = a * 2 + x + 4;
	std::cout<<x<<'\n';
	
	return 0;
}