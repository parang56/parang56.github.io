//최대한 적은 봉지를 가져가야하므로 일단 5의 배수인지 확인
//5의 배수가 맞다면 나눈 몫이 답: cnt이 답
//5의 배수로 나누어지지 않다면 N에서 3을 뺴고 5의 배수인지 확인: 3kg 한 봉지 뺐으므로 cnt++
//N<0되면 -1출력, N=0이면 답 출력

#include <stdio.h>

int main(void)
{
	int N, cnt=0;
	scanf("%d",&N);
	while(1)
	{
		//5의 배수인지 확인
		if(N%5==0)
		{
			cnt+=N/5;
			break;
		}
		//5의 배수가 아니라면
		N-=3;
		cnt++;
		if(N<=0)
			break;
	}
	if(N<0)
		printf("-1\n");
	else
		printf("%d\n",cnt);
	return 0;
}