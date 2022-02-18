#include <stdio.h>
int main(void)
{
	int T,a,b;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d %d",&a,&b);
		int tmp=1;
		for(int j=0;j<b;j++)
		{
			tmp*=a;
			tmp%=10;
		}
		if(tmp==0)
			printf("10\n");
		else
			printf("%d\n",tmp);
	}
	return 0;
}