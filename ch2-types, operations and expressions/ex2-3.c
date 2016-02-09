#include <stdio.h>
#define YES 1
#define NO 0

/*htoi: convert hexadecimal string s to integer*/
int htoi(char s[]){
	int hexdigit, i, inhex, n;

	i=0;
	if(s[i]=='0'){
		i++;
		if(s[i]=='x' || s[i]=='X') i++; //skip optional 0x or 0X
	}
	n=0; //integer value to be returned
	inhex = YES; //assume valid first
	for(; inhex==YES; i++){
		if(s[i]>='0' && s[i]<='9')
			hexdigit = s[i]-'0';
		else if(s[i]>='a' && s[i]<='f')
			hexdigit = s[i]-'a'+10;
		else if(s[i]>='A' && s[i]<='F')
			hexdigit = s[i]-'A'+10;
		else inhex=NO;
		if(inhex==YES) n = 16*n + hexdigit;
	}
	return n;
}

int main(int argc, char* argv[])
{
	char s[10];
	scanf("%s",s);//以字符串的形式读入
	printf("%d\n",htoi(s));
	return 0;
}
