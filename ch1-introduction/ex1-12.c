#include <stdio.h>
#define IN 1
#define OUT 0
/*print input one word per line*/
int main()
{
	int c, state;
	state = OUT;
	while((c=getchar())!=EOF){
		if(c==' ' || c=='\t' || c=='\n'){
			if(state == IN){ //finish the word
				putchar('\n');
				state = OUT;
			}
		}else if(state == OUT){ //beginnning of word
			state = IN;
			putchar(c);
		}else
			putchar(c); //inside a word
	}
	return 0;
}
