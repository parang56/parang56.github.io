#include <stdio.h>
#include <string.h>
int main(void)
{
	char word[100];
	
	int alphabet[26],i,j;
	
	for(int i=0;i<26;i++)
	{
		alphabet[i] = -1;
	}
	
	scanf("%s",word);
	
	for(i='a'; i<='z'; i++)
	{
		for(j=0; j<strlen(word); j++)
		{
			if(word[j]==i)
			{
				alphabet[word[j]-'a'] = j;
				break;
			}
		}
	}
	
	for(int i=0; i<26; i++){
		printf("%d",alphabet[i]);
		if(i<25)
			printf(" ");
	}
	
	return 0;
}