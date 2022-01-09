#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

typedef struct Deque {
	int *deque;
	int front, rear, size;
}Deque;

void init_deque(Deque* d)
{
	d->deque = (int*)malloc(sizeof(int)*MAX);
	d->front=0;
	d->rear=0;
	d->size=0;
}

int size(Deque* d)
{
	return d->size;
}

int full(Deque* d)
{
	return ((d->rear+1)%MAX==d->front);
}

int empty(Deque* d)
{
	return (d->front == d->rear);
}

int front(Deque* d)
{
	if(empty(d))
		return -1;
	return d->deque[(d->front+1)%MAX];
}

int back(Deque* d)
{
	if(empty(d))
		return -1;
	return d->deque[d->rear];
}

void push_front(Deque* d, int data) 
{
	if(full(d))
		printf("큐가 포화상태입니다. 데이터 삽입을 취소합니다.\n");
	else
	{
		d->deque[d->front] = data;
		d->front = (d->front-1+MAX) % MAX;	
		d->size++;
	}
}

void push_back(Deque* d, int data) 
{
	if(full(d))
		printf("큐가 포화상태입니다. 데이터 삽입을 취소합니다.\n");
	else
	{
		d->rear = (d->rear+1) % MAX;
		d->deque[d->rear] = data;
		d->size++;
	}
}

int pop_front(Deque* d)
{
	if(empty(d))
		return -1;
	
	d->front=(d->front+1)%MAX;
	d->size--;
	return d->deque[d->front];
}

int pop_back(Deque* d)
{
	if(empty(d))
		return -1;
	
	int tmp=d->deque[d->rear];
	d->rear=(d->rear-1+MAX)%MAX;
	d->size--;
	return tmp;
}

int main(void) 
{
	Deque* deque=(Deque*)malloc(sizeof(Deque));
	init_deque(deque);
	char Get_Com[11];
	int N,num;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"push_front")==0)
		{
			scanf("%d",&num);
			push_front(deque,num);
		}
		else if(strcmp(Get_Com,"push_back")==0)
		{
			scanf("%d",&num);
			push_back(deque,num);
		}
		else if(strcmp(Get_Com,"front")==0)
			printf("%d\n",front(deque));
		else if(strcmp(Get_Com,"back")==0)
			printf("%d\n",back(deque));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(deque));
		else if(strcmp(Get_Com,"size")==0)
			printf("%d\n",size(deque));
		else if(strcmp(Get_Com,"pop_front")==0)
			printf("%d\n",pop_front(deque));
		else if(strcmp(Get_Com,"pop_back")==0)
			printf("%d\n",pop_back(deque));
	}
	return 0;
}