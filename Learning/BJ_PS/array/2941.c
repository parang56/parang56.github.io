#include <stdio.h> 
#include <string.h> 

int main(void) 
{ 
	char arr[100];
	scanf("%s", arr);
	int sum = strlen(arr); 
	
	for(int i=0; i<strlen(arr); i++) 
	{ 
		if((arr[i] == 'l' || arr[i] == 'n') && arr[i+1] == 'j') sum--; 
		else if(arr[i] == '=' || arr[i] == '-') sum--; 
		else if(arr[i] == 'd' && arr[i+1] == 'z' && arr[i+2] == '=') sum--; 
	}

	printf("%d\n", sum); 
	
	return 0;
}