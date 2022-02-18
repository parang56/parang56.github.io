#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if(num1 < num2) //a가 b보다 작을 때는 -1 반환
        return -1;
    
    if(num1 > num2) //a가 b보다 클 때는 1 반환
        return 1;
    
    return 0; //a와 b가 같을 때는 0 반환
}

int lower_binary_search(int arr[], int target, int size) //하한
{
	int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start)
	{
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int upper_binary_search(int arr[], int target, int size) //상한
{
	int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start)
	{
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else start = mid + 1;
    }
    return end;
}

int main(void)
{
    int lower, upper, mid;
	int N,M;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&M);
	int data[M],res[M];
	for(int i=0;i<M;i++)
	{
		scanf("%d",&data[i]);
		res[i]=0;
	}
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int),compare);
	for (int i = 0; i < M; i++) 
	{
        lower = lower_binary_search(arr, data[i], N);
        upper = upper_binary_search(arr, data[i], N);
        if (upper == N - 1 && arr[N - 1] == data[i])
            upper++;
        res[i] = upper - lower;
    }
	for (int i=0; i<M; i++)
        printf("%d ",res[i]);

    return 0;
}