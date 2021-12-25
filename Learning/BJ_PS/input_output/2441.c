#include <stdio.h>

int main()
{
	int N,tmp;
	scanf("%d",&N);
	tmp = N;
	while(N>0)
	{
		for(tmp; tmp>N;tmp--)
		{
			printf(" ");
		}
		for(int i=0; i<N; i++)
		{
			printf("*");
		}
		N--;
		printf("\n");
	}
	return 0;
}