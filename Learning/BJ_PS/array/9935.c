#include <stdio.h>
#include <string.h>
int arr_len, bomb_len, pos;
char arr[1000005], bomb[40], ans[1000005];
 
int check(int location) 
{
    for (int i=0; i<bomb_len; i++) 
        if (ans[i+location] != bomb[i]) 
            return 0;
    return 1;
}

int main(void) 
{
    scanf("%s %s", arr, bomb);
    arr_len = strlen(arr);
    bomb_len = strlen(bomb);
	
    for(int i=0; i<arr_len; i++)
	{
        ans[pos++] = arr[i];
        if(pos - bomb_len >= 0 && check(pos - bomb_len))
            pos -= bomb_len;
		if(i==arr_len-1)
			ans[pos] = 0;
    }

	if(pos>0)
		printf("%s\n",ans);
	else
		printf("FRULA\n");
	
	return 0;
}