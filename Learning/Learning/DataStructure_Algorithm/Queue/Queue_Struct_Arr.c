#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue{ // 선형 큐 타입
	int front;
	int rear;
	int data[MAX];
}Queue;

// 선형 큐 초기화 
void init_queue(Queue *q)
{
	q->rear = -1;
	q->front = -1;
}

// 선형 큐 상태 출력
void print_queue(Queue *q)
{
	for (int i = 0; i<MAX; i++) {
		if (i <= q->front || i> q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int full(Queue *q)
{
	if (q->rear ==  MAX - 1 )
		return 1;
	else
		return 0;
}

int empty(Queue *q)
{
	if ( q->front == q->rear ) //front==rear이면 빈 상태
		return 1;
	else
		return 0;
}

// 선형 큐에 데이터 삽입
void enqueue(Queue *q, int item)
{
	if (full(q)) {
		printf("큐가 포화상태입니다. 데이터 삽입을 취소합니다.\n");
		return;
	}
	q->data[  ++(q->rear)  ] = item;
}

// 선형 큐에서 데이터 제거
int dequeue(Queue *q)
{
	if (empty(q)) {
		printf("큐가 공백상태입니다. 데이터 제거를 취소합니다.\n");
		return -1;
	}
	int item = q->data[ ++(q->front) ];
	return item;
}	

int main(void)
{
	int item = 0;
	Queue* q = (Queue *)malloc(sizeof(Queue));
	init_queue(q);
	
	dequeue(q);
	printf("\n");
	enqueue(q, 10); print_queue(q);
	enqueue(q, 20); print_queue(q);
	enqueue(q, 30); print_queue(q);
	enqueue(q, 40); print_queue(q);
	enqueue(q, 50); print_queue(q);
	printf("\n");
	enqueue(q, 60);
	printf("\n");
	item = dequeue(q); print_queue(q);
	item = dequeue(q); print_queue(q);
	item = dequeue(q); print_queue(q);
	item = dequeue(q); print_queue(q);
	item = dequeue(q); print_queue(q);
	printf("\n");
	item = dequeue(q);
	
	return 0;
}