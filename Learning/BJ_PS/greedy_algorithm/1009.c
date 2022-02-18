#include <stdio.h>
#define MAX 1000000
int arr[MAX];

int main(void)
{
	int T, a, b, tmp, key=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		tmp=1;
		scanf("%d %d",&a, &b);
		for(int j=0;j<b;j++)
		{
			tmp*=a;
			tmp%=10;	
		}
		
		arr[key]=tmp;
		key++;
		if(arr[i]%10==0)
			printf("10\n");
		else
			printf("%d\n",arr[i]);
	}
	
	return 0;
}