//스택 문제로 분류되어있지만 스택이 아닌 배열로 푼 풀이

#include <stdio.h>
#include <string.h>

int main(void)
{
	int T;
	scanf("%d",&T);
	char arr[50];
	for(int i=0;i<T;i++)
	{
		int left=0, right=0;
		scanf("%s",arr);
		int len=strlen(arr);
		for(int j=0;j<len;j++)
		{
			if(arr[j]=='(')
				left++;
			if(arr[j]==')')
				right++;
			if(right>left) //여기서 제출에 틀렸다. 문제를 똑바로 읽지 않아서 '('와')'의 수만 같아도 되는 줄 알고 이 조건을 안 넣었었다. 
			{
				printf("NO\n");
				break;
			}
		}
		if(right==left)
			printf("YES\n");
		else if(left>right)
			printf("NO\n");
	}
	return 0;
}