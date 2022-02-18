#include <stdio.h>

typedef struct Node{
	int num;
	int visited;
	struct Node *next;
}Node;

Node graph[1001];
Node dummy[10000];
int queue[1000];
int head, tail, cnt;

void init_graph(int N) 
{
	head=tail=cnt=0;
    for(int i=1; i<=N; i++)
	{
        graph[i].num = i;
        graph[i].next = NULL;
        graph[i].visited = 0;
    }
}

void insert(int i, int j)   // i번째 정점에 j번째 정점을 추가
{
    Node *tmp = graph[i].next;
    if(tmp == NULL)
	{
        tmp = &dummy[cnt++];
        tmp->num = j;
        tmp->visited = 0;
        tmp->next = NULL;
        graph[i].next = tmp;
    }   
    else
	{
        Node *newNode = &dummy[cnt++];
        newNode->num = j;
        newNode->visited = 0;

        if(newNode->num < tmp->num)
		{
                newNode->next = tmp;
                graph[i].next = newNode;
        }
        else
		{
            while(tmp->next)
			{
                if(newNode->num < (tmp->next)->num)
				{
                    newNode->next = tmp->next;
                    tmp->next = newNode;
                    break;
                }
                else tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    } 
}

void DFS(int v) // DFS starting from i
{
    Node *cursor = &graph[v];
    if(!cursor->visited)
	{
        printf("%d ", cursor->num);
        cursor->visited = 1; //방문한 곳: 1
        cursor = cursor->next;
        while(cursor)
		{
            DFS(cursor->num);
            cursor = cursor->next;
        }
    }
}

void enqueue(int i)
{
    queue[tail++] = i;
    // printf("Enqueue %d\n", i);
}

int dequeue()
{
    int num = queue[head++];
    // printf("Dequeue %d\n", num);
    printf("%d ", num);
    return num;
}

void BFS(int i) // BFS starting from i
{
    Node *cursor = &graph[i];
    int num=0;
    graph[i].visited = 1;
    enqueue(i);
    cursor = cursor->next;
    while(head < tail)
	{
        num = dequeue();
        cursor = graph[num].next;
        while(cursor)
		{
            if(!graph[cursor->num].visited)
			{
                graph[cursor->num].visited = 1;
                enqueue(cursor->num);
            }
            cursor = cursor->next;
        }
    }
    
}


int main()
{
    int N, M, v, a, b, i=0; //N:정점개수, M:간선개수, v:시작정점
    scanf("%d %d %d", &N, &M, &v);
    init_graph(N);
    while(i < M)
	{
        i++;
        scanf("%d %d", &a, &b);
		//인접 리스트 만들기
        insert(a, b);
        insert(b, a);
    }

	/*
    for(i=1; i<=N; i++) {
        Node *tmp = (&graph[i])->next;
        printf("Nodes connected to node %d\n", i);
        while(tmp) {
            printf("%d\n", tmp->num);
            tmp = tmp->next;
        }
	}
	*/

    DFS(v);
    printf("\n");
    
    for(i=1; i<=N; i++)
        graph[i].visited = 0;

    BFS(v);
    printf("\n");
    
    return 0;
}