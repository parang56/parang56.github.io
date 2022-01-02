#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue{
	int queue[MAX];
	int front;
}Queue;

void init_queue(Queue *q)
{
	q->front = 0;
}

int main() 
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
		for(int i=0;i<DocNum;i++)
			scanf("%d",q->queue+i);
		
		while(1)
		{
			for(int k=0;k<DocNum;k++)
			{
				if(q->queue[k]>max)
					max=q->queue[k]; //가장 중요도 높은 수 max에 넣기
			}
			while(q->queue[q->front]!=max) //queue[front]가 max 일치시키게 하기
				q->front=(q->front+1)%DocNum;
			
			if(q->front==CuriousNum) //뽑는 수와 궁금한 수가 일치하면 cnt 출력
				break;
			
			q->queue[q->front]=0; //없앴다고 셈 치기
			q->front = (q->front+1)%DocNum;
			max=0;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}