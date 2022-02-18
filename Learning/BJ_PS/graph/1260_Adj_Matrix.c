#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX]={0,}; //인접행렬
int visitedDFS[MAX]={0,}; //DFS 방문했는지 check
int visitedBFS[MAX]={0,}; //BFS 방문했는지 check
int queue[MAX] = {0,};

void DFS(int v, int N)
{
	visitedDFS[v]=1; //방문한 곳: 1
	printf("%d ", v); //정점 출력
	for(int i=1; i<=N; i++)
	{
		if(graph[v][i] && !visitedDFS[i]) //인접여부 확인 && 정점의 방문 여부
			DFS(i, N); //재귀 함수
	}
}

void BFS(int v, int N)
{
	int pop, front, rear;
	front = rear = -1;
	visitedBFS[v] = 1; //방문한 곳: 1
	queue[++rear] = v; //큐->push
	while(front < rear)
	{
		pop = queue[++front]; //큐->pop
		printf("%d ",pop);
		for(int i=1; i<=N; i++)
		{
			if(graph[pop][i] && !visitedBFS[i]) //인접여부 확인 && 정점의 방문 여부
			{
				visitedBFS[i] = 1;
				queue[++rear] = i; //큐->push
			}
		}
	}
}

int main(void)
{
	int N,M,v; // 정점개수, 간선개수, 시작정점
	int x,y; // 좌표
	scanf("%d %d %d", &N, &M, &v);
	
	//간선개수만큼 반복
	while(M--)
	{
		scanf("%d %d", &x,&y);
		//인접행렬 만들기
		graph[x][y]=1;
		graph[y][x]=1;
	}
	DFS(v, N);
	printf("\n");
	BFS(v, N);
	printf("\n");
	return 0;
}