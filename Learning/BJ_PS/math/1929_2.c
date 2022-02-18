#include <stdio.h>
int main(void)
{
	int m,n,i,j,arr[1000001]={0,};
    arr[0]=arr[1]=1;
	
	for(j=2; j<1000001/j; j++)
	{
		if(arr[j]==1) continue;
		for(i=j*j; i<1000001; i+=j)
			if(i%j==0) arr[i]==1;
	}
	scanf("%d %d", &m, &n);
	
	for(i=m; i<=n; i++)
        if(arr[i]==0)
            printf("%d\n",i);
	
	return 0;
}