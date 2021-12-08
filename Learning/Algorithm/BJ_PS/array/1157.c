#include <stdio.h>
#include <string.h>
#define BIG 1000001

int main(void){
	int i,j,max=0, max_num, len;
	char word[BIG];
	int cnt[26] = {0,};
	
	scanf("%s",word);
	len = strlen(word);
	
	for(int i=0; i<len; i++){
		if(word[i]<97){
			word[i] += 32;
		}
		cnt[word[i] - 97]++;
	}
	
	for(int i=0; i<26; i++){
		if(max<cnt[i]){
			max=cnt[i];
			max_num = i;
		}
		else if(max==cnt[i]){
			max_num = -1;
		}
	}
	
	if(max_num != -1){
		printf("%c\n", max_num+65);
	}
	else{
		printf("?\n");
	}
	
	return 0;
}