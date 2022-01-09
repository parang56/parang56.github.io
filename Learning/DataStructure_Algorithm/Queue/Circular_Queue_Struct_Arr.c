#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct Queue {
	int queue[MAX];
	int front, rear;
}Queue;

void init_queue(Queue* q)
{
	q->front = q->rear = 0; //front, rear 0으로 초기화
}

//큐가 비어 있는지 확인
int empty(Queue* q)
{
	return (q->front == q->rear);
}

//큐가 가득 찼는지 확인
int full(Queue* q) 
{
	return (q->front == ((q->rear+1)%MAX));
}

//큐가 가득 차 있는지 확인 후 삽입 연산
void enqueue(Queue* q, int data) 
{
	if (full(q))
	{
		printf("큐가 포화상태입니다. 데이터 삽입을 취소합니다.\n");
		return;
	}
	else 
	{
		q->rear = (q->rear + 1) % MAX;
		q->queue[q->rear] = data;
	}
}

//큐가 비어 있는지 확인 후 삭제 연산
int dequeue(Queue* q) 
{
	if (empty(q)) 
		return -1;
	else {
		q->front = (q->front + 1) % MAX;
		return q->queue[q->front];
	}
}

int main() {

	Queue* queue=(Queue*)malloc(sizeof(Queue));
	char Get_Com[10];
	int N,pushnum;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"enqueue")==0)
		{
			scanf("%d",&pushnum);
			enqueue(queue,pushnum);
		}
		else if(strcmp(Get_Com,"dequeue")==0)
			printf("%d\n",dequeue(queue));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(queue));
		else if(strcmp(Get_Com,"full")==0)
			printf("%d\n",full(queue));
	}
	return 0;
}