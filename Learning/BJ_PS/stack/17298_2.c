#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

typedef struct Stack{
	int stack_arr[MAX];
	int size;
}Stack;

int empty(Stack *s)
{
	return s->size==0;
}

int top(Stack *s)
{
	return s->stack_arr[s->size-1];
}

void push(Stack *s, int num)
{
	s->stack_arr[s->size++]=num;
}

int pop(Stack *s)
{
	return s->stack_arr[--s->size];
}

int main(void)
{
	Stack* stack = (Stack *)malloc(sizeof(Stack));
	int N;
	scanf("%d",&N);
	int arr[N];
	int ans[N];
	for(int i=0;i<N;i++)
	{
		scanf("%d", &arr[i]);
		ans[i]=-1;
	}
	
	for(int i=0;i<N;i++)
	{
		while(!empty(stack) && arr[top(stack)] < arr[i])
			ans[pop(stack)] = arr[i];
		
		push(stack, i);
	}
	
	for(int i=0;i<N;i++)
		printf("%d ", ans[i]);
	
	return 0;
}