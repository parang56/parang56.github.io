#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct Key{
	int key;
	int value;
}Key;

typedef struct Queue{
	Key queue[MAX];
	int front,rear,size;
}Queue;

void init_queue(Queue *q)
{
	q->front = 0;
	q->rear = 0;
	q->size = 0;
}

void enqueue(Queue *q, int num)
{
	q->rear = (q->rear+1)%MAX;
    q->queue[q->rear].value=num;
	q->size+=1;
}

int main(void)
{
	Queue* q=(Queue*)malloc(sizeof(Queue));
	int TestCaseNum, DocNum, CuriousNum;
	scanf("%d",&TestCaseNum);
	while(TestCaseNum--)
	{
		init_queue(q);
		int max=0;
		int cnt=1;
		scanf("%d %d", &DocNum, &CuriousNum);
		for(int i=0; i<DocNum; i++)
		{
			int GetImportance;
			scanf("%d",&GetImportance);
			enqueue(q, GetImportance);
			q->queue[q->rear].key=i;
		}
		int key1,key2;
		key1 = q->queue[CuriousNum].value;
		key2 = q->queue[CuriousNum].key;
		while(1)
		{
			for(int i=0;i<DocNum;i++)
			{
				if(q->queue[i].value>max)
					max=q->queue[i].value; //가장 중요도 높은 수 max에 넣기
			}
			//가장 중요도 큰 수가 앞에 올때까지 반복
			while(q->queue[q->front].value!=max)
			{
				int tmp=q->queue[q->front].value;
				q->front = (q->front+1)%q->size;
				enqueue(q,tmp);
			}
			//가장 앞이 원하는 목표 수면 break
			if(q->queue[q->front].value == key1 && q->queue[q->front].key == key2)
				break;
			//가장 잎이 중요도 크지만 원하는 목표 수가 아니면
			q->queue[q->front].value=-1; //없앴다고 셈 치기
			q->front = (q->front+1)%DocNum;
			cnt++;
			max=0;
			q->size-=1;
		}
		printf("%d\n",cnt);
	}
	return 0;
}