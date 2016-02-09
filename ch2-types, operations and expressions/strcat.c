#include <stdio.h>

/*cat: concatenate t to the end of s; s must be big enough*/
void cat(char s[], char t[]){
	int i, j;
	i=j=0;
	while(s[i]!='\0') i++; //i reach the end of s, aka '\0'
	while((s[i++]=t[j++])!='\0') //copy till reach '\0' of t
		;
}

int main()
{
	char s[10]="abc";
	char t[5]="def";
	cat(s,t);
	printf("%s\n",s);
	return 0;
}
