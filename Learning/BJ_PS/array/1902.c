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

int binary_search(int num, int arr[], int low, int high)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//탐색 성공
		if (num == arr[mid])
			return 1;
		
		// 탐색 범위 재조정 low ~ mid-1
		else if (num < arr[mid])
			high = mid - 1;
		
		// 탐색 범위 재조정 mid+1 ~ high	
		else if (num > arr[mid])
			low = mid + 1;
	}
	return 0;
}

int main(void)
{
    int low,high,mid;
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
		printf("%d\n",binary_search(data[i], arr, low, high));
	
    return 0;
}