#include <stdio.h>
#include <stdlib.h>

void fibo(int num) 
{
    int a=0, b=1, c;
    if (num==0)
        printf("1 0\n");

    else if (num==1)
        printf("0 1\n");
	
    else 
	{
        for (int i=1; i<num; i++) 
		{
            c=a+b;
            a=b;
            b=c;
        }
        printf("%d %d\n", a, b);
    }
}

int main(void) 
{
    int T, N;
    scanf("%d", &T);

    while(T--)
	{
        scanf("%d",&N);
        fibo(N);
    }
}