#include <stdio.h>
#include <stdlib.h>
#define MAX 26

int graph[MAX][MAX];
// 단지를 저장할 배열 = 나올 수 있는 단지의 최대 개수 = n * (n/2) + 1
int housecomplex[MAX*(MAX/2)+1];

int vectX[4] = {0,0,1,-1};
int vectY[4] = {1,-1,0,0};
 
int cnt; //단지의 개수
int length; //한 변의 길이
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2) 
        return -1;
    
    if(num1 > num2) 
        return 1;
    
    return 0;
}

void DFS(int x, int y, int key)
{
    graph[x][y] = key;
 	int nextX,nextY;
    for(int i=0; i<4; i++)
	{
		nextX = x + vectX[i];
        nextY = y + vectY[i];
 
        if(x>=0 && x<length && y>=0 && y<length && graph[nextX][nextY]==1)
            DFS(nextX, nextY, key);
    }
}

void solution()
{
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(graph[i][j]==1)
			{
				cnt++;
				DFS(i, j, cnt+1);
			}
		}
	}
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length;j++)
		{
			if(graph[i][j]>1)
				housecomplex[graph[i][j]-2]++;
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