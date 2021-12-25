// num==0 이면 pop, num!=0 이면 push
// pop>push 인 경우는 생각안한다 (보장되어있음)
// 합을 구해야하므로 pop할때 sum-=stk[stkindex], push할때 sum+=num

#include <stdio.h>
#define MAX 100000

int stk[MAX];
int sum=0, stkindex=-1;

void pop()
{
	sum-=stk[stkindex--];
}

void push(int num)
{
	stk[++stkindex]=num;
	sum+=num;
}

int main(void)
{
	int N,num;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&num);
		if(num==0)
			pop();
		else
			push(num);
	}
	printf("%d\n",sum);
	return 0;
}