#include <stdio.h>
#include <string.h>

#define MAX 52

typedef struct Stack{
	char arr[MAX];
	int top;
}Stack;

void init_stack(Stack* stack) //스택 초기화: top=-1
{
	stack->top=-1;
}

int full(Stack* stack)
{
	return (stack->top+1) == MAX;
}

int empty(Stack* stack)
{
	return (stack->top)==-1;
}

void push(Stack* stack, char cha)
{
	if (full(stack)) //꽉차면 더 이상 push하지 않음
		return;

	/*
	stack->top++;
	stack->arr[stack->top]=num;
	*/ //또 하나의 코드 줄이기 모먼트 발견
	
	stack->arr[++stack->top] = cha;
}

char pop(Stack* stack)
{
	if (empty(stack))
		return -1;
	
	/*
	char popcha = stack->arr[stack->top];
	stack->top--;
	*/
	
	char popcha = stack->arr[stack->top--]; 
	return popcha;
}

int main()
{
	Stack stack;

	char text[MAX], checkcha;
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		init_stack(&stack); //for문 반복마다 stack 초기화
		int yesorno=1;      //for문 반복마다 YES, NO를 결정할 변수 초기화
		scanf("%s",text);
		for(int j=0;j<strlen(text);j++)
		{
			if(text[j]=='(')
				push(&stack, text[j]); //'(' 마다 stack에 push
			else if(text[j]==')')
			{
				checkcha = pop(&stack); //')'가 입력되면 top에 있는 문자 확인.
				if(checkcha != '(')     //'('가 아니면, 성립이 안되서 yesorno가 NO 값인 0이 된다. 
				{
					yesorno=0;
					break;
				}
			}
		}
		if(!empty(&stack)) //스택이 비어있지 않다는건, '('가 남아있는 상황이라는 것이므로 yesorno가 NO 값인 0이 된다.
			yesorno=0;
		if(yesorno==0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}