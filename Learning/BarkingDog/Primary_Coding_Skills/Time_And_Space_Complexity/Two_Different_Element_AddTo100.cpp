#include <iostream>
using namespace std;

int func2(int arr[], int N) //시간 복잡도 O(N^2)
{
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(arr[i]+arr[j]==100)
				return 1;
	return 0;
}

int main(void)
{
	int arr1[3]={1,52,48};
	int arr2[2]={50,42};
	int arr3[4]={4,13,63,87};
	printf("%d\n",func2(arr1,3));
	printf("%d\n",func2(arr2,2));
	printf("%d\n",func2(arr3,4));
	return 0;
}