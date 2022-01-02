#include <stdio.h>

int hansoo(int n);

int main()
{
	int N, count, add;
	
	scanf("%d",&N);
	if(1<=N && N<=99){
		count = N;
	}
	if(100<=N && N<=1000){
		add = hansoo(N);
		count = 99 + add;
	}
	printf("%d\n",count);
	return 0;
}

int hansoo(int n){
	int count;
	for(int i=100; i<=n; i++){
		int a = i/100;
		int b = (i-a*100)/10;
		int c = (i-a*100-b*10)%10;
		if(b-a==c-b){
			count++;
		}
	}
	return count;
}