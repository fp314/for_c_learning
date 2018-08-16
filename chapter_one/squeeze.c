#include<stdio.h>

//去除字符串中所有c字符
int squeeze(char s[], int c){
	int i, j;
	for(i = j = 0; s[i] != '\0'; i++)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	return j;
}

int  sgetline(char s[], int MAX){
	int c = 0, i = 0;
	while((c = getchar())!= EOF && i < MAX-1 && c != '\n'){
		s[i++] = c;
	}
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

main(){
	//printf("test << and >> 13>>2 : %d", 13>>2);
	//return;
	int MAX = 10; 
	char s[MAX];
	int a;
	while((a = sgetline(s, MAX)) != 0){
		printf("len : %d / line : %s \n", a, s);
		int b = squeeze(s,'c');
		printf("after squeeze\(s,\'c\'\) string len : %d / line : %s \n", b, s);
	}
}
 
