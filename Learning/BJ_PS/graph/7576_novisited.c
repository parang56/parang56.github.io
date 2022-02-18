//익은 토마토를 기점으로 BFS로 탐색을 하면서 0을 전부 1로 바꾼다.
//-1이 있으면 건너뜀
//익을 수 있는 모든 토마토가 익으면 -1은 건너뛰고 모든 칸을 검사하고 안 익은 곳이 있으면 -1 출력
//안 익은 곳이 없으면 익은 토마토를 기점으로 최소 일 수 출력
//처음부터 다 익은 상태면 0 출력

#include <stdio.h>
#define MAX 1001
#define BIG 1000001

int graph[MAX][MAX];
int M, N, rear, front, res;

typedef struct Node{
	int x;
	int y;
}q;

q queue[BIG+1];

int vectX[4] = {0,0,1,-1};
int vectY[4] = {1,-1,0,0};

q dequeue()
{
    q temp = queue[front];
    front = (front + 1) % BIG;
    return temp;
}

void enqueue(int x, int y)
{
    q temp;
    temp.x = x;
    temp.y = y;
    queue[rear] = temp;
    rear = (rear + 1) % BIG;
}

int BFS()
{
	int nextX, nextY;
	while(front<rear)
	{
		q pop=dequeue();
		for(int i=0;i<4;i++) //모든 방향으로 검사
		{
			nextX = vectX[i] + pop.x;
			nextY = vectY[i] + pop.y;
			
			if(nextX>=1 && nextX<=M && nextY>=1 && nextY<=N)
				if(graph[nextX][nextY]==0)
				{
					graph[nextX][nextY] = graph[pop.x][pop.y]+1;
					enqueue(nextX,nextY);
				}
		}
	}
	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=N; j++)
		{
			if(graph[i][j]==0)
			{
				res=-1;
				return res;
			}
			else if(res<graph[i][j])
				res=graph[i][j];
		}
	}
	
	return res-1;
}

int main(void)
{
	int isRipe=1;
	scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
		{
			scanf("%d", &graph[i][j]);
			if(graph[i][j]==1)
				enqueue(i, j);
		}
    }
	for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
			if(graph[i][j]==0)
				isRipe=0;
	if(isRipe==1)
		printf("0\n");
	else
		printf("%d\n",BFS());
	return 0;
}