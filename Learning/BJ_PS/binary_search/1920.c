#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if(*(int *)a < *(int *)b)
		return -1;
	if(*(int *)a > *(int *)b)
		return 1;
	return 0;
}

int binary_search(int num, int arr[], int low, int high)
{
	int mid, res=0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(num == arr[mid])
			res+=1;
		else if(num < arr[mid])
			high = mid-1;
		else if(num > arr[mid])
			low = mid+1;
	}
	return res;
}

int main(void)
{
	int low=0, high, mid;
	int N,M;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&M);
	int data[M];
	for(int i=0;i<M;i++)
		scanf("%d",&data[i]);
	low=0;
	high=N;
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int),compare);
	for(int i=0;i<M;i++)
		printf("%d\n",binary_search(data[i],arr,low,high));
	return 0;
}