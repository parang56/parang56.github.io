//숫자를 한번에 스캔 받아서 arr에 넣은 다음 arr와 stack을 비교해가면서 결과를 도출
//stack[top]이 arr[idx] 보다 낮으면 push, 같으면 pop, 크면 "NO"

#include <stdio.h>
#define MAX 100000

int stack[MAX];
char res[MAX*2];
int top=-1;

int main(void)
{
	int n,num=0,idx=0,res_idx=0;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int k=n*2;
	while(k--) //while(0)이 되면 바로 멈춤
	{
		//stack[top]이 arr[idx]보다 낮은 경우 (push)
		if(top==-1 || stack[top]<arr[idx])
		{
			stack[++top]=++num; //push
			res[res_idx++]='+';
		}
		
		//stack[top]이 arr[idx]와 같은 경우 (pop)
		else if(stack[top] == arr[idx])
		{
			top--; //pop
			res[res_idx++]='-';
			idx++; //배열의 다음 숫자로 넘어감
		}
		
		//stack[top]이 arr[idx]보다 큰 경우 ("NO")
		else
		{
			printf("NO"); //수열을 만들 수가 없음
			return 0;
		}
	}
	
	for(int i=0;i<res_idx;i++)
		printf("%c\n",res[i]);
	return 0;
}