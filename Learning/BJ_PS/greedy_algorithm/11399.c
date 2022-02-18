#include <stdio.h>
#include <stdlib.h>

//내림차순 compare 함수
int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
	
    if (num1 < num2) //뒤에 있는게 크면 1 (바꿈)
        return 1;
    if (num1 > num2) //앞에 있는게 크면 -1 (안 바꿈)
        return -1;
    return 0; // a==b
}

int main(void)
{
	int N, sum=0;
	scanf("%d",&N);
	int arr[N];
	
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	
	qsort(arr,sizeof(arr)/sizeof(int),sizeof(int),compare);
	
	for(int i=1;i<=N;i++)
		sum += i*arr[i-1];
	printf("%d\n",sum);
	
	return 0;
}