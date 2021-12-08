#include <stdio.h>
#include <string.h>

int main(void)
{
	int T,R;
	char C[20];
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		scanf("%d %s", &R, C);
		for(int j=0; j<strlen(C); j++){
			for(int k=0; k<R; k++){
				printf("%C",C[j]);
			}
		}
		printf("\n");
	}
	return 0;
}