#include <stdio.h>
#include <ctype.h>
/* atoi: convert s to integer */
int atoi(char s[])
{
    int i, n, sign;
    
    for(i = 0; isspace(s[i]); i++)
	;/* skip the white space */
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') i++; /* skip the sign */
    for(n = 0; isdigit(s[i]); i++)
	n = n*10 + s[i] - '0';

    return sign * n;
}
int main(int argc, char* argv[])
{
    int i;
    for(i=1;i<argc;i++)
    {
	printf("%d\n", atoi(argv[i]));
    }
    return 0;
}
