#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

typedef struct Deque{
	int arr[MAX];
	int front, rear, size;
}Deque;

void init_deque(Deque* d)
{
	d->front=0;
	d->rear=0;
	d->size=0;
}

int size(Deque* d)
{
	return d->size;
}

int empty(Deque* d)
{
	return d->size<0;
}

void push_front(Deque* d, int data)
{
	d->arr[d->front] = data;
	d->front = (d->front-1+MAX) % MAX;
	d->size++;
}

void push_back(Deque* d, int data)
{
	d->rear = (d->rear+1) % MAX;
	d->arr[d->rear] = data;
	d->size++;
}

int pop_front(Deque* d)
{
	d->size--;
	if(empty(d))
		return -1;
	d->front=(d->front+1)%MAX;
	return d->arr[d->front];
}

int pop_back(Deque* d)
{
	d->size--;
	if(empty(d))
		return -1;
	int tmp=d->arr[d->rear];
	d->rear=(d->rear-1+MAX)%MAX;
	return tmp;
}

void print_front(Deque* d)
{
	printf("[");
	for(int i=d->front+1; i<=d->size-1+d->front; i++)
		printf("%d,",d->arr[i]);
	printf("%d",d->arr[d->size+d->front]);
	printf("]\n");
}

void print_back(Deque* d)
{
	printf("[");
	for(int i=d->size+d->front; i>d->front+1; i--)
		printf("%d,",d->arr[i]);
	printf("%d",d->arr[d->front+1]);
	printf("]\n");
}

int T, N, temp, swap, check;
char Get_Com[MAX*4];
char e;

int main(void)
{
	Deque* deque=(Deque*)malloc(sizeof(Deque));
	scanf("%d",&T);
	while(T--)
	{
		init_deque(deque);
		swap=check=0;
		scanf("%s", Get_Com);
		scanf("%d",&N);
		getchar();
		
		//N이 0이 아닐 때 숫자만 입력받기
		if(N!=0)
		{
            scanf("%c", &e);
            for(int i=0;i<N;i++)
			{
                scanf("%d", &temp);
                getchar();
                
                push_back(deque, temp);
            }
        }
		else //N==0이면 []를 입력
            scanf("%c %c", &e, &e);
		
		for(int i=0;;i++)
		{
			if(Get_Com[i]=='R')
				swap = !swap; //swap==1 은 reverse 상태
			else if(Get_Com[i]=='D')
				check = ((swap==0) ? pop_front(deque) : pop_back(deque));
			else if(Get_Com[i]=='\0')
				break;
		}
		
		if(check == -1)
		{
			printf("error\n");
			continue;
		}
		
		if(deque->size==0)
		{
			printf("[]\n");
			continue;
		}
		
		else
			(swap==0) ? print_front(deque) : print_back(deque);
	}
	return 0;
}