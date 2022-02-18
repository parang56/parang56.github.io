#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *stack;
    int size;
}Stack;

void push(Stack *s, int a)
{
    s->stack[s->size++] = a;
}

int pop(Stack *s)
{
    return s->stack[--s->size];
}

int top(Stack *s)
{
    return s->stack[s->size - 1];
}

int IsEmpty(Stack *s)
{
    return (s->size == 0);
}

int main(void)
{
    Stack* stk = (Stack *)malloc(sizeof(Stack));
	int N=0;
    scanf("%d", &N);
	int arr[N];
	int ans[N];
    stk->stack = calloc(N, sizeof(int));

    for(int i=0;i<N;i++)
	{
        scanf("%d", &arr[i]);
        ans[i] = -1;
    }

    for(int i=0;i<N;i++)
	{
        while(!IsEmpty(stk) && arr[top(stk)] < arr[i])
            ans[pop(stk)] = arr[i];

        push(stk, i);
    }
	
    for(int i=0;i<N;i++)
        printf("%d ", ans[i]);
	
	return 0;
}