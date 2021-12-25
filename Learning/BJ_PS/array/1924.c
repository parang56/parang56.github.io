#include <stdio.h>
int main(void)
{
	int months[12] = {31, 28, 31, 30, 31, 30, 31, 31 ,30, 31 ,30, 31};
	int x,y,total,final;
	const char *days[7] ={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	scanf("%d %d", &x, &y);
	for(int i=0;i<x-1; i++)
	{
		total += months[i];
	}
	total += y;
	final = total%7;
	printf("%s\n",days[final]);
	
	return 0;
}