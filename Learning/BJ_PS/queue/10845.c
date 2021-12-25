#include <stdio.h>
#include <string.h>
#define MAX 10000
int Stack[MAX];
int top=-1;

void push(int n)
{
	Stack[++top]=n;
}

int size()
{
	return top+1;
}

int empty()
{
	if(top<0)
		return 1;
	return 0;
}

void pop()
{
	if(empty()==1)
		printf("-1\n");
	else
	{
		printf("%d\n",Stack[0]);
		for(int i=1;i<=top;i++)
			Stack[i-1]=Stack[i];
		Stack[top--];
	}
}

void front()
{
	if(empty()==1)
		printf("-1\n");
	else
		printf("%d\n",Stack[0]);
}

void back()
{
	if(empty()==1)
		printf("-1\n");
	else
		printf("%d\n",Stack[top]);
}

int main(void)
{
	int N;
	char arr[20];
	scanf("%d",&N);
	int Stack[N];
	while(N--)
	{
		scanf("%s",arr);
		if(strcmp(arr,"push")==0)
		{
			int num;
			scanf("%d",&num);
			push(num);
		}
		if(strcmp(arr,"size")==0)
			printf("%d\n",size());
		if(strcmp(arr,"empty")==0)
			printf("%d\n",empty());
		if(strcmp(arr,"pop")==0)
			pop();
		if(strcmp(arr,"front")==0)
			front();
		if(strcmp(arr,"back")==0)
			back();
	}
	return 0;
}