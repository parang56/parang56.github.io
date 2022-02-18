#include <stdio.h>
 
int graph[50][50];
int vectY[4] = {-1,0,1,0};
int vectX[4] = {0,1,0,-1};

int main(void)
{
    int N, M, r, c, d, ans=0; 
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &graph[i][j]);

    while(1) 
	{
		//1번 조건
        if(graph[r][c] == 0) 
		{
            ans++;
            graph[r][c] = -1; //청소해서 -1로 표시
        }
		
        int check=0, end=0;
		int nextY, nextX, backY, backX, leftY, leftX;
		int vect_Back=0, vect_Left=0;
		
		//check=1이면 2-d번인지 확인, 2-d 아니면 2-c번
        for (int i=0; i<4; i++)
		{
			nextY = r + vectY[i];
			nextX = c + vectX[i];
			if (0<=nextY && nextY<N && 0<=nextX && nextX<M)
                if (graph[nextY][nextX] == 0) 
					check = 1;
		}
 		
		if(!check)
		{
			//현 방향에 따른 뒤 방향 구하기
			int vect_Back = 0;
			if(d<2) 
				vect_Back = d+2;
			else 
				vect_Back = d-2;

			//(backY,backX) -> 뒤 칸
			backY = r + vectY[vect_Back];
			backX = c + vectX[vect_Back];

			//2-d번
			if(graph[backY][backX] == 1)
			{
				end=1;
				break;
			}

			//2-c번
			else 
			{
				r = backY;
				c = backX;
			}	
		}
		
		else
		{
			//현 방향에 따른 왼 방향 구하기
			int vect_Left = 0;
			if(d>0) 
				vect_Left = d - 1;
			else 
				vect_Left = 3;

			//(leftY, leftX) -> 왼쪽 칸
			leftY = r + vectY[vect_Left];
			leftX = c + vectX[vect_Left];

			//2-a번
			if ((0<=leftY && leftY<N && 0<=leftX && leftX<M) && graph[leftY][leftX]==0) 
			{
				r = leftY;
				c = leftX;
				d = vect_Left;
			}
			//2-b번
			else 
				d = vect_Left;
		}
		
		if(end)
			break;
    }
	
    printf("%d\n", ans);
	
    return 0;
}