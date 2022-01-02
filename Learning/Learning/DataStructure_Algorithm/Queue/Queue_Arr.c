#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front;
int rear;
int data[MAX];

// 선형 큐 초기화 
void init_queue()
{
	rear = -1;
	front = -1;
}

// 선형 큐 상태 출력
void queue_print()
{
	for (int i = 0; i<MAX; i++) {
		if (i <= front || i> rear)
			printf("   | ");
		else
			printf("%d  | ", data[i]);
	}
	printf("\n");
}

// 선형 큐가 포화상태인가?
int is_full()
{
	return (rear==MAX-1);
}

// 선형 큐가 공백상태인가?
int is_empty()
{
	return (front==rear); //front==rear이면 빈 상태
}

// 선형 큐에 데이터 삽입
void enqueue(int item)
{
	if (is_full()) {
		printf("큐가 포화상태입니다.\n");
		return;
	}
	data[  ++(rear)  ] = item;
}

// 선형 큐에서 데이터 제거
int dequeue()
{
	if (is_empty()) {
		printf("큐가 공백상태입니다.\n");
		return -1;
	}
	int item = data[ ++(front) ];
	return item;
}	

int main(void)
{
	init_queue();
	dequeue(); printf("\n"); queue_print();
	enqueue(1); queue_print();
	enqueue(2); queue_print();
	enqueue(3); queue_print();
	enqueue(4); queue_print();
	enqueue(5); queue_print(); printf("\n");
	enqueue(6); printf("\n"); queue_print();
	dequeue(); queue_print();
	dequeue(); queue_print();
	dequeue(); queue_print();
	dequeue(); queue_print();
	dequeue(); queue_print(); printf("\n");
	dequeue();
	return 0;
}