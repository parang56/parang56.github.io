#include <stdio.h>

int main(){
	int N, K, j=0;
	int arr[5000];

	scanf("%d",&N);
    scanf("%d",&K);

	for(int i=0; i<N; i++)
		arr[i]=i+1;

	printf("<");

	do{
		j=(j+K-1)%N;
		printf("%d",arr[j]);
		for(int i=j; i<N-1; i++)
			arr[i]=arr[i+1];
		if(N==1)
		{
			printf(">\n");
			break;
		}
		else
			printf(", ");
	}while(N--);
	return 0;
}