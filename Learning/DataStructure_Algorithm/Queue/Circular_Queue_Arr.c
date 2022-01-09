#include <stdio.h>
#include <string.h>
#define MAX 5

int front;
int rear;
int queue[MAX];
 
void init_queue() //선형 큐와의 차이점: front와 rear을 0으로 초기화한다.
{
	rear = 0;
	front = 0;
}

int empty(void)
{
    return (front==rear); //front와 rear가 같으면 큐는 비어있는 상태 
}
int full(void)
{
    return ((rear+1)%MAX==front); //(rear+1)%MAX가 front와 같으면 큐는 가득차 있는 상태 
}
void enqueue(int data)
{
    if(full())
	{
        printf("큐가 포화상태입니다. 데이터 삽입을 취소합니다.\n");
		return;
	}
    else
	{
         rear = (rear+1)%MAX;
         queue[rear]=data;
    }

}
int dequeue()
{
    if(empty())
		return -1;
    else
	{
        front = (front+1)%MAX;
        return queue[front];
    }
}
 
int main()
{    
    char Get_Com[10];
	int N,pushnum;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"enqueue")==0)
		{
			scanf("%d",&pushnum);
			enqueue(pushnum);
		}
		else if(strcmp(Get_Com,"dequeue")==0)
			printf("%d\n",dequeue());
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty());
		else if(strcmp(Get_Com,"full")==0)
			printf("%d\n",full());
	}
    return 0;
}