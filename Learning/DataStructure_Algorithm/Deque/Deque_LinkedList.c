#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}Node;

typedef struct Deque {
	Node *front;
	Node *rear;
	int size;
}Deque;

void init_deque(Deque *deque)
{
	deque->front = NULL;
	deque->rear = NULL;
	deque->size = 0;
}

int empty(Deque *deque)
{
	return deque->size == 0 ;
}

int size(Deque *deque) 
{
    return deque->size;
}

int front(Deque *deque)
{
    if(empty(deque))
    	return -1;
    return deque->front->data;
}

int back(Deque *deque)
{
    int re = -1;
    if(empty(deque))
	    return re;

    re = deque->rear->data;
    return re;
}

int strcmp(char* str1, char* str2)
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;
}

void push_front(Deque *deque, int data)
{
	Node *now = (Node *)malloc(sizeof(Node));
	now->data = data;
	if(empty(deque)) 
	{
		deque->front = now;
		deque->rear = now;
		now->right = NULL;
		now->left = NULL;
	} 
	else 
	{
		deque->front->left = now;
		now->right = deque->front;
		now->left = NULL;
		deque->front = now;
    }
    deque->size++;
}

/*
void push_front(Deque *deque, int data)
{
	Node *now = (Node *)malloc(sizeof(Node));
	now->data = data;
	now->left = NULL;
	if(empty(deque)) 
	{
		deque->rear = now;
		now->right = NULL;
	} 
	else 
	{
		deque->front->left = now;
		now->right = deque->front;
    }
    deque->front = now;
    deque->size++;
}
*/

void push_back(Deque *deque, int data)
{
	Node *now = (Node *)malloc(sizeof(Node));
	now->data = data;
	if(empty(deque)) 
	{
		deque->front = now;
		deque->rear = now;
		now->right = NULL;
    	now->left = NULL;
	} 
	else 
	{
    	deque->rear->right = now;
    	now->left = deque->rear;
		now->right = NULL;
		deque->rear = now;
	}
    deque->size++;
}

/*
void push_back(Deque *deque, int data)
{
	Node *now = (Node *)malloc(sizeof(Node));
	now->data = data;
	now->right = NULL;
	if(empty(deque)) 
	{
		deque->front = now;
    	now->left = NULL;
	} 
	else 
	{
    	deque->rear->right = now;
    	now->left = deque->rear;
	}
    deque->rear = now;
    deque->size++;
}
*/

int pop_front(Deque *deque)
{
    int re = -1;
    Node *now;
    if(empty(deque))
    	return re;
		
    now = deque->front;
    re = now->data;
    deque->front = now->right;
    free(now);
    deque->size--;
    return re;
}

int pop_back(Deque *deque)
{
    int re = -1;
    Node *now;
    if(empty(deque))
    	return re;
	
    now = deque->rear;
    re = now->data;
    deque->rear = now->left;
    free(now);
    deque->size--;
    return re;
}

int main(void) 
{
	Deque* deque=(Deque*)malloc(sizeof(Deque));
	init_deque(deque);
	char Get_Com[11];
	int N,num;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",Get_Com);
		if(strcmp(Get_Com,"push_front")==0)
		{
			scanf("%d",&num);
			push_front(deque,num);
		}
		else if(strcmp(Get_Com,"push_back")==0)
		{
			scanf("%d",&num);
			push_back(deque,num);
		}
		else if(strcmp(Get_Com,"front")==0)
			printf("%d\n",front(deque));
		else if(strcmp(Get_Com,"back")==0)
			printf("%d\n",back(deque));
		else if(strcmp(Get_Com,"empty")==0)
			printf("%d\n",empty(deque));
		else if(strcmp(Get_Com,"size")==0)
			printf("%d\n",size(deque));
		else if(strcmp(Get_Com,"pop_front")==0)
			printf("%d\n",pop_front(deque));
		else if(strcmp(Get_Com,"pop_back")==0)
			printf("%d\n",pop_back(deque));
	}
	return 0;
}