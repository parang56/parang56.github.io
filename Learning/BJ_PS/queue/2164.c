#include <stdio.h>
#include <string.h>
#define MAX 500000

int front;
int rear;
int queue[MAX];
 
void init_queue()
{
	rear = 0;
	front = 0;
}

/*
void enqueue(int data)
{
    rear = (rear+1)%MAX;
	queue[rear]=data;
}

int dequeue()
{
    front = (front+1)%MAX;
    return queue[front];
}
*/

void enqueue(int data)
{
	queue[rear]=data;
    rear = (rear+1)%MAX;
}

int dequeue()
{
	int tmp=queue[front];
    front = (front+1)%MAX;
    return tmp;
}

int main()
{    
	int N,tmp=0;
	init_queue();
	scanf("%d",&N);
	//1~N 큐에 넣기
	if(N==1)
		printf("1\n");
	else
	{
		for(int i=1;i<=N;i++)
			enqueue(i);
		for(int i=0;i<N-1;i++)
		{
			dequeue();
			tmp=dequeue();
			enqueue(tmp);
		}
		printf("%d\n",tmp);
	}
    return 0;
}