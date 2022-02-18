#include <stdio.h>
#define MAX 101
#define BIG 10000

int graph[MAX][MAX];
int visited[MAX][MAX];
int M,N;

typedef struct Node{
	int x;
	int y;
}q;

q queue[BIG+1];
int rear = 0;
int front = 0;
int max = 0;

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

void BFS()
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
				if(graph[nextX][nextY] && !visited[nextX][nextY])
				{
					//(M,N)에 도착하는 값이 항상 최소, 그 외의 값은 첫 if 조건에서 이미 걸러짐.
					visited[nextX][nextY] = visited[pop.x][pop.y]+1;
					enqueue(nextX,nextY);
				}
		}
	}
}

int main(void)
{
	scanf("%d %d", &M, &N);
    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            scanf("%1d", &graph[i][j]); //하나씩 입력 받음
	visited[1][1] = 1;
    enqueue(1, 1);
    BFS();
    printf("%d\n", visited[M][N]);
}