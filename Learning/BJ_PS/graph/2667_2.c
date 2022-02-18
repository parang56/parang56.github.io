#include <stdio.h>
#include <stdlib.h>
#define MAX 26

int graph[MAX][MAX];
int visited[MAX][MAX];
// 단지를 저장할 배열 = 나올 수 있는 단지의 최대 개수 = n * (n/2) + 1
int housecomplex[MAX*(MAX/2)+1];

int vectX[4] = {0,0,1,-1};
int vectY[4] = {1,-1,0,0};
 
int cnt; //단지의 개수
int length; //한 변의 길이
int key; //단지 구별할 수
int compare(const void *a, const void *b)    //오름차순 비교
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2) 
        return -1;
    
    if(num1 > num2) 
        return 1;
    
    return 0;
}

void DFS(int x, int y)
{
    housecomplex[cnt]++;
 	int nextX,nextY;
    for(int i=0; i<4; i++)
	{
		nextX = x + vectX[i];
        nextY = y + vectY[i];
 
        if(x>=0 && x<length && y>=0 && y<length)
			if(visited[nextX][nextY]==0 && graph[nextX][nextY]==1)
			{
				visited[nextX][nextY]=1;
				DFS(nextX, nextY);
			}
    }
}

void solution()
{
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(visited[i][j]==0 && graph[i][j]==1)
			{
				visited[i][j]=1;
				DFS(i, j);
				cnt++;
			}
		}
	}
}

int main(void)
{
	scanf("%d",&length);
	for(int i=0;i<length;i++)
		for(int j=0;j<length;j++)
			scanf("%1d",&graph[i][j]); //그래프 입력받기

	solution();
	printf("%d\n",cnt);
	qsort(housecomplex,cnt, sizeof(int),compare);
	for(int i=0;i<cnt;i++)
		printf("%d\n",housecomplex[i]);
	return 0;
}