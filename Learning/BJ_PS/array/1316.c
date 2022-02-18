#include <stdio.h>
#include <string.h>

int N, len, res;
char arr[100] = {0,};

int main(void)
{
	scanf("%d",&N);
	while(N--)
	{
		int alphabet[26] = {0,};
		int check=1;
		char temp='0';
		scanf("%s",arr);
		len = strlen(arr);
		for(int i=0; i<len; i++)
		{
			if(temp!=arr[i])
			{
				temp=arr[i];
				alphabet[arr[i]-'a']++;
			}
			if(alphabet[arr[i]-'a']>1) 
			{
				check=0;
				break;
			}
		}
		if(check)
			res++;
	}
	
	printf("%d\n",res);
	
	return 0;
}