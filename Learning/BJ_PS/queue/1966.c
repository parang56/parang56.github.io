#include <stdio.h>

int main(void)
{
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		int cnt=1,filenum, selprint,sum=0,temp;
		scanf("%d %d",&filenum, &selprint);
		int arr[filenum];
		for(int i=0;i<filenum;i++)
			scanf("%d",&arr[i]);
		temp=arr[selprint+1];
		while(1)
		{
			for(int k=1;k<filenum;k++)
			{
				if(arr[0]<arr[k])
					sum+=1;
			}
			if(sum==0)
				break;
			int tmp=arr[0];
			for(int j=filenum;j>0;j--)
				arr[j-1]=arr[j];
			arr[filenum]=tmp;
			break;
		}	
		if(arr[0]==temp)
		{
			printf("%d\n",cnt);
			break;
		}

		for(int i=filenum;i>0;i--)
			arr[i-1]=arr[i];
		arr[filenum--];
		cnt++;	
	}
	return 0;
}