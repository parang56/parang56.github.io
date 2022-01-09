#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX]={0,}; //인접행렬
int visited[MAX]={0,}; // DFS 방문했는지 check


void DFS(int v, int N)
{
	visited[v]=1; //방문한 곳: 1
	printf("%d ", v); //정점 출력
	for(int i=1; i<=N; i++)
	{
		if(graph[v][i] && !visited[i]) //2번: 인접여부 확인 && 1번: 정점의 방문 여부
			DFS(i, N); //3번: 재귀 함수
	}
}

int main(void)
{
	int N,M,v; //정점개수,간선개수,시작정점
	int x,y; //좌표
	scanf("%d %d %d", &N, &M, &v);
	
	//간선개수만큼 반복
	while(M--)
	{
		scanf("%d %d", &x,&y);
		//2번: 인접행렬 만들기
		graph[x][y]=1;
		graph[y][x]=1;
	}
	DFS(v, N);
	return 0;
}