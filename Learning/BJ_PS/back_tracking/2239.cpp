#include <iostream>
#include <string>
#define MAX 9
using namespace std;

string sudoku[MAX];
int row[MAX][MAX]; //열, 1 ~ 9
int col[MAX][MAX]; //행, 1 ~ 9
int square[MAX][MAX]; //3 * 3 박스 idx, 1 ~ 9

int make3by3(int y, int x)
{
	return (y/3)*3 + x/3;
}

void Back_Tracking(int cnt)
{
	if(cnt==81)
	{
		for(int i=0; i<MAX; i++)
		{
			for (int j=0; j<MAX; j++)
				cout << sudoku[i][j];
			cout << "\n";
		}
		exit(0); //사전식으로 앞서는 답 출력
	}

	int y = cnt / 9;
	int x = cnt % 9;

	//칸이 채워져 있으면 넘어감
	if (sudoku[y][x] != '0')
		Back_Tracking(cnt+1);
	
	//칸이 안 채워져 있고
	else
	{
		for (int k=1; k<=MAX; k++)
		{
			//가로줄에 없고 세로줄에 없고 정사각형 안에 없어야 함.
			if (!col[x][k] && !row[y][k] && !square[make3by3(y,x)][k])
			{
				sudoku[y][x] = k + '0'; //필요한 숫자 채워 넣음
				col[x][k] = row[y][k] = square[make3by3(y,x)][k] = 1; //있다고 표시
				Back_Tracking(cnt + 1);
				sudoku[y][x] = '0'; //리셋
				col[x][k] = row[y][k] = square[make3by3(y,x)][k] = 0; //리셋
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < MAX; i++)
	{
		cin >> sudoku[i];
		for (int j = 0; j < MAX; j++)
		{
			if (sudoku[i][j] != '0')
			{
				int num = sudoku[i][j] - '0';
				col[j][num] = row[i][num] = square[make3by3(i,j)][num] = 1;
			}
		}
	}

	Back_Tracking(0);

	return 0;
}