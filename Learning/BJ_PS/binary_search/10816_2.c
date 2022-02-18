#include <stdio.h>

int arr[20000001];

int main(void)
{
	int N,M,num;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&num);
		arr[num+10000000]++;
	}
	scanf("%d",&M);
	int data[M];
	for(int i=0;i<M;i++)
		scanf("%d",&data[i]);
	for(int i=0;i<M;i++)
		printf("%d ",arr[data[i]+10000000]);

    return 0;
}