#include <stdio.h>
 
int N,M;
int result[1000];
int check[1000];
 
void Backtracking(int L)
{   
    if(L==M)
    {
        for(int i=0;i<M;i++)
            printf("%d ",result[i]);
        printf("\n");
    }
    else
    {
        for(int i=1 ; i<=N ; i++)
        {
            if(!check[i])
            {
                result[L]=i;
                check[i]=1;
                Backtracking(L+1);
                check[i]=0;
            }
        }
    }
}
    
 
int main(void)
{
    scanf("%d %d",&N,&M);
    Backtracking(0);
	
	return 0;
} 