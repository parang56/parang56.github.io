//스택을 배열로 구현하기

//push X: 정수 X를 스택에 넣는 연산이다.
//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 스택에 들어있는 정수의 개수를 출력한다.
//full: 스택이 꽉 찼으면 1, 아니면 0을 출력한다.
//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <string.h>
#define MAX 100000

int Stack[MAX];
int topnum=-1;

void push(int n)
{
	/*
	if(topnum+1==MAX)
	{
		printf("스택이 꽉참\n!!");
		return;
	}
	*/
	//main에서 몇 개의 명령을 입력 받을건지 안 정하고 하는거면 위 if문이 있어야 안전하게 돌아간다.
	Stack[++topnum]=n;
}

int pop()
{
	if(topnum<0)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		printf("%d\n",Stack[topnum]);
		return Stack[topnum--];
	}
}

void size()
{
	printf("%d\n",topnum+1);
}

void full()
{
	if(topnum==MAX-1)
		printf("1\n");
	else
		printf("0\n");
}

void empty()
{
	if(topnum<0)
		printf("1\n");
	else
		printf("0\n");
}

void top()
{
	if(topnum<0)
	{
		printf("-1\n");
	}
	else
		printf("%d\n",Stack[topnum]);
}

int main(void)
{
	char Get_Com[10];
	int N,pushnum;
	scanf("%d",&N);
	int Stack[N];
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"push")==0)
		{
			scanf("%d",&pushnum);
			push(pushnum);
		}
		else if(strcmp(Get_Com,"pop")==0)
			pop();
		else if(strcmp(Get_Com,"size")==0)
			size();
		else if(strcmp(Get_Com,"empty")==0)
			empty();
		else if(strcmp(Get_Com,"top")==0)
			top();
	}
	return 0;
}