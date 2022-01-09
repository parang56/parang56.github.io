#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;
 
typedef struct Queue //Queue 구조체 정의
{
    Node *front; //맨 앞(꺼낼 위치)
    Node *rear; //맨 뒤(보관할 위치)
	int queuesize;
}Queue;

int size(Queue *queue)
{
	return queue->queuesize;
}

int empty(Queue *queue)
{ 
    return queue->front==NULL;
}

int front(Queue *queue)
{
	if(empty(queue)==1)
		return -1;
	else
		return queue->front->data;
}

int back(Queue *queue)
{
	if(empty(queue)==1)
		return -1;
	else
		return queue->rear->data;
}

void InitQueue(Queue *queue)
{
    queue->front = NULL; 
	queue->rear = NULL; //front와 rear를 NULL로 설정
	queue->queuesize = 0;
}

void push(Queue *queue, int data)
{
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = data;
 
    if (empty(queue))
        queue->front = now; //비어있으면 맨 앞을 now로 설정       
    else
        queue->rear->next = now; //안 비어있으면 rear의 다음을 now로 설정
	
    queue->rear = now; //맨 뒤를 now로 설정
	queue->queuesize++;
}

int pop(Queue *queue)
{
	/*
    if (empty(queue)) //큐가 비었을 때
        return -1;
	
    int re = queue->front->data;
    queue->front = queue->front->next; //front는 한 칸 앞인 now의 next로 설정
	queue->queuesize--;
    return re;*/
	int re=-1;
    Node *now;
    if (IsEmpty(queue))//큐가 비었을 때
        return re;
    now = queue->front;//맨 앞의 노드를 now에 기억
    re = now->data;//반환할 값은 now의 data로 설정
    queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
    free(now);//now 소멸
	queue->queuesize--;
    return re;
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
		if(strcmp(Get_Com,"push")==0)
		{
			scanf("%d",&pushnum);
			push(queue,pushnum);
		}
		else if(strcmp(Get_Com,"pop")==0)
			printf("%d\n",pop(queue));
		else if(strcmp(Get_Com,"size")==0)
			printf("%d\n",size(queue));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(queue));
		else if(strcmp(Get_Com,"front")==0)
			printf("%d\n",front(queue));
		else if(strcmp(Get_Com,"back")==0)
			printf("%d\n",back(queue));
	}
    return 0;
}