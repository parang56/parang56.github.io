#include <iostream>
using namespace std;

/*
int func4(int n)
{
	int k=1;
	for(int i=0;i<n;i++)
	{
		k=k*2;
		if(k>n)
			return k/2;
	}
	return 0;
}
*/

int func4(int n) //시간 복잡도는 O(logN) -> log는 밑이 2
{
	int val=1;
	while(2*val <= n)
		val*=2;
	return val;
}

int main(void)
{
	cout<<func4(5)<<endl;
	cout<<func4(97615282)<<endl;
	cout<<func4(1024)<<endl;
	return 0;
}