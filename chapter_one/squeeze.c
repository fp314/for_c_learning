#include<stdio.h>

//去除字符串中所有c字符
void squeeze(char s[], int c){
	int i, j;
	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

int  getline(char [] s, const int MAX){
	int c;
	int i = 0;
	while( (c = getchar())!= EOF && i < MAX-1 && C != '\n'){
		s[i++] = c;
	}
	if(c = '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}
main(){
	const int MAX = 10; 
	char s[MAX];
	int nl;
	while(getline(s, MAX)){
		printf("line : %s", s);
	}
}
 
