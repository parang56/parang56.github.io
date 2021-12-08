#include <iostream>
int main()
{
	int GooGooDan;
	std::cout<<"구구단 출력할 숫자: ";
	std::cin>>GooGooDan;
	for(int i=1;i<10;i++)
	{
		std::cout<<GooGooDan*i<<std::endl;
	}
	return 0;
}