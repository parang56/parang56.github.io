#include <stdio.h>
#include <string.h>
#define MAX 1000000
int main()
{
    char array[MAX];
    int i,count=0,len;
    scanf("%[^\n]",array);
    len = strlen(array);
    
    if(len==1){
        if(array[i]== ' '){
            printf("0\n");
            return 0;
        }
    }
    
    else{
        for(i=1; i<len-1;i++)
        {
            if(array[i]==' '){
                count++;
            }
        }
    }
    
    printf("%d\n",count+1);
    
    return 0;
}