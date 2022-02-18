#include <stdio.h>
#define MAX 1001

typedef struct Node{
	int num;
	int visited;
	struct Node *next;
}Node;

Node graph[MAX][MAX];
Node dummy[20010];
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
}

int dequeue()
{
    int num = queue[head++];
    printf("%d ", num);
    return num;
}

void BFS(int v)
{
    Node *cursor = &graph[v];
    int num=0;
    graph[v].visited = 1;
    enqueue(v);
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
    int N, M, v, x, y, i=0; //N:정점개수, M:간선개수, v:시작정점
    scanf("%d %d %d", &N, &M, &v);
    init_graph(N);
    while(i < M)
	{
        i++;
        scanf("%d %d", &x, &y);
		//인접 리스트 만들기
        graph[x][y]=1;
		graph[y][x]=1;
    }

    DFS(v);
    printf("\n");
    
    for(i=1; i<=N; i++)
        graph[i].visited = 0;

    BFS(v);
    printf("\n");
    
    return 0;
}