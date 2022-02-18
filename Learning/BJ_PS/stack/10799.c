#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

typedef struct Stack{
	int top;
	char arr[MAX];
}Stack;

void InitStack(Stack *stack)
{
	stack->top=-1;
} 

int isFull(Stack *stack)
{
	return stack->top+1 == MAX;
}

int isEmpty(Stack *stack)
{
	return stack->top==-1;
}

int top(Stack *stack)
{
	if(isEmpty(stack)==1)
		return -1;
	return stack->top+1;
}

void push(Stack *stack, char data)
{
	if(isFull(stack))
		return;
	stack->arr[++stack->top]=data;
}

int pop(Stack *stack)
{
	if(isEmpty(stack))
		return -1;
	return stack->arr[stack->top--];
}

int main(void)
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	InitStack(stack);
	char input[MAX];
	int sum=0;
	scanf("%s", input);
	for(int i=0; i<strlen(input); i++)
	{
		if(input[i]=='(')
		{
			//()는 레이저
			if(input[i+1]==')')
			{
				//막대를 자름
				sum += stack->top+1;
				i++;
			}
			//레이저가 아니라 막대면 '('를 스택에 push
			else 
				push(stack, input[i]);
		}
		//'('에 대응되는 ')'를 하나 입력 받았으므로 스택에서 pop
		else if(input[i] == ')')
		{
			pop(stack);
			//막대 추가
			sum++;
		}
	}
	printf("%d\n",sum);
	free(stack);
	
	return 0;
}