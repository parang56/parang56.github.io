#include <stdio.h>

int front;
int rear;

void init_queue()
{
	rear = 0;
	front = 0;
}

void enqueue(int data, int size, int* queue)
{
	queue[rear]=data;
    rear = (rear+1)%size;
}

int dequeue(int size, int* queue)
{
	int tmp = queue[front];
    front = (front+1)%size;
    return tmp;
}

int main()
{
	int N,K, tmp, k=1;
	scanf("%d %d",&N,&K);
	int queue[N];
	int requeue[N];
	for(int i=1;i<=N;i++)
		enqueue(i, N, queue);

	front=K-1;
	requeue[0]=queue[front];
	printf("<"); printf("%d",requeue[0]);
	queue[front]=0;
	for(int i=0;i<N-1;i++)
	{
		int num=K;
		while(num--)
		{
			while(queue[front]==0) //0이 아닌 값 찾기
				front = (front+1)%N;
			tmp=dequeue(N, queue);
		}
		requeue[k]=tmp;
		k++;
		if(front-1>=0)
			queue[front-1]=0;
		else //front-1<0
			queue[N-1]=0;
	}
	for(int i=1;i<N;i++)
	{
		printf(", %d",requeue[i]);
	}
	printf(">\n");
    return 0;
}