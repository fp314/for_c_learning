#include<ctype.h>
#include<stdio.h>

double atof(char s[]){
	double val, power, powere;
	int i, sign, e, signe;
	
	for( i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10 * val + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	//扩充增加对e-6形似的支持
	if(s[i] == 'e')
		i++;
	signe = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;
	for(e = 0; isdigit(s[i]); i++){
		e = 10 * e + (s[i] - '0');
	}
	powere = 1.0;
	while(e-- > 0){
		powere *= 10.0;
	}	
	if(signe == 1)
		val *= powere;
	else
		val /= powere;
	return val;
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

main(){
	int c;
	char line[100];
	while((c = getLine(line, 100)) != 0){
		printf(" string to double : %f \n", atof(line));
	}
}