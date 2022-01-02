#include <stdio.h>
#include <stdlib.h>
/* 
int main(void)
{
    int i, num1, num2, n1, n2; 
    scanf("%d %d", &num1, &num2);
    n1 = (num1 / 100) + (num1 / 10 % 10 * 10) + (num1 % 10 * 100);
    n2 = (num2 / 100) + (num2 / 10 % 10 * 10) + (num2 % 10 * 100);
    if(n1 > n2)
        printf("%d", n1);
    else
        printf("%d", n2);
    return 0;
}
*/

char swap(char *word1, char *word2);
void print(char *drow);
int main(void)
{
	char word1[3], word2[3],drow1[3],drow2[3];
	scanf("%s %s",word1, word2);
	
	swap(word1,drow1);
	swap(word2,drow2);
	
	if(drow1[0]>drow2[0])
	{
		print(drow1);
		exit(0);
	}
	
	else if(drow1[0]<drow2[0])
	{
		print(drow2);
		exit(0);
	}
	
	else if(drow1[0]==drow2[0])
	{
		if(drow1[1]>drow2[1])
		{
			print(drow1);
			exit(0);
		}
		else if(drow1[1]<drow2[1])
		{
			print(drow2);
			exit(0);
		}
		else if(drow1[1]=drow2[1])
		{
			if(drow1[2]>drow2[2])
			{
				print(drow1);
				exit(0);
			}
			else if(drow1[2]<drow2[2])
			{
				print(drow2);
				exit(0);
			}
		}
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

void print(char *drow)
{
	for(int j=0; j<3; j++){
		printf("%c",drow[j]);
	}
	printf("\n");
}