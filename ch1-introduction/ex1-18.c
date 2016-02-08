#include <stdio.h>
#define MAXLINE 1000 /*maximum input line size*/

int mygetline(char s[], int limit);
int myremove(char s[]);

/*myremove trailing blanks and tabs, and delete blank lines*/
int main()
{
	char line[MAXLINE];
	while(mygetline(line, MAXLINE)>0){
		if(myremove(line)>0)
			printf("%s",line);
	}
	return 0;
}

/*myremove trailing blanks and tabs from s(terminated by '\n')*/
int myremove(char s[]){
	int i = 0;
	while(s[i]!='\n') i++;
	i--; //find the last character before '\n'
	while(i>=0 && (s[i]==' ' || s[i]=='\t'))
		i--; //find the last non-blank character
	if(i>=0){
		s[++i] = '\n'; //末尾补\n,\0
		s[++i] = '\0';
	}
	return i; //返回实际长度（包括\n但不包括\0）
}

/*read a line into s(at most lim chars saved), return length*/
int mygetline(char s[], int lim){
	int c, i, j;
	j = 0;
	for(i=0; (c=getchar())!=EOF && c!='\n'; i++){
		if(i<lim-2) s[j++] = c;
	}
	if(c=='\n'){s[j++]=c; i++;}
	s[j] = '\0';
	return i;
}
