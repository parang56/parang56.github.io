#include <stdio.h>
#include <stdlib.h>
char swap(char *word1, char *word2);

int main(void)
{
	char word1[3], word2[3],drow1[3],drow2[3];
	scanf("%s %s",word1, word2);
	
	swap(word1,drow1);
	swap(word2,drow2);
	
	int num1,num2;
	num1 = atoi(drow1);
	num2 = atoi(drow2);
	
	if(num1>num2){
		printf("%d\n",num1);
	}
	else{
		printf("%d\n",num2);
	}
	return 0;
}

char swap(char *word,char *drow)
{
	int j=2;
	for(int i=0; i<3; i++)
	{
		drow[i] = word[j];
		j--;
	}
}

//뭐가 문제인지 모르겠는데 안됨;
