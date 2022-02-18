#include <stdio.h>
#define MAX_N 100001

typedef struct heap 
{
    int arr[MAX_N];
    int size;
} heap;
 
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void initHeap(heap *hp)
{
    hp->size = 0;
}

void insert(heap* hp,int data) 
{
    int here = ++hp->size;
     
    while ((here!=1)&&(data<hp->arr[here/2])) 
	{
        hp->arr[here] = hp->arr[here / 2];
        here /= 2;
    }
    hp->arr[here] = data;
}
 
int deleteData(heap *hp) 
{
    if (hp->size == 0)
		return 0;
    int ret = hp->arr[1];
    hp->arr[1]=hp->arr[hp->size--];
    int parent = 1;
    int child;
 
    while (1) 
	{
        child = parent * 2;
		
		//왼쪽, 오른쪽 자식이 있고 왼쪽 자식이 오른쪽 자식보다 클 때
        if (child + 1 <= hp->size && hp->arr[child]>hp->arr[child + 1])
            child++;
 	
		//자식이 없거나, 가장 작은 자식과 비교해서 부모가 더 작아지면 break.
        if (child>hp->size||hp->arr[child] > hp->arr[parent]) 
			break;
         
        swap(&hp->arr[parent], &hp->arr[child]);
        parent = child;
    }
     
    return ret;
}

int main(void) 
{
	heap hp;
	initHeap(&hp);
    int x, N;
	scanf("%d",&N);
    for (int i=0; i<N; i++)
	{
        scanf("%d",&x);
        if (x == 0)
			printf("%d\n",deleteData(&hp));
        else 
			insert(&hp, x);
    }
    
    return 0;
}