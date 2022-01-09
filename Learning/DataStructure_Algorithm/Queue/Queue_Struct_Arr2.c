#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct { // 선형 큐 타입
	int front;
	int rear;
	int data[MAX];
} Queue;

// 선형 큐 초기화 
void InitQueue(Queue *queue)
{
	queue->rear = -1;
	queue->front = -1;
}

int full(Queue *queue)
{
	return (queue->rear == MAX-1);
}

int empty(Queue *queue)
{
	return (queue->front == queue->rear); //front==rear이면 빈 상태
}

// 선형 큐에 데이터 삽입
void enqueue(Queue *queue, int item)
{
	if (full(queue)) {
		printf("큐가 포화상태입니다. 데이터 삽입을 취소합니다.\n");
		return;
	}
	queue->data[++(queue->rear)] = item;
}

// 선형 큐에서 데이터 제거
int dequeue(Queue *queue)
{
	if (empty(queue)) {
		return -1;
	}
	int num = queue->data[++(queue->front)];
	return num;
}	

int main(void)
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	InitQueue(queue);
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
		else if(strcmp(Get_Com,"full")==0)
			printf("%d\n",full(queue));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(queue));
	}
	return 0;
}