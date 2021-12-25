#include <stdio.h>
#include <string.h>
#define MAX 100001

int Stack[MAX];
int topnum=-1;

void push(int n)
{
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

void empty()
{
	if(topnum<0)
	{
		printf("1\n");
	}
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