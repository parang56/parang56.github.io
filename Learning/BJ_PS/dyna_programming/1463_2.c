#include <stdio.h>
#define MAX 1000001
 
int N;
int arr[MAX];

int MIN(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	scanf("%d",&N);
    int tmp;
    for (int i=2;i<=N;i++) //arr[0]=arr[1]=1
	{
        arr[i]=arr[i-1]+1;
        if (i%3==0)
		{
            tmp=arr[i/3]+1;
            arr[i]=MIN(arr[i],tmp);
        }
        if (i%2==0)
		{
            tmp=arr[i/2]+1;
            arr[i]=MIN(arr[i],tmp);
        }
    }
    printf("%d\n", arr[N]);
}