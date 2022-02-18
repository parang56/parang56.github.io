#include <stdio.h>

int main(void)
{
	int N;
	int cnt=0;
	scanf("%d",&N);
	while(N!=1)
	{
		int tmp = N-1;
		if(N%3==0)
		{
			N/=3; cnt++;
			continue;
		}
		else if(tmp%3==0)
		{
			N-=1; cnt++;
			N/=3; cnt++;
		}
		else if(N%2==0)
		{
			N/=2; cnt++;
			continue;
		}
	}
	printf("%d\n",cnt);
	return 0;
}