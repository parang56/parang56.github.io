#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
	char str[30];
public:
	void SetString(const char *s);
	void ShowString();
};

void Printer::SetString(const char *s)
{
	strcpy(str,s);
}

void Printer::ShowString()
{
	cout<<str<<endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello World");
	pnt.ShowString();
	
	pnt.SetString("I Love C++");
	pnt.ShowString();
	return 0;
}