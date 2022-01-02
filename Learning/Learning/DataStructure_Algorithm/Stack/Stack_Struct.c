//스택을 구조체로 구현하기

//push X: 정수 X를 스택에 넣는 연산이다.
//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 스택에 들어있는 정수의 개수를 출력한다.
//full: 스택이 꽉 찼으면 1, 아니면 0을 출력한다.
//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include <stdio.h>
#include <string.h>
#define MAX 100000

typedef struct Stack{
	int arr[MAX];
	int top;
}Stack;

void InitStack(Stack *stack) //스택 초기화: top=-1
{
	stack->top=-1;
}

int full(Stack *stack)
{
	/*
	if(stack->top+1==MAX)
		return 1;
	return 0;
	*/
	return (stack->top+1)==MAX;
}

int empty(Stack *stack)
{
	/*
	if(stack->top==-1)
		return 1;
	return 0;
	*/
	return (stack->top)==-1;
}

int size(Stack *stack)
{
	return stack->top+1;
}

int top(Stack *stack)
{
	if(empty(stack)==1)
		return -1;
	return stack->top+1;
}

void push(Stack *stack, int num)
{
	/*
	if(stack->top+1==MAX)
	{
		printf("스택이 꽉참\n!!");
		return;
	}
	*/ 
	//main에서 몇 개의 명령을 입력 받을건지 안 정하고 하는거면 위 if문이 있어야 안전하게 돌아간다.
	
	stack->top++; //push하면 top 1씩 증가
	stack->arr[stack->top]=num; //num을 push한 위치에 저장
}

int pop(Stack *stack)
{
	if(stack->top==-1)
	{
		return -1;
	}
	int popnum = stack->arr[stack->top];
	stack->top--; //pop하면서 top 1씩 감소
	return popnum;
}

int main(void)
{
	Stack stack;
	InitStack(&stack); //stack 초기화
	char Get_Com[10];
	int N,pushnum;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"push")==0)
		{
			scanf("%d",&pushnum);
			push(&stack,pushnum);
		}
		else if(strcmp(Get_Com,"pop")==0)
			printf("%d\n",pop(&stack));
		else if(strcmp(Get_Com,"size")==0)
			printf("%d\n",size(&stack));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(&stack));
		else if(strcmp(Get_Com,"full")==0)
			printf("%d\n",full(&stack));
		else if(strcmp(Get_Com,"top")==0)
			printf("%d\n",top(&stack));
	}
	return 0;
}