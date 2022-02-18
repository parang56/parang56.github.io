#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1,y1,r1,x2,y2,r2,T;
	double dist, raddiff; //점 사이의 거리, 반지름 차이
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		dist = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		raddiff = fabs(r1-r2);
		
		if(dist==0 && raddiff==0) //무한대
			printf("-1\n");
		else if(dist<r1+r2 && raddiff<dist) //두 점 겹침
			printf("2\n");
		else if(dist==r1+r2 || dist==raddiff) //외부, 내부 점 일치 한개
			printf("1\n");
		else
			printf("0\n"); //겹침 X
	}
	return 0;
}