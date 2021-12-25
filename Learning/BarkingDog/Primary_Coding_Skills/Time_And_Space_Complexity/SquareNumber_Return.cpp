#include <iostream>
using namespace std;

/*
int func3(int n) //시간 복잡도 아마도 O(N)
{
	for(int i=1;i<n;i++)
		if(i*i==n)
			return 1;
	return 0; //직접 n까지 안 가고 i*i가 n까지 가는거 확인하는게 당연하지... ㅠㅠ
}
*/

int func3(int n) //시간 복잡도 O(루트N)
{
	for(int i=1;i*i<=n;i++)
	{
		if(i*i==n)
			return 1;
	}
	return 0;
}

int main(void)
{
	cout<<func3(9)<<endl;
	cout<<func3(693953651)<<endl;
	cout<<func3(756580036)<<endl;
	return 0;
}