#include <iostream>
using namespace std;
/*
int func1(int n)
{
	int num1 = n-(n%3);
	int num2 = n-(n%5);
	int num3 = n-(n%15);
	int nnum1 = num1/3;
	int nnum2 = num2/5;
	int nnum3 = num3/15;
	int sum;
	for(int i=1;i<=nnum1;i++)
		sum+=num1/i;
	for(int i=1;i<=nnum2;i++)
		sum+=num2/i;
	for(int i=1;i<=nnum3;i++)
		sum-=num3/i;
	
	return sum;	
}
*/

int func1(int N) //시간 복잡도 O(N)
{
	int ret=0;
	for(int i=1;i<=N;i++)
	{
		if(i%3==0||i%5==0)
			ret+=i;
	}
	return ret;
}

int main(void)
{
	printf("%d\n",func1(16));
	printf("%d\n",func1(34567));
	printf("%d\n",func1(27639));
	return 0;
}