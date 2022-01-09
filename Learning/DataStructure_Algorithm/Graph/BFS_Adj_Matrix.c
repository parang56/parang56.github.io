#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX] = {0,}; // 인접행렬 만들때 사용
int visited[MAX] = {0,}; // BFS 방문했는지 check
int queue[MAX] = {0,};

void BFS(int v, int N)
{
	int pop, front, rear;
	front = rear = -1;
	visited[v] = 1; //방문한 곳: 1
	queue[++rear] = v; //3번: 큐->push
	while(front < rear)
	{
		pop = queue[++front]; //3번: 큐->pop
		printf("%d ",pop);
		for(int i=1; i<=N; i++)
		{
			if(graph[pop][i] && !visited[i]) //2번: 인접여부 확인 && 1번: 정점의 방문 여부
			{
				visited[i] = 1;
				queue[++rear] = i; //3번: 큐->push
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
		//2번: 인접행렬 만들기
		graph[x][y]=1;
		graph[y][x]=1;
	}
	BFS(v, N);
	return 0;
}