//그냥 단순 배열 풀이
//마지막 출력 후 공백이 있으면 안됨 -> 마지막 출력만 따로
//답은 맞췄지만 -> 시간 초과! 다른 풀이가 필요함.

#include <stdio.h>
int main(void)
{
	int N,chk=0;
	scanf("%d",&N);
	int arr[N];
	
	for(int i=0;i<N-1;i++)
	{
		chk=0; //초기화
		scanf("%d",&arr[i]);
		//매 for문 반복마다 arr[0]~arr[i]까지 arr[i]보다 큰 값 있는지 확인
		for(int j=i;j>=0;j--)
		{
			if(arr[j]>arr[i])
			{
				printf("%d ",j+1);
				chk=1;
				break;
			}
		}
		//arr[j]>arr[i]가 없는 경우
		if(chk==0)
			printf("0 ");
	}
	
	//마지막 출력만 따로
	scanf("%d",&arr[N-1]);
	chk=0;
	for(int i=N-1;i>=0;i--)
	{
		if(arr[i]>arr[N-1])
		{
			printf("%d\n",i+1);
			chk=1;
			break;
		}
	}
	if(chk==0)
		printf("0\n");
	return 0;	
}


//그냥 단순 배열 풀이
//malloc, free 추가

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int N,chk=0;
	scanf("%d",&N);
	int *p_arr; //포인터 변수
	p_arr = (int*)malloc(sizeof(int)*N); //메모리공간 할당
	
	for(int i=0;i<N;i++)
		scanf("%d",&p_arr[i]);
	for(int i=0;i<N;i++)
	{
		chk=0; //초기화
		//매 for문 반복마다 p_arr[0]~p_arr[i]까지 p_arr[i]보다 큰 값 있는지 확인
		for(int j=i;j>=0;j--)
		{
			if(p_arr[j]>p_arr[i])
			{
				printf("%d ",j+1);
				chk=1;
				break;
			}
		}
		//p_arr[j]>p_arr[i]가 없는 경우
		if(chk==0)
			printf("0 ");
	}
	free(p_arr);
	return 0;	
}