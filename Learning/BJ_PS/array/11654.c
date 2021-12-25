/*#include <stdio.h>

int main(){
	
	char c;
	scanf("%c",&c);
	printf("%d\n",c);
	
	return 0;
}*/

#include <stdio.h>
#include <time.h>
long totalElapsedTime = 0; //총 경과 시간
long start = 0; //게임 시작 시간
start = clock();

int main( void)
{
	getchar();
	totalElapsedTime = (clock() - start) / CLOCKS_PER_SEC;
	printf("%ld\n", totalElapsedTime);
    return 0;
}