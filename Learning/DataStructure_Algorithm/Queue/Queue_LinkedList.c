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
}Queue;
 
void InitQueue(Queue *queue)
{
    queue->front = NULL; 
	queue->rear = NULL; //front와 rear를 NULL로 설정
}
 
int empty(Queue *queue) //front와 rear가 직접 움직이는 것이 아니므로 
{ 
    return queue->front==NULL;
}
 
void enqueue(Queue *queue, int data)
{
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = data;
 
    if (empty(queue))
        queue->front = now; //비어있으면 맨 앞을 now로 설정       
    else
        queue->rear->next = now; //안 비어있으면 rear의 다음을 now로 설정
	
    queue->rear = now; //맨 뒤를 now로 설정
}
 
int dequeue(Queue *queue)
{
    int re = -1;
    if (empty(queue)) //큐가 비었을 때
        return re;
	
    Node *now = queue->front;
    re = now->data;
    queue->front = now->next; //front는 한 칸 앞인 now의 next로 설정
    free(now);
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
		if(strcmp(Get_Com,"enqueue")==0)
		{
			scanf("%d",&pushnum);
			enqueue(queue,pushnum);
		}
		else if(strcmp(Get_Com,"dequeue")==0)
			printf("%d\n",dequeue(queue));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(queue));
	}
    return 0;
}