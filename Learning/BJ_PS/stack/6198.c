#include<stdio.h>

#define BUILDING_MAX 80000
#define HEIGHT_MAX 1000000000

int N, top;
int Stack[BUILDING_MAX + 10];
long long res;


int Is_Empty()
{
	return top==0;
}

void Push(int data)
{
	Stack[++top] = data;
}

void Pop()
{
	top--;
}

int Top()
{
	return Stack[top];
}

int Size()
{
	return top;
}

int main(void)
{
    scanf("%d", &N);

    for(int i=0; i<N; ++i)
    {
        int height;
        scanf("%d", &height);

        while(!Is_Empty() && height >= Top())
			Pop();
        Push(height);


        res+=Size()-1;
    }

    printf("%lld\n", res);

    return 0;
}