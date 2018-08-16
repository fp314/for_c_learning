#include<stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxLen);
int strIndex(char line[], char searchof[]);

char pattern[] = "abcd";

main(){
	char line[MAXLINE];
	int index;
	
	while(getLine(line, MAXLINE) != 0){
		printf("fortest line is : %s \n",line);
		index = strIndex(line, pattern);
		printf("the index is : %d \n", index);
		if(index != -1)
			printf("match succese : %s \n", line);
		else
			printf("match fail!!! \n");
	}
}

int getLine(char line[], int maxLen){
	int c , i = 0;
	while(--maxLen > 0 && (c = getchar()) != EOF && c != '\n'){
		line[i++] = c;
	}
	if(c == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return i;
}

//返回pattern 在line字符串最右边的位置
int strIndex(char line[], char searchof[]){
	int i, j, k, result = -1;
	for(i = 0; line[i] != '\0'; i++){
		for(j = i, k = 0; searchof[k] != '\0' && line[j] == searchof[k]; j++, k++)
			;
		if(k > 0 && searchof[k] == '\0')
			result = i;
	}
	return result;
}