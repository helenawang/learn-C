#include <stdio.h>
#define MAXLINE 1000 /*maximum input line size*/

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

//print longest input line
int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while((len = getlinee(line, MAXLINE)) > 0){
		printf("%d, %s", len, line);
		if(len > max){ //更新最大值
			max = len;
			copy(longest, line);
		}
	}
	if(max > 0)
		printf("%s",longest);
	return 0;
}

/*getlinee: read a line(terminated by '\n') from stdin into s, return length*/
int getlinee(char s[], int lim){
	int c, i, j;
	j = 0; //循环退出条件必须有EOF以判输入结束！
	for(i=0; (c=getchar())!=EOF && !='\n'; i++){//Ctrl+D表示EOF
		if(i < lim-2){
			s[j] = c;
			j++;
		} 	
	}//j指向lim范围内的最后一个字符

	if(c=='\n'){ //长度小于lim,正常结束,末尾补\n
		s[i] = c;
		i++; j++;
	}//最末字符不是\n就结束了，说明长度超过lim，最后不补\n，直接补\0
	s[j] = '\0';
	return i; //实际长度（不管是否超过lim）
}

/*copy: copy 'from' into 'to'; assume 'to' is big enough*/
void copy(char to[], char from[]){
	int i = 0;
	while((to[i]=from[i])!='\0') i++;
}
